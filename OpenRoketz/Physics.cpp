#include "stdafx.h"
#include "Physics.h"

#include "Constants.h"


void Physics::update(double i_dt, std::vector<std::shared_ptr<IInertial>>& io_objects) const
{
  const auto staticForceSum = getStaticForcesSum();

  for (auto& object : io_objects)
  {
    CONTRACT_ASSERT(object);
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
  auto sumForce = i_staticForceSum;

  for (const auto& force : io_object.getActiveForces())
    sumForce += force;
  io_object.clearActiveForces();

  constexpr double MovementThreshold = 0.0001;

  auto acceleration = (sumForce.lengthSq() > MovementThreshold) ? sumForce / io_object.getMass() : Sdk::Vector2D{ 0, 0 };

  if (io_object.isGravityAffected())
    acceleration += { 0, -Constants::GravitationalAccelerationNibiru };

  if (acceleration.lengthSq() < MovementThreshold)
    return;

  auto speed = io_object.getSpeed() + acceleration * i_dt;
  const auto speedValue = speed.length();
  if (speedValue > 30)
    speed = speed * 30 / speedValue;
  io_object.setSpeed(speed);

  if (speed.lengthSq() < MovementThreshold)
    return;

  const auto position = io_object.getPosition() + speed * i_dt;
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
