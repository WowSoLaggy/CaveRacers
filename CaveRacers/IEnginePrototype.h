#pragma once

#include "IPrototype.h"


class IEnginePrototype : public IPrototype
{
public:
  virtual double getPower() const = 0;
  virtual double getConsumption() const = 0;
  virtual double getMass() const = 0;
};
