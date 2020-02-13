#pragma once

#include "Fwd.h"


class IHull
{
public:
  virtual ~IHull() = default;

  virtual const IHullPrototype& getPrototype() const = 0;

  virtual double getArmor() const = 0;
  virtual double getMass() const = 0;
};
