#pragma once

#include "Force.h"

#include <Sdk/Vector.h>


class IInertial
{
public:
  virtual ~IInertial() = default;

  virtual double getMass() const = 0;

  virtual const Sdk::Vector2D& getPosition() const = 0;
  virtual void setPosition(Sdk::Vector2D i_position) = 0;

  virtual const Sdk::Vector2D& getSpeed() const = 0;
  virtual void setSpeed(Sdk::Vector2D i_speed) = 0;

  virtual double getRotation() const = 0;
  virtual void setRotation(double i_rotation) = 0;

  virtual double getRotationSpeed() const = 0;
  virtual void setRotationSpeed(double i_rotationSpeed) = 0;

  virtual void addActiveForce(Force i_force) = 0;
  virtual const std::vector<Force>& getActiveForces() const = 0;
  virtual void clearActiveForces() = 0;

  virtual bool isGravityAffected() const = 0;
  virtual void setGravityAffected(bool i_affected) = 0;
};