#pragma once

#include "Fwd.h"
#include "ILevel.h"

#include <Physics/Physics.h>


class Level : public ILevel
{
public:
  Physics_NS::Physics& getPhysics();
  const Physics_NS::Physics& getPhysics() const;

  virtual std::optional<std::string> getBackgroundTextureName() const override;
  void setBackgroundTextureName(std::string i_textureName);

  virtual std::vector<std::shared_ptr<Object>> getObjects() const override;
  virtual std::shared_ptr<Object> getControlledObjectView() const override;

  virtual std::shared_ptr<IRocketControl> getControlledObject() const override;

  virtual void addObject(std::shared_ptr<Object> i_object) override;

  void setControlledRocket(std::shared_ptr<Rocket> i_rocket);

  virtual void update(double i_dt) override;

private:
  Physics_NS::Physics d_physics;

  std::optional<std::string> d_backgroundTextureName;
  std::vector<std::shared_ptr<Object>> d_objects;

  std::weak_ptr<Rocket> d_controlledRocket;
};
