#include "stdafx.h"
#include "IInertial.h"

#include <Sdk/Math.h>


namespace Physics_NS
{
  Sdk::Vector2D IInertial::getDirection() const
  {
    const double rotation = getRotation();
    return { std::sin(rotation), std::cos(rotation) };
  }

  double IInertial::getSpeedAngle() const
  {
    const auto linearSpeed = getSpeed();
    return -std::atan2(linearSpeed.y, linearSpeed.x) + Sdk::PiHalf;
  }


  void IInertial::updateCollisions(const std::vector<CollisionInfo>& i_collisions)
  {
    // nop
  }

} // Physics_NS
