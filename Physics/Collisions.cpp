#include "stdafx.h"
#include "Collisions.h"

#include "IInertial.h"

#include <Sdk/Math.h>


namespace Physics_NS
{
  std::optional<CollisionInfo> getCollision(const IInertial& i_object1, const IInertial& i_object2)
  {
    auto rect1 = i_object1.getShape();
    auto rect2 = i_object2.getShape();

    rect1.move(i_object1.getPosition());
    rect2.move(i_object2.getPosition());

    const bool isCollision = rect1.intersectRect(rect2);
    if (!isCollision)
      return std::nullopt;

    Sdk::Vector2D normal;
    const auto side = Sdk::getSide(rect1.center() - rect2.center());
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

    return CollisionInfo{ i_object1, i_object2, normal };
  }

} // Physics_NS
