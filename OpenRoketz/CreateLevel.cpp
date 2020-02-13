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

  defaultLevel->setBackgroundTextureName("Space.png");

  // Player

  {
    auto rocket = createRocket(i_session.getFuelTankName(),
                               i_session.getEngineName(),
                               i_session.getHullName());
    CONTRACT_ASSERT(rocket);
    rocket->setPosition({ 20, 20 });
    defaultLevel->addObject(rocket);

    defaultLevel->setControlledRocket(rocket);
  }

  // Enemy

  {
    auto rocket = createRocket(i_session.getFuelTankName(),
                               i_session.getEngineName(),
                               i_session.getHullName());
    CONTRACT_ASSERT(rocket);
    rocket->setPosition({ 40, 20 });
    defaultLevel->addObject(rocket);
  }

  // Scenery

  auto wall1 = createWall();
  wall1->setPosition({ 30, 20 });
  defaultLevel->addObject(wall1);

  auto wall2 = createWall();
  wall2->setPosition({ 20, 0 });
  defaultLevel->addObject(wall2);

  auto wall3 = createWall();
  wall3->setPosition({ 40, 0 });
  defaultLevel->addObject(wall3);

  return defaultLevel;
}
