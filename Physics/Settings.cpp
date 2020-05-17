#include "stdafx.h"
#include "Settings.h"


namespace Physics_NS
{
  double Settings::getGravityAcceleration() const
  {
    return d_gravityAcceleration;
  }

  void Settings::setGravityAcceleration(double i_gravity)
  {
    d_gravityAcceleration = i_gravity;
  }

} // Physics_NS
