#include "stdafx.h"
#include "CreateLevel.h"

#include "CreateObjects.h"
#include "ISession.h"
#include "Level.h"
#include "Rocket.h"
#include "SceneObject.h"

#include <Sdk/Math.h>


std::unique_ptr<ILevel> createDefaultLevel(const ISession& i_session)
{
  auto defaultLevel = std::make_unique<Level>();

  // UTIL LAMBDAS

  auto rocket = [&](double i_x, double i_y)
  {
    auto rocket = createRocket(i_session.getFuelTankName(),
                               i_session.getEngineName(),
                               i_session.getHullName());
    CONTRACT_ASSERT(rocket);
    rocket->setPosition({ i_x, i_y });
    defaultLevel->addObject(rocket);
    return rocket;
  };

  auto landingSite = [&](double i_x, double i_y)
  {
    auto obj = createLandingSite();
    obj->setPosition({ i_x, i_y });
    defaultLevel->addObject(obj);
    return obj;
  };

  auto wall = [&](double i_x, double i_y)
  {
    auto obj = createWall();
    obj->setPosition({ i_x, i_y });
    defaultLevel->addObject(obj);
    return obj;
  };

  // Level creation

  defaultLevel->setBackgroundTextureName("Space.png");

  // Rockets

  auto player = rocket(20, 20);
  defaultLevel->setControlledRocket(player);

  rocket(40, 20);

  // Landings

  landingSite(20, 0);
  landingSite(30, 20);
  landingSite(40, 0);

  // Border

  constexpr double Increment = 6.3;

  for (double x = -30; x < 93; x += Increment)
  {
    wall(x, 45.3);
    wall(x, -24);
  }

  for (double y = -24 + Increment; y < 44; y += Increment)
  {
    wall(-30, y);
    wall(89.6, y);
  }

  return defaultLevel;
}
