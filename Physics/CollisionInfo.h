#pragma once

#include "Fwd.h"

#include <Sdk/Vector.h>


namespace Physics_NS
{
  struct CollisionInfo
  {
    const IInertial& object1;
    const IInertial& object2;

    const Sdk::Vector2D normal;
  };

} // Physics_NS
