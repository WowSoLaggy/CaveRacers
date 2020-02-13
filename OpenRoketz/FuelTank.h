#pragma once

#include "IFuelTank.h"


class FuelTank : public IFuelTank
{
public:
  FuelTank(const IFuelTankPrototype& i_prototype);

  virtual const IFuelTankPrototype& getPrototype() const override;

  virtual bool isEmpty() const override;
  virtual double getFuel() const override;

  virtual void fill() override;
  virtual void fill(double i_value) override;

  virtual void waste() override;
  virtual void waste(double i_value) override;

  virtual double getMass() const override;

private:
  double d_fuel = 0.0;
  const IFuelTankPrototype& d_prototype;
};
