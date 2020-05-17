#pragma once

#include "Fwd.h"

#include <Sdk/IEvent.h>


class OnControlledObjectChange : public Sdk::IEvent
{
public:
  std::shared_ptr<Rocket> getControlledRocket() const { return d_controlledRocket; }
private:
  std::shared_ptr<Rocket> d_controlledRocket;
};
