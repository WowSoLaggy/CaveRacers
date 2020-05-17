#pragma once

#include "Constants.h"


namespace Physics_NS
{
  class Settings
  {
  public:
    double getGravityAcceleration() const;
    void setGravityAcceleration(double i_gravity);

  private:
    double d_gravityAcceleration = Constants::GravitationalAccelerationEarth;
  };

} // Physics_NS
