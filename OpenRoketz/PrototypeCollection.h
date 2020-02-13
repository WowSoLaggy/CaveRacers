#pragma once

#include "EnginePrototype.h"
#include "FuelTankPrototype.h"
#include "HullPrototype.h"
#include "IPrototypeCollection.h"

#include <Sdk/json.h>


class PrototypeCollection : public IPrototypeCollection
{
public:
  virtual const IFuelTankPrototype& getFuelTank(const std::string& i_name) const override;
  virtual const IEnginePrototype& getEngine(const std::string& i_name) const override;
  virtual const IHullPrototype& getHull(const std::string& i_name) const override;

private:
  std::vector<FuelTankPrototype> d_fuelTanks;
  std::vector<EnginePrototype> d_engines;
  std::vector<HullPrototype> d_hulls;

  virtual void loadInternal() override;
  void loadComponents(const fs::path& i_componentsFile);
  void loadFuelTanks(const Json::Value& i_node);
  void loadEngines(const Json::Value& i_node);
  void loadHull(const Json::Value& i_node);
};
