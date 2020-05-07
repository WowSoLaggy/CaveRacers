#pragma once

#include "Fwd.h"

#include <Sdk/Vector.h>


struct CollisionInfo
{
  const IInertial& receiver;
  const IInertial& sender;

  const bool isCollision;

  const Sdk::Vector2D normal;
};
