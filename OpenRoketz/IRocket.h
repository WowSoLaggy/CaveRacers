#pragma once

#include "IRocketControl.h"
#include "ISceneObject.h"


class IRocket : public ISceneObject, public IRocketControl
{
public:
  virtual double getFuelPercentage() const = 0;
};
