#pragma once

#include "Fwd.h"


class ILevelModel
{
public:
  virtual ~ILevelModel() = default;

  virtual void update(double i_dt) = 0;

  virtual std::shared_ptr<IRocketControl> getControlledObject() const = 0;
};
