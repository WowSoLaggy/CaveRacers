#pragma once

#include "IEnginePrototype.h"


class EnginePrototype : public IEnginePrototype
{
public:
  virtual const std::string& getName() const override;
  virtual double getPower() const override;
  virtual double getConsumption() const override;
  virtual double getMass() const override;

  void setName(std::string i_name);
  void setPower(double i_power);
  void setConsumption(double i_consumption);
  void setMass(double i_mass);

private:
  std::string d_name;

  double d_power = 0.0;
  double d_consumption = 0.0;
  double d_mass = 0.0;
};
