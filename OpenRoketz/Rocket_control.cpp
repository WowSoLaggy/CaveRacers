#include "stdafx.h"
#include "Rocket.h"

#include "IEnginePrototype.h"


void Rocket::thrust()
{
  const auto thrustPower = d_engine.getPrototype().getPower();

  const double y = std::cos(getRotation());
  const double x = std::sin(getRotation());
  const Force thrust = Sdk::Vector2D{ x, y } * thrustPower;

  addActiveForce(thrust);
}

void Rocket::turnLeft()
{
  setRotationSpeed(-5);
}

void Rocket::turnRight()
{
  setRotationSpeed(5);
}


void Rocket::fire()
{
}

void Rocket::changeWeapon()
{
}