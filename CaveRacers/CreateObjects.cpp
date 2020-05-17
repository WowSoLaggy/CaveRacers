#include "stdafx.h"
#include "CreateObjects.h"

#include "IPrototypeCollection.h"
#include "ILevelModel.h"
#include "Object.h"
#include "Rocket.h"


std::shared_ptr<Rocket> createRocket(ILevelModel& i_levelModel,
                                     const std::string& i_fuelTankName,
                                     const std::string& i_engineName,
                                     const std::string& i_hullName)
{
  const auto& prototypeCollection = IPrototypeCollection::get();

  FuelTank fuelTank(prototypeCollection.getFuelTank(i_fuelTankName));
  fuelTank.fill();

  Engine engine(prototypeCollection.getEngine(i_engineName));
  Hull hull(prototypeCollection.getHull(i_hullName));

  auto rocket = std::make_shared<Rocket>(i_levelModel, std::move(fuelTank), std::move(engine), std::move(hull));
  rocket->setTextureName("Rocket.png");

  rocket->setGravityAffected(true);

  i_levelModel.addObject(rocket);
  return rocket;
}


std::shared_ptr<Object> createWall(ILevelModel& i_levelModel)
{
  auto object = std::make_shared<Object>(i_levelModel);
  object->setTextureName("Wall.png");
  object->setMovable(false);

  i_levelModel.addObject(object);
  return object;
}

std::shared_ptr<Object> createLandingSite(ILevelModel& i_levelModel)
{
  auto object = std::make_shared<Object>(i_levelModel);
  object->setTextureName("LandingSite.png");
  object->setBehavior(ObjectBehavior::LandingSite);
  object->setMovable(false);

  i_levelModel.addObject(object);
  return object;
}


std::shared_ptr<Object> createProjectile(ILevelModel& i_levelModel)
{
  auto object = std::make_shared<Object>(i_levelModel);
  object->setTextureName("Projectile.png");
  object->setMass(0.1);

  constexpr double HalfSize = 8.0 / 2 / 10;
  object->setShape({ -HalfSize, HalfSize, -HalfSize, HalfSize });

  object->setGravityAffected(true);
  object->setRotateToSpeed(true);

  i_levelModel.addObject(object);
  return object;
}
