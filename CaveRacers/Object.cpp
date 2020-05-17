#include "stdafx.h"
#include "Object.h"

#include <Sdk/Math.h>


Object::Object(ILevelModel& i_levelModel)
  : d_levelModel(i_levelModel)
{
}


const std::string& Object::getTextureName() const
{
  return d_textureName;
}

void Object::setTextureName(std::string i_textureName)
{
  d_textureName = std::move(i_textureName);
}


ObjectBehavior Object::getBehavior() const
{
  return d_behavior;
}

void Object::setBehavior(ObjectBehavior i_behavior)
{
  d_behavior = i_behavior;
}


void Object::update(double i_dt)
{
}
