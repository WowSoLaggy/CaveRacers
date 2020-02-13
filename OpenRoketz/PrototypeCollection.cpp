#include "stdafx.h"
#include "PrototypeCollection.h"

#include "SettingsProvider.h"

#include <Sdk/json.h>


void PrototypeCollection::loadInternal()
{
  const auto& settings = SettingsProvider::getDefaultInternalSettings();
  loadComponents(settings.configFolder / settings.componentPrototypesFile);
}


const IFuelTankPrototype& PrototypeCollection::getFuelTank(const std::string& i_name) const
{
  const auto it = std::find_if(d_fuelTanks.cbegin(), d_fuelTanks.cend(),
                               [&](const auto& i_fuelTankProto) { return i_fuelTankProto.getName() == i_name; });
  CONTRACT_EXPECT(it != d_fuelTanks.cend());
  return *it;
}

const IEnginePrototype& PrototypeCollection::getEngine(const std::string& i_name) const
{
  const auto it = std::find_if(d_engines.cbegin(), d_engines.cend(),
                               [&](const auto& i_fuelTankProto) { return i_fuelTankProto.getName() == i_name; });
  CONTRACT_EXPECT(it != d_engines.cend());
  return *it;
}

const IHullPrototype& PrototypeCollection::getHull(const std::string& i_name) const
{
  const auto it = std::find_if(d_hulls.cbegin(), d_hulls.cend(),
                               [&](const auto& i_fuelTankProto) { return i_fuelTankProto.getName() == i_name; });
  CONTRACT_EXPECT(it != d_hulls.cend());
  return *it;
}


void PrototypeCollection::loadComponents(const fs::path& i_componentsFile)
{
  if (!fs::exists(i_componentsFile))
    return;

  std::ifstream file(i_componentsFile.string(), std::ifstream::binary);

  Json::Reader reader;
  Json::Value root;
  const bool success = reader.parse(file, root, false);
  if (!success)
  {
    const auto errors = reader.getFormattedErrorMessages();
    CONTRACT_ASSERT(false);
  }

  // Fuel tanks

  loadFuelTanks(root["FuelTanks"]);
  loadEngines(root["Engines"]);
  loadHull(root["Hulls"]);
}

void PrototypeCollection::loadFuelTanks(const Json::Value& i_node)
{
  const auto names = i_node.getMemberNames();
  for (const auto& name : names)
  {
    FuelTankPrototype proto;

    const auto& node = i_node[name];

    proto.setName(name);
    proto.setMaxFuel(node["MaxFuel"].asDouble());
    proto.setMassEmpty(node["MassEmpty"].asDouble());

    d_fuelTanks.push_back(std::move(proto));
  }
}

void PrototypeCollection::loadEngines(const Json::Value& i_node)
{
  const auto names = i_node.getMemberNames();
  for (const auto& name : names)
  {
    EnginePrototype proto;

    const auto& node = i_node[name];

    proto.setName(name);
    proto.setPower(node["Power"].asDouble());
    proto.setConsumption(node["Consumption"].asDouble());
    proto.setMass(node["Mass"].asDouble());

    d_engines.push_back(std::move(proto));
  }
}

void PrototypeCollection::loadHull(const Json::Value& i_node)
{
  const auto names = i_node.getMemberNames();
  for (const auto& name : names)
  {
    HullPrototype proto;

    const auto& node = i_node[name];

    proto.setName(name);
    proto.setMaxArmor(node["MaxArmor"].asDouble());
    proto.setMass(node["Mass"].asDouble());

    d_hulls.push_back(std::move(proto));
  }
}
