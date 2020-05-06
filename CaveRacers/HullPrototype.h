#pragma once

#include "IHullPrototype.h"


class HullPrototype : public IHullPrototype
{
public:
  virtual const std::string& getName() const override;
  virtual double getMaxArmor() const override;
  virtual double getMass() const override;

  void setName(std::string i_name);
  void setMaxArmor(double i_maxArmor);
  void setMass(double i_mass);

private:
  std::string d_name;
  double d_maxArmor = 0.0;
  double d_mass = 0.0;
};
