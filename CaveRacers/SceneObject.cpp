#include "stdafx.h"
#include "SceneObject.h"


SceneObject::SceneObject()
{
  constexpr double Size = 64.0 / 10;
  constexpr double HalfSize = Size / 2;

  d_rect = Sdk::RectD(-HalfSize, HalfSize, -HalfSize, HalfSize);
}


double SceneObject::getMaxSpeed() const
{
  return std::numeric_limits<double>::max();
}

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
  return d_speed;
}

void SceneObject::setSpeed(Sdk::Vector2D i_speed)
{
  d_speed = std::move(i_speed);
}


double SceneObject::getRotation() const
{
  return d_rotation;
}

void SceneObject::setRotation(double i_rotation)
{
  d_rotation = i_rotation;
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
  return d_gravityAffected;
}

void SceneObject::setGravityAffected(bool i_affected)
{
  d_gravityAffected = i_affected;
}


void SceneObject::setTextureName(std::string i_textureName)
{
  d_textureName = std::move(i_textureName);
}

const std::string& SceneObject::getTextureName() const
{
  return d_textureName;
}


ObjectBehavior SceneObject::getBehavior() const
{
  return d_behavior;
}

void SceneObject::setBehavior(ObjectBehavior i_behavior)
{
  d_behavior = i_behavior;
}


Sdk::RectD SceneObject::getRect() const
{
  return d_rect;
}

void SceneObject::setRect(Sdk::RectD i_rect)
{
  d_rect = std::move(i_rect);
}

bool SceneObject::isReceiveCollision() const
{
  return false;
}

bool SceneObject::isSendCollision() const
{
  return true;
}

bool SceneObject::isRigid() const
{
  return true;
}


void SceneObject::addCollidedObject(std::shared_ptr<IInertial> i_object)
{
  d_collidedObjects.push_back(std::move(i_object));
}

void SceneObject::clearCollidedObjects()
{
  d_collidedObjects.clear();
}
