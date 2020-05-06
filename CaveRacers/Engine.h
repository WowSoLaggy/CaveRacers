#pragma once

#include "IEngine.h"


class Engine : public IEngine
{
public:
  Engine(const IEnginePrototype& i_prototype);

  virtual const IEnginePrototype& getPrototype() const override;

  virtual double getMass() const override;

private:
  const IEnginePrototype& d_prototype;
};
