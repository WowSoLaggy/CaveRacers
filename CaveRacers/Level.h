#pragma once

#include "Fwd.h"
#include "ILevel.h"


class Level : public ILevel
{
public:
  virtual std::optional<std::string> getBackgroundTextureName() const override;
  void setBackgroundTextureName(std::string i_textureName);

  virtual std::vector<std::shared_ptr<ISceneObject>> getObjects() const override;
  virtual std::shared_ptr<ISceneObject> getControlledObjectView() const override;

  virtual std::shared_ptr<IRocketControl> getControlledObject() const override;

  virtual void addObject(std::shared_ptr<ISceneObject> i_object) override;

  void setControlledRocket(std::shared_ptr<IRocket> i_rocket);

  virtual void update(double i_dt) override;

private:
  std::optional<std::string> d_backgroundTextureName;
  std::vector<std::shared_ptr<ISceneObject>> d_objects;

  std::weak_ptr<IRocket> d_controlledRocket;
};
