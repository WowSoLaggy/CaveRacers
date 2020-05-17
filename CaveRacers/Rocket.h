#pragma once

#include "Engine.h"
#include "FuelTank.h"
#include "Hull.h"
#include "IRocketControl.h"
#include "Object.h"


class Rocket : public IRocketControl, public Object
{
public:
  Rocket(ILevelModel& i_levelModel, FuelTank i_fuelTank, Engine i_engine, Hull i_hull);

  double getFuelPercentage() const;

  // Object::

  virtual double getMass() const override;
  virtual void update(double i_dt) override;

  virtual Physics_NS::Force getActiveForcesSum() const override;
  virtual void updateCollisions(const std::vector<Physics_NS::CollisionInfo>& i_collisions) override;

  // IRocketControl::

  virtual void thrust(bool i_on) override;
  virtual void turnLeft(bool i_on) override;
  virtual void turnRight(bool i_on) override;

  virtual void fire1() override;

  virtual void refill() override;

private:
  FuelTank d_fuelTank;
  Engine d_engine;
  Hull d_hull;

  bool d_isThrustOn = false;
  bool d_isRotateLeftOn = false;
  bool d_isRotateRightOn = false;

  bool d_landed = false;

  Physics_NS::Force d_thrust;
};
