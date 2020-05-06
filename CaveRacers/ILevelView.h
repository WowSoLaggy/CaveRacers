#pragma once

#include "Fwd.h"

#include <Sdk/EventHandler.h>


class ILevelView : public Sdk::EventHandler
{
public:
  virtual ~ILevelView() = default;

  virtual std::optional<std::string> getBackgroundTextureName() const = 0;

  virtual std::vector<std::shared_ptr<ISceneObject>> getObjects() const = 0;

  virtual std::shared_ptr<ISceneObject> getControlledObjectView() const = 0;
};
