#include "stdafx.h"
#include "Physics.h"

#include "Constants.h"
#include "GetCollision.h"


namespace
{
  constexpr double MovementThreshold = 0.01;

  Sdk::Vector2D getAcceleration(IInertial& io_object)
  {
    Force sumForce;
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
    if (speedValue > io_object.getMaxSpeed())
      speed = speed * io_object.getMaxSpeed() / speedValue;

    return speed;
  }

  Sdk::Vector2D getPosition(const IInertial& io_object, const Sdk::Vector2D& i_speed, double i_dt)
  {
    return io_object.getPosition() + i_speed * i_dt;
  }
}


void Physics::update(double i_dt, std::vector<std::shared_ptr<IInertial>>& io_objects) const
{
  for (auto& objectPtr : io_objects)
  {
    CONTRACT_ASSERT(objectPtr);
    auto& object = *objectPtr;

    object.clearCollisions();

    for (const auto& otherPtr : io_objects)
    {
      CONTRACT_ASSERT(otherPtr);
      auto& other = *otherPtr;

      if (&object == &other)
        continue;

      const auto collision = getCollision(object, other);
      if (!collision.isCollision)
        continue;

      object.addCollision(std::move(collision));
    }

    updateObject(i_dt, object);
  }
}

void Physics::updateObject(double i_dt, IInertial& io_object) const
{
  updateObjectLinear(i_dt, io_object);
  updateObjectRotation(i_dt, io_object);
}

void Physics::updateObjectLinear(double i_dt, IInertial& io_object) const
{
  auto acceleration = getAcceleration(io_object);
  if (acceleration.lengthSq() < MovementThreshold)
    acceleration = {};

  auto speed = getSpeed(io_object, acceleration, i_dt);

  // Remove collisions
  for (const auto& collision : io_object.getCollisions())
  {
    CONTRACT_ENSURE(collision.isCollision);

    if (!collision.receiver.isRigid() || !collision.sender.isRigid())
      continue;

    const auto& normalProjection = speed.dot(collision.normal);
    if (normalProjection > 0)
      speed = speed - collision.normal * normalProjection * 1.5;

    speed = speed * 0.9;
  }

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
