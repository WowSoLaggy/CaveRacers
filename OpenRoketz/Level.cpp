#include "stdafx.h"
#include "Level.h"

#include "Rocket.h"


std::optional<std::string> Level::getBackgroundTextureName() const
{
  return d_backgroundTextureName;
}

void Level::setBackgroundTextureName(std::string i_textureName)
{
  d_backgroundTextureName = std::move(i_textureName);
}


std::vector<std::shared_ptr<ISceneObject>> Level::getObjects() const
{
  return d_objects;
}

std::shared_ptr<ISceneObject> Level::getControlledObjectView() const
{
  return d_controlledRocket.lock();
}

std::shared_ptr<IRocketControl> Level::getControlledObject() const
{
  return d_controlledRocket.lock();
}


void Level::addObject(std::shared_ptr<ISceneObject> i_object)
{
  d_objects.push_back(std::move(i_object));
}

void Level::setControlledRocket(std::shared_ptr<IRocket> i_rocket)
{
  d_controlledRocket = i_rocket;
}


Physics& Level::getPhysics()
{
  return d_physics;
}


void Level::update(double i_dt)
{
  for (auto& object : d_objects)
    object->update(i_dt);

  auto inertials = std::vector<std::shared_ptr<IInertial>>{d_objects.begin(), d_objects.end()};
  d_physics.update(i_dt, inertials);
}
