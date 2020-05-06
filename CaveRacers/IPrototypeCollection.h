#pragma once

#include "Fwd.h"


class IPrototypeCollection
{
public:
  static const IPrototypeCollection& get();
  static void load();

public:
  virtual const IFuelTankPrototype& getFuelTank(const std::string& i_name) const = 0;
  virtual const IEnginePrototype& getEngine(const std::string& i_name) const = 0;
  virtual const IHullPrototype& getHull(const std::string& i_name) const = 0;

protected:
  virtual void loadInternal() = 0;
};
