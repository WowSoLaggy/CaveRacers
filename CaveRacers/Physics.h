#pragma once

#include "Force.h"
#include "IInertial.h"

#include <Sdk/Vector.h>


class Physics
{
public:
  void update(double i_dt, std::vector<std::shared_ptr<IInertial>>& io_objects) const;

private:
  void updateObject(double i_dt, IInertial& io_object, const std::vector<Sdk::Vector2D>& i_normals) const;
  void updateObjectLinear(double i_dt, IInertial& io_object, const std::vector<Sdk::Vector2D>& i_normals) const;
  void updateObjectRotation(double i_dt, IInertial& io_object) const;
};
