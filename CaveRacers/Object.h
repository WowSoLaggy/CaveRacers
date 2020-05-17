#pragma once

#include "Fwd.h"
#include "InertialBase.h"
#include "ObjectBehavior.h"


class Object : public InertialBase
{
public:
  Object(ILevelModel& i_levelModel);

  ILevelModel& getLevel() const { return d_levelModel; }

  const std::string& getTextureName() const;
  void setTextureName(std::string i_textureName);

  ObjectBehavior getBehavior() const;
  void setBehavior(ObjectBehavior i_behavior);


  virtual void update(double i_dt);

private:
  ILevelModel& d_levelModel;

  std::string d_textureName;
  ObjectBehavior d_behavior = ObjectBehavior::Default;
};