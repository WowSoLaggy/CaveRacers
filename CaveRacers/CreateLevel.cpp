#include "stdafx.h"
#include "CreateLevel.h"

#include "CreateObjects.h"
#include "ISession.h"
#include "Level.h"
#include "Rocket.h"
#include "Object.h"

#include <Physics/Constants.h>
#include <Sdk/Math.h>


std::unique_ptr<ILevel> createDefaultLevel(const ISession& i_session)
{
  auto levelPtr = std::make_unique<Level>();
  auto& level = CONTRACT_DEREF(levelPtr);

  // UTIL LAMBDAS

  auto rocket = [&](double i_x, double i_y)
  {
    auto rocket = createRocket(level,
                               i_session.getFuelTankName(),
                               i_session.getEngineName(),
                               i_session.getHullName());
    CONTRACT_ASSERT(rocket);
    rocket->setPosition({ i_x, i_y });
    return rocket;
  };

  auto landingSite = [&](double i_x, double i_y)
  {
    auto obj = createLandingSite(level);
    CONTRACT_ASSERT(obj);
    obj->setPosition({ i_x, i_y });
    return obj;
  };

  auto wall = [&](double i_x, double i_y)
  {
    auto obj = createWall(level);
    CONTRACT_ASSERT(obj);
    obj->setPosition({ i_x, i_y });
    return obj;
  };

  // Level creation

  level.setBackgroundTextureName("Space.png");
  level.getPhysics().getSettings().
    setGravityAcceleration(Physics_NS::Constants::GravitationalAccelerationNibiru);

  // Rockets

  auto player = rocket(20, 20);
  level.setControlledRocket(player);

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

  return levelPtr;
}
