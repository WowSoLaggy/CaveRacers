#pragma once

#include "Fwd.h"

#include <Sdk/Vector.h>


namespace Physics_NS
{
  /// Returns the normal vector of collision between the two given objects if any
  /// \param[in] i_object1 - first object to check the collision
  /// \param[in] i_object2 - second object to check the collision
  /// \return Collision normal or nullopt if there is no collision
  std::optional<Sdk::Vector2D> getCollision(const IInertial& i_object1, const IInertial& i_object2);

} // Physics_NS
