#include "stdafx.h"
#include "Rocket.h"

#include "IEnginePrototype.h"
#include "IFuelTankPrototype.h"
#include "IHullPrototype.h"


Rocket::Rocket(FuelTank i_fuelTank, Engine i_engine, Hull i_hull)
  : d_fuelTank(std::move(i_fuelTank))
  , d_engine(std::move(i_engine))
  , d_hull(std::move(i_hull))
{
}


double Rocket::getMass() const
{
  return d_fuelTank.getMass() + d_engine.getMass() + d_hull.getMass();
}


const Sdk::Vector2D& Rocket::getPosition() const
{
  return d_position;
}

void Rocket::setPosition(Sdk::Vector2D i_position)
{
  d_position = std::move(i_position);
}


const Sdk::Vector2D& Rocket::getSpeed() const
{
  return d_speed;
}

void Rocket::setSpeed(Sdk::Vector2D i_speed)
{
  d_speed = std::move(i_speed);
}


void Rocket::addActiveForce(Force i_force)
{
  d_activeForces.push_back(std::move(i_force));
}

const std::vector<Force>& Rocket::getActiveForces() const
{
  return d_activeForces;
}

void Rocket::clearActiveForces()
{
  d_activeForces.clear();
  d_moving = false;
}


bool Rocket::isGravityAffected() const
{
  return d_gravityAffected;
}

void Rocket::setGravityAffected(bool i_affected)
{
  d_gravityAffected = i_affected;
}


const std::string& Rocket::getTextureName() const
{
  return d_textureName;
}

void Rocket::setTextureName(std::string i_textureName)
{
  d_textureName = std::move(i_textureName);
}


void Rocket::update(double i_dt)
{
  if (d_moving)
    d_fuelTank.waste(d_engine.getPrototype().getConsumption() * i_dt);

  const bool landed = std::any_of(d_collidedObjects.cbegin(), d_collidedObjects.cend(), [](const auto& i_object) {
    if (const auto* sceneObject = dynamic_cast<const ISceneObject*>(i_object.get()))
      return sceneObject->getBehavior() == ObjectBehavior::LandingSite;
    return false;
  });
  if (landed)
    d_fuelTank.fill(i_dt * 10);
}


ObjectBehavior Rocket::getBehavior() const
{
  return ObjectBehavior::Default;
}


double Rocket::getRotation() const
{
  return d_rotation;
}

void Rocket::setRotation(double i_rotation)
{
  d_rotation = i_rotation;
}

double Rocket::getRotationSpeed() const
{
  return d_rotationSpeed;
}

void Rocket::setRotationSpeed(double i_rotationSpeed)
{
  d_rotationSpeed = i_rotationSpeed;
}


Sdk::RectD Rocket::getRect() const
{
  constexpr double Size = 32.0 / 10;
  constexpr double HalfSize = Size / 2;

  const double left = getPosition().x - HalfSize;
  const double top = getPosition().y - HalfSize;

  return Sdk::RectD(left, left + Size, top, top + Size);
}

bool Rocket::isCollidable() const
{
  return d_collidable;
}

void Rocket::setCollidable(bool i_collidable)
{
  d_collidable = i_collidable;
}

bool Rocket::isRigid() const
{
  return d_rigid;
}

void Rocket::setRigid(bool i_rigid)
{
  d_rigid = i_rigid;
}


void Rocket::addCollidedObject(std::shared_ptr<IInertial> i_object)
{
  d_collidedObjects.push_back(std::move(i_object));
}

void Rocket::clearCollidedObjects()
{
  d_collidedObjects.clear();
}


double Rocket::getFuelPercentage() const
{
  return d_fuelTank.getFuel() / d_fuelTank.getPrototype().getMaxFuel();
}
