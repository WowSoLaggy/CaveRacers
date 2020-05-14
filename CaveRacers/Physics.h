#pragma once

#include "Fwd.h"


class Physics
{
public:
  void update(double i_dt, std::vector<std::shared_ptr<IInertial>>& io_objects) const;

private:
  void updateObject(double i_dt, IInertial& io_object) const;
  void updateObjectLinear(double i_dt, IInertial& io_object) const;
  void updateObjectRotation(double i_dt, IInertial& io_object) const;
};
