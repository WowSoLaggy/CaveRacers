#pragma once

#include "Force.h"
#include "IInertial.h"


class Physics
{
public:
  void update(double i_dt, std::vector<std::shared_ptr<IInertial>>& io_objects) const;

  void addStaticForce(Force i_staticForce);

private:
  std::vector<Force> d_staticForces;

  Force getStaticForcesSum() const;

  void updateObject(double i_dt, IInertial& io_object, const Force& i_staticForceSum) const;
  void updateObjectLinear(double i_dt, IInertial& io_object, const Force& i_staticForceSum) const;
  void updateObjectRotation(double i_dt, IInertial& io_object) const;
};
