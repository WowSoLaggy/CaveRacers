#pragma once

#include <Physics/IInertial.h>


class InertialBase : public Physics_NS::IInertial
{
public:
  virtual bool isGravityAffected() const override;
  void setGravityAffected(bool i_affected);

  virtual Physics_NS::Force getActiveForcesSum() const override;

  virtual double getMass() const override;
  void setMass(double i_mass);

  virtual bool isMovable() const override;
  void setMovable(bool i_movable);

  virtual Sdk::Vector2D getSpeed() const override;
  virtual void setSpeed(Sdk::Vector2D i_speed) override;

  virtual Sdk::Vector2D getPosition() const override;
  virtual void setPosition(Sdk::Vector2D i_position) override;

  virtual double getRotationSpeed() const override;
  void setRotationSpeed(double i_speed);

  virtual double getRotation() const override;
  virtual void setRotation(double i_rotation) override;

  virtual bool isRotateToSpeed() const override;
  void setRotateToSpeed(bool i_rotate);

  virtual Sdk::RectD getShape() const override;
  void setShape(Sdk::RectD i_shape);

private:
  bool d_isGravityAffected = false;
  double d_mass = 0.0;
  bool d_isMovable = true;
  Sdk::Vector2D d_speed;
  Sdk::Vector2D d_position;
  double d_rotationSpeed = 0.0;
  double d_rotation = 0.0;
  bool d_rotateToSpeed = false;
  Sdk::RectD d_rect;
};
