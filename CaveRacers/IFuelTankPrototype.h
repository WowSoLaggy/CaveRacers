#pragma once

#include "IPrototype.h"


class IFuelTankPrototype : public IPrototype
{
public:
  virtual double getMaxFuel() const = 0;
  virtual double getMassEmpty() const = 0;
};
