#pragma once

#include "CollisionInfo.h"
#include "Fwd.h"


namespace Physics_NS
{
  /// Returns collision between the two given objects if any
  /// \param[in] i_object1 - first object to check the collision
  /// \param[in] i_object2 - second object to check the collision
  /// \return Info about the collision or nullopt if there is no collision
  std::optional<CollisionInfo> getCollision(const IInertial& i_object1, const IInertial& i_object2);

} // Physics_NS
