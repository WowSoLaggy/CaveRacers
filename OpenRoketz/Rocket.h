#pragma once

#include "Engine.h"
#include "Force.h"
#include "FuelTank.h"
#include "Hull.h"
#include "IRocket.h"


class Rocket : public IRocket
{
public:
  Rocket(FuelTank i_fuelTank, Engine i_engine, Hull i_hull);

  void setTextureName(std::string i_textureName);
  
  // IInertial implementation

  virtual double getMass() const override;

  virtual const Sdk::Vector2D& getPosition() const override;
  virtual void setPosition(Sdk::Vector2D i_position) override;

  virtual const Sdk::Vector2D& getSpeed() const override;
  virtual void setSpeed(Sdk::Vector2D i_speed) override;

  virtual double getRotation() const override;
  virtual void setRotation(double i_rotation) override;

  virtual double getRotationSpeed() const override;
  virtual void setRotationSpeed(double i_rotationSpeed) override;

  virtual void addActiveForce(Force i_force) override;
  virtual const std::vector<Force>& getActiveForces() const override;
  virtual void clearActiveForces() override;

  virtual bool isGravityAffected() const override;
  virtual void setGravityAffected(bool i_affected) override;

  virtual Sdk::RectD getRect() const override;
  virtual bool isReceiveCollision() const override;
  virtual bool isSendCollision() const override;
  virtual bool isRigid() const override;

  virtual void addCollidedObject(std::shared_ptr<IInertial> i_object) override;
  virtual void clearCollidedObjects() override;

  // ISceneObject implementation

  virtual const std::string& getTextureName() const override;
  virtual void update(double i_dt) override;
  virtual ObjectBehavior getBehavior() const override;

  // IRocketControl implementation

  virtual void thrust() override;
  virtual void turnLeft() override;
  virtual void turnRight() override;

  virtual void fire() override;
  virtual void changeWeapon() override;

  virtual void refill() override;

  // IRocket implementation

  virtual double getFuelPercentage() const override;

private:
  FuelTank d_fuelTank;
  Engine d_engine;
  Hull d_hull;

  Sdk::Vector2D d_position;
  Sdk::Vector2D d_speed;

  double d_rotation = 0.0;
  double d_rotationSpeed = 0.0;

  std::vector<Force> d_activeForces;

  bool d_gravityAffected = true;

  std::vector<std::shared_ptr<IInertial>> d_collidedObjects;

  bool d_moving = false;

  std::string d_textureName;
};
