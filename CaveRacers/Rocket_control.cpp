#include "stdafx.h"
#include "Rocket.h"

#include "CreateObjects.h"
#include "IEnginePrototype.h"
#include "ILevelModel.h"
#include "Object.h"


void Rocket::thrust(bool i_on)
{
  d_isThrustOn = i_on;
}

void Rocket::turnLeft(bool i_on)
{
  d_isRotateLeftOn = i_on;
}

void Rocket::turnRight(bool i_on)
{
  d_isRotateRightOn = i_on;
}


void Rocket::fire1()
{
  auto projectile = createProjectile(getLevel());
  CONTRACT_ASSERT(projectile);

  const auto shootDirection = getDirection();
  const auto projectileSpeed = getSpeed() + shootDirection * 75;
  projectile->setSpeed(projectileSpeed);

  projectile->setPosition(getPosition() + shootDirection * 2.5);
}


void Rocket::refill()
{
  d_fuelTank.fill();
}
