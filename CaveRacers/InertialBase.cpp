#include "stdafx.h"
#include "InertialBase.h"


bool InertialBase::isGravityAffected() const
{
  return d_isGravityAffected;
}

void InertialBase::setGravityAffected(bool i_affected)
{
  d_isGravityAffected = i_affected;
}


Physics_NS::Force InertialBase::getActiveForcesSum() const
{
  return Physics_NS::Force::zero();
}


double InertialBase::getMass() const
{
  return d_mass;
}

void InertialBase::setMass(double i_mass)
{
  d_mass = i_mass;
}


bool InertialBase::isMovable() const
{
  return d_isMovable;
}

void InertialBase::setMovable(bool i_movable)
{
  d_isMovable = i_movable;
}


Sdk::Vector2D InertialBase::getSpeed() const
{
  return d_speed;
}

void InertialBase::setSpeed(Sdk::Vector2D i_speed)
{
  d_speed = std::move(i_speed);
}

Sdk::Vector2D InertialBase::getPosition() const
{
  return d_position;
}

void InertialBase::setPosition(Sdk::Vector2D i_position)
{
  d_position = std::move(i_position);
}


double InertialBase::getRotationSpeed() const
{
  return d_rotationSpeed;
}

void InertialBase::setRotationSpeed(double i_speed)
{
  d_rotationSpeed = i_speed;
}


double InertialBase::getRotation() const
{
  return d_rotation;
}

void InertialBase::setRotation(double i_rotation)
{
  d_rotation = i_rotation;
}


bool InertialBase::isRotateToSpeed() const
{
  return d_rotateToSpeed;
}

void InertialBase::setRotateToSpeed(bool i_rotate)
{
  d_rotateToSpeed = i_rotate;
}


Sdk::RectD InertialBase::getShape() const
{
  return d_rect;
}

void InertialBase::setShape(Sdk::RectD i_shape)
{
  d_rect = std::move(i_shape);
}


double InertialBase::getElasticity() const
{
  return d_elasticity;
}

void InertialBase::setElasticity(double i_elasticity)
{
  d_elasticity = i_elasticity;
}
