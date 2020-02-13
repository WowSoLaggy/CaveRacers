#pragma once

#include "Fwd.h"


class IFuelTank
{
public:
  virtual ~IFuelTank() = default;

  virtual const IFuelTankPrototype& getPrototype() const = 0;

  virtual bool isEmpty() const = 0;
  virtual double getFuel() const = 0;

  virtual void fill() = 0;
  virtual void fill(double i_value) = 0;

  virtual void waste() = 0;
  virtual void waste(double i_value) = 0;

  virtual double getMass() const = 0;
};
