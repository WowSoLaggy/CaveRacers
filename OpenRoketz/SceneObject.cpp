#include "stdafx.h"
#include "SceneObject.h"


double SceneObject::getMass() const
{
  return 0;
}

const Sdk::Vector2D& SceneObject::getPosition() const
{
  return d_position;
}

void SceneObject::setPosition(Sdk::Vector2D i_position)
{
  d_position = std::move(i_position);
}


const Sdk::Vector2D& SceneObject::getSpeed() const
{
  static const auto Empty = Sdk::Vector2D{};
  return Empty;
}

void SceneObject::setSpeed(Sdk::Vector2D i_speed)
{
  CONTRACT_ASSERT(false);
}


double SceneObject::getRotation() const
{
  return 0;
}

void SceneObject::setRotation(double i_rotation)
{
  CONTRACT_ASSERT(false);
}


double SceneObject::getRotationSpeed() const
{
  return 0;
}

void SceneObject::setRotationSpeed(double i_rotationSpeed)
{
}


void SceneObject::addActiveForce(Force i_force)
{
  CONTRACT_ASSERT(false);
}

const std::vector<Force>& SceneObject::getActiveForces() const
{
  static const auto Empty = std::vector<Force>();
  return Empty;
}

void SceneObject::clearActiveForces()
{
}


bool SceneObject::isGravityAffected() const
{
  return false;
}

void SceneObject::setGravityAffected(bool i_affected)
{
  CONTRACT_ASSERT(false);
}


void SceneObject::setTextureName(std::string i_textureName)
{
  d_textureName = std::move(i_textureName);
}

const std::string& SceneObject::getTextureName() const
{
  return d_textureName;
}
