#include "stdafx.h"
#include "GetCollision.h"

#include "IInertial.h"

#include <Sdk/Math.h>
#include <Sdk/Vector.h>


CollisionInfo getCollision(const IInertial& i_left, const IInertial& i_right)
{
  if (!i_left.isReceiveCollision() || !i_right.isSendCollision())
    return { i_left, i_right, false, Sdk::Vector2D::zero() };

  auto leftRect = i_left.getRect();
  auto rightRect = i_right.getRect();

  leftRect.move(i_left.getPosition());
  rightRect.move(i_right.getPosition());

  const bool isCollision = leftRect.intersectRect(rightRect);
  if (!isCollision)
    return { i_left, i_right, false, Sdk::Vector2D::zero() };

  Sdk::Vector2D normal;
  const auto side = Sdk::getSide(leftRect.center() - rightRect.center());
  switch (side)
  {
  case Sdk::Side::Up:
    normal = Sdk::Vector2D{ 0, -1 };
    break;
  case Sdk::Side::Down:
    normal = Sdk::Vector2D{ 0, 1 };
    break;
  case Sdk::Side::Left:
    normal = Sdk::Vector2D{ 1, 0 };
    break;
  case Sdk::Side::Right:
    normal = Sdk::Vector2D{ -1, 0 };
    break;

  default:
    CONTRACT_ASSERT(false);
  }

  return { i_left, i_right, true, normal };
}
