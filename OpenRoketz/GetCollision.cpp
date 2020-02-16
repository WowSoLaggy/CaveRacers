#include "stdafx.h"
#include "GetCollision.h"

#include "IInertial.h"


bool getCollision(const IInertial& i_left, const IInertial& i_right)
{
  if (!i_right.isCollidable() || !i_left.isCollidable())
    return false;

  const bool isCollision = i_left.getRect().intersectRect(i_right.getRect());
  return isCollision;
}
