#include "stdafx.h"
#include "Physics.h"

#include "CollisionInfo.h"
#include "Collisions.h"
#include "IInertial.h"
#include "Settings.h"


namespace Physics_NS
{
  namespace
  {
    double getSumElasticity(const IInertial& i_first, const IInertial& i_second)
    {
      const double retval = (i_first.getElasticity() + i_second.getElasticity()) / 2;
      return std::min(std::max(retval, 0.0), 1.0);
    }

  } // anonymous NS


  Settings& Physics::getSettings()
  {
    return d_settings;
  }

  const Settings& Physics::getSettings() const
  {
    return d_settings;
  }

  void Physics::update(
    const std::vector<std::shared_ptr<IInertial>>& io_objects,
    double i_dt) const
  {
    if (io_objects.empty())
      return;

    d_collisionsMap.clear();

    for (auto itFirst = io_objects.cbegin(); ; ++itFirst)
    {
      auto itSecond = std::next(itFirst);
      if (itSecond == io_objects.cend())
        break;

      const auto firstPtr = *itFirst;
      const auto& first = CONTRACT_DEREF(firstPtr);

      for (; itSecond != io_objects.cend(); ++itSecond)
      {
        const auto secondPtr = *itSecond;
        const auto& second = CONTRACT_DEREF(secondPtr);

        if (const auto normalOpt = getCollision(first, second))
        {
          const auto normal = *normalOpt;
          d_collisionsMap[&first].push_back({ second, normal });
          d_collisionsMap[&second].push_back({ first, -normal });
        }
      }
    }

    for (auto objectPtr : io_objects)
    {
      auto& object = CONTRACT_DEREF(objectPtr);
      if (object.isMovable())
        updateObject(object, i_dt);
    }
  }

  void Physics::updateObject(IInertial& io_object, double i_dt) const
  {
    updateLinear(io_object, i_dt);
    updateAngular(io_object, i_dt);
  }

  void Physics::updateLinear(IInertial& io_object, double i_dt) const
  {
    const auto accel = getAcceleration(io_object);

    const auto speed = getSpeed(io_object, accel, i_dt);
    io_object.setSpeed(speed);

    const auto position = io_object.getPosition() + speed * i_dt;
    io_object.setPosition(position);
  }

  void Physics::updateAngular(IInertial& io_object, double i_dt) const
  {
    if (!io_object.isRotateToSpeed())
    {
      const auto speed = io_object.getRotationSpeed();

      const auto rotation = io_object.getRotation() + speed * i_dt;
      io_object.setRotation(rotation);
    }
    else
      io_object.setRotation(io_object.getSpeedAngle());
  }


  Sdk::Vector2D Physics::getAcceleration(const IInertial& i_object) const
  {
    const auto activeForces = i_object.getActiveForcesSum();

    const double mass = i_object.getMass();
    CONTRACT_EXPECT(std::abs(mass) > 1e-6);

    auto accel = activeForces / mass;
    if (i_object.isGravityAffected())
      accel += { 0, -d_settings.getGravityAcceleration() };

    return accel;
  }

  Sdk::Vector2D Physics::getSpeed(const IInertial& i_object, const Sdk::Vector2D& i_accel, double i_dt) const
  {
    auto virtualSpeed = i_object.getSpeed() + i_accel * i_dt;

    const auto collisionsIt = d_collisionsMap.find(&i_object);
    if (collisionsIt == d_collisionsMap.cend())
      return virtualSpeed;

    const auto& collisions = collisionsIt->second;
    for (const auto& collision : collisions)
    {
      const auto& other = collision.object;
      const auto& normal = collision.normal;

      const double elasticity = getSumElasticity(i_object, other);

      const auto& normalProj = virtualSpeed.dot(normal);
      if (normalProj > 0)
        virtualSpeed = virtualSpeed - normal * normalProj * 1.5;
    }

    return virtualSpeed;
  }

} // Physics_NS
