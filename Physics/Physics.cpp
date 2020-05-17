#include "stdafx.h"
#include "Physics.h"

#include "CollisionInfo.h"
#include "Collisions.h"
#include "IInertial.h"
#include "Settings.h"


namespace Physics_NS
{
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

    std::vector<CollisionInfo> collisions;

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

        if (const auto collisionOpt = getCollision(first, second))
          collisions.push_back(std::move(*collisionOpt));
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

    const auto speed = io_object.getSpeed() + accel * i_dt;
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

  Sdk::Vector2D Physics::getAcceleration(IInertial& i_object) const
  {
    const auto activeForces = i_object.getActiveForcesSum();

    const double mass = i_object.getMass();
    CONTRACT_EXPECT(std::abs(mass) > 1e-6);

    auto accel = activeForces / mass;
    if (i_object.isGravityAffected())
      accel += { 0, -d_settings.getGravityAcceleration() };

    return accel;
  }

} // Physics_NS
