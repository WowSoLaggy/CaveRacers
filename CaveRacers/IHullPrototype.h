#pragma once

#include "IPrototype.h"


class IHullPrototype : public IPrototype
{
public:
  virtual double getMaxArmor() const = 0;
  virtual double getMass() const = 0;
};
