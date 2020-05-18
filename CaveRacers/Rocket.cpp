#include "stdafx.h"
#include "Rocket.h"

#include "IEnginePrototype.h"
#include "IFuelTankPrototype.h"
#include "IHullPrototype.h"


Rocket::Rocket(ILevelModel& i_levelModel, FuelTank i_fuelTank, Engine i_engine, Hull i_hull)
  : Object(i_levelModel)
  , d_fuelTank(std::move(i_fuelTank))
  , d_engine(std::move(i_engine))
  , d_hull(std::move(i_hull))
{
}


double Rocket::getMass() const
{
  return d_fuelTank.getMass() + d_engine.getMass() + d_hull.getMass();
}


void Rocket::update(double i_dt)
{
  auto noThrust = [&]() { d_thrust = Physics_NS::Force::zero(); };
  auto noRotation = [&]() { setRotationSpeed(0); };

  if (!d_fuelTank.isEmpty())
  {
    bool isMoving = false;

    if (d_isThrustOn)
    {
      const auto thrustPower = d_engine.getPrototype().getPower();
      d_thrust = getDirection() * thrustPower;
      isMoving = true;
    }
    else
      noThrust();

    if (d_isRotateLeftOn)
    {
      setRotationSpeed(-5);
      isMoving = true;
    }
    else if (d_isRotateRightOn)
    {
      setRotationSpeed(5);
      isMoving = true;
    }
    else
      noRotation();

    if (isMoving)
      d_fuelTank.waste(d_engine.getPrototype().getConsumption() * i_dt);
  }
  else
    noThrust();
    
  if (d_landed)
    d_fuelTank.fill(i_dt * 10);
}


Physics_NS::Force Rocket::getActiveForcesSum() const
{
  return d_thrust;
}

void Rocket::updateCollisions(const std::vector<Physics_NS::CollisionInfo>& i_collisions)
{
  d_landed = std::any_of(i_collisions.cbegin(), i_collisions.cend(), [](const auto& i_collision) {
    if (const auto* object = dynamic_cast<const Object*>(&i_collision.object);
        object && object->getBehavior() == ObjectBehavior::LandingSite)
    {
      return true;
    }
    return false;
  });
}


double Rocket::getFuelPercentage() const
{
  return d_fuelTank.getFuel() / d_fuelTank.getPrototype().getMaxFuel();
}
