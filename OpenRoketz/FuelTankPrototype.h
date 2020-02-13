#pragma once

#include "IFuelTankPrototype.h"


class FuelTankPrototype : public IFuelTankPrototype
{
public:
  virtual const std::string& getName() const override;
  virtual double getMaxFuel() const override;
  virtual double getMassEmpty() const override;

  void setName(std::string i_name);
  void setMaxFuel(double i_maxFuel);
  void setMassEmpty(double i_massEmpty);

private:
  std::string d_name;
  double d_maxFuel = 0.0;
  double d_massEmpty = 0.0;
};
