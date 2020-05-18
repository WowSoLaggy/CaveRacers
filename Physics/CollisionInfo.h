#pragma once

#include "Fwd.h"

#include <Sdk/Vector.h>


namespace Physics_NS
{
  struct CollisionInfo
  {
    const IInertial& object;
    const Sdk::Vector2D normal;
  };

} // Physics_NS
