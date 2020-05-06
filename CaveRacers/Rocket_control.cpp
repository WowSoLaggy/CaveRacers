#include "stdafx.h"
#include "Rocket.h"

#include "CreateObjects.h"
#include "IEnginePrototype.h"
#include "ILevelModel.h"
#include "SceneObject.h"


namespace
{
  Sdk::Vector2D getDirection(double i_rotation)
  {
    return { std::sin(i_rotation), std::cos(i_rotation) };
  }
}


void Rocket::thrust()
{
  if (d_fuelTank.isEmpty())
    return;

  const auto thrustPower = d_engine.getPrototype().getPower();
  const Force thrust = getDirection(getRotation()) * thrustPower;

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


void Rocket::fire1()
{
  auto* level = getLevel();
  CONTRACT_ASSERT(level);

  auto projectile = createProjectile();
  CONTRACT_ASSERT(projectile);

  projectile->setGravityAffected(true);

  projectile->setBehavior(ObjectBehavior::Projectile);

  const auto shootDirection = getDirection(getRotation());
  const auto projectileSpeed = getSpeed() + shootDirection * 75;
  projectile->setSpeed(projectileSpeed);

  projectile->setPosition(getPosition() + shootDirection * 2.5);

  level->addObject(projectile);
}


void Rocket::refill()
{
  d_fuelTank.fill();
}
