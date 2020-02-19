#include "stdafx.h"
#include "GetCollision.h"

#include "IInertial.h"

#include <Sdk/Math.h>


std::optional<Sdk::Vector2D> getCollisionNormal(const IInertial& i_left, const IInertial& i_right)
{
  if (!i_left.isReceiveCollision() || !i_right.isSendCollision())
    return std::nullopt;

  auto leftRect = i_left.getRect();
  auto rightRect = i_right.getRect();

  leftRect.move(i_left.getPosition());
  rightRect.move(i_right.getPosition());

  const bool isCollision = leftRect.intersectRect(rightRect);
  if (!isCollision)
    return std::nullopt;

  const auto side = Sdk::getSide(leftRect.center() - rightRect.center());
  switch (side)
  {
  case Sdk::Side::Up: return Sdk::Vector2D{ 0, -1 };
  case Sdk::Side::Down: return Sdk::Vector2D{ 0, 1 };
  case Sdk::Side::Left: return Sdk::Vector2D{ 1, 0 };
  case Sdk::Side::Right: return Sdk::Vector2D{ -1, 0 };
  }

  CONTRACT_ASSERT(false);
}
