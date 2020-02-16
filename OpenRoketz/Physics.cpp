#include "stdafx.h"
#include "Physics.h"

#include "Constants.h"
#include "GetCollision.h"


namespace
{
  constexpr double MovementThreshold = 0.0001;

  Sdk::Vector2D getAcceleration(IInertial& io_object, const Force& i_staticForceSum)
  {
    auto sumForce = i_staticForceSum;

    for (const auto& force : io_object.getActiveForces())
      sumForce += force;
    io_object.clearActiveForces();

    auto acceleration = (sumForce.lengthSq() > MovementThreshold) ? sumForce / io_object.getMass() : Sdk::Vector2D{ 0, 0 };

    if (io_object.isGravityAffected())
      acceleration += { 0, -Constants::GravitationalAccelerationNibiru };

    return acceleration;
  }

  Sdk::Vector2D getSpeed(const IInertial& io_object, const Sdk::Vector2D& i_acceleration, double i_dt)
  {
    auto speed = io_object.getSpeed() + i_acceleration * i_dt;

    const auto speedValue = speed.length();
    constexpr double MaxSpeed = 30;
    if (speedValue > MaxSpeed)
      speed = speed * MaxSpeed / speedValue;

    return speed;
  }

  Sdk::Vector2D getPosition(const IInertial& io_object, const Sdk::Vector2D& i_speed, double i_dt)
  {
    return io_object.getPosition() + i_speed * i_dt;
  }
}


void Physics::update(double i_dt, std::vector<std::shared_ptr<IInertial>>& io_objects) const
{
  const auto staticForceSum = getStaticForcesSum();

  for (auto& object : io_objects)
  {
    CONTRACT_ASSERT(object);

    const bool inCollision = std::any_of(io_objects.begin(), io_objects.end(),
                                         [&](const auto& i_other) {
      return object.get() == i_other.get() ? false : getCollision(*object, *i_other);
    });

    if (!inCollision)
      updateObject(i_dt, *object, staticForceSum);
  }
}

void Physics::updateObject(double i_dt, IInertial& io_object, const Force& i_staticForceSum) const
{
  updateObjectLinear(i_dt, io_object, i_staticForceSum);
  updateObjectRotation(i_dt, io_object);
}

void Physics::updateObjectLinear(double i_dt, IInertial& io_object, const Force& i_staticForceSum) const
{
  const auto acceleration = getAcceleration(io_object, i_staticForceSum);
  if (acceleration.lengthSq() < MovementThreshold)
    return;

  const auto speed = getSpeed(io_object, acceleration, i_dt);
  if (speed.lengthSq() < MovementThreshold)
  {
    io_object.setSpeed({ 0, 0 });
    return;
  }
  io_object.setSpeed(speed);

  const auto position = getPosition(io_object, speed, i_dt);
  io_object.setPosition(position);
}

void Physics::updateObjectRotation(double i_dt, IInertial& io_object) const
{
  constexpr double MovementThreshold = 0.0001;
  const auto rotationSpeed = io_object.getRotationSpeed();
  io_object.setRotationSpeed(0);
  if (std::abs(rotationSpeed) < MovementThreshold)
    return;

  io_object.setRotation(io_object.getRotation() + rotationSpeed * i_dt);
}


void Physics::addStaticForce(Force i_staticForce)
{
  d_staticForces.push_back(std::move(i_staticForce));
}

Force Physics::getStaticForcesSum() const
{
  Force sumForce;
  for (const auto& force : d_staticForces)
    sumForce += force;
  return sumForce;
}
