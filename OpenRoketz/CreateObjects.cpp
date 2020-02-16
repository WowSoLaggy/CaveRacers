#include "stdafx.h"
#include "CreateObjects.h"

#include "IPrototypeCollection.h"
#include "Rocket.h"
#include "SceneObject.h"


std::shared_ptr<Rocket> createRocket(const std::string& i_fuelTankName,
                                     const std::string& i_engineName,
                                     const std::string& i_hullName)
{
  const auto& prototypeCollection = IPrototypeCollection::get();

  FuelTank fuelTank(prototypeCollection.getFuelTank(i_fuelTankName));
  fuelTank.fill();

  Engine engine(prototypeCollection.getEngine(i_engineName));
  Hull hull(prototypeCollection.getHull(i_hullName));

  auto rocket = std::make_shared<Rocket>(std::move(fuelTank), std::move(engine), std::move(hull));
  rocket->setTextureName("Rocket.png");
  return rocket;
}


std::shared_ptr<SceneObject> createWall()
{
  auto wall = std::make_shared<SceneObject>();
  wall->setTextureName("Wall.png");
  return wall;
}
