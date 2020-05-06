#pragma once

#include "Fwd.h"
#include "IInertial.h"
#include "ObjectBehavior.h"

#include <Sdk/Vector.h>


class ISceneObject : public IInertial
{
public:
  virtual const std::string& getTextureName() const = 0;

  virtual void update(double i_dt) = 0;

  virtual ObjectBehavior getBehavior() const = 0;

  ILevelModel* getLevel() const { return d_levelModel; }
  void setLevel(ILevelModel* i_levelModel) { d_levelModel = i_levelModel; }

private:
  ILevelModel* d_levelModel = nullptr;
};