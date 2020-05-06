#pragma once

#include "Fwd.h"


class IEngine
{
public:
  virtual ~IEngine() = default;

  virtual const IEnginePrototype& getPrototype() const = 0;

  virtual double getMass() const = 0;
};
