#include "stdafx.h"
#include "Rocket.h"

#include "IEnginePrototype.h"


void Rocket::thrust()
{
  if (d_fuelTank.isEmpty())
    return;

  const auto thrustPower = d_engine.getPrototype().getPower();

  const double y = std::cos(getRotation());
  const double x = std::sin(getRotation());
  const Force thrust = Sdk::Vector2D{ x, y } * thrustPower;

  addActiveForce(thrust);

  d_moving = true;
}

void Rocket::turnLeft()
{
  if (d_fuelTank.isEmpty())
    return;
  setRotationSpeed(-5);
  d_moving = true;
}

void Rocket::turnRight()
{
  if (d_fuelTank.isEmpty())
    return;
  setRotationSpeed(5);
  d_moving = true;
}


void Rocket::fire()
{
}

void Rocket::changeWeapon()
{
}


void Rocket::refill()
{
  d_fuelTank.fill();
}
