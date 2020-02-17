#pragma once

#include "ObjectBehavior.h"
#include "IInertial.h"

#include <Sdk/Vector.h>


class ISceneObject : public IInertial
{
public:
  virtual const std::string& getTextureName() const = 0;

  virtual void update(double i_dt) { }

  virtual ObjectBehavior getBehavior() const = 0;
};