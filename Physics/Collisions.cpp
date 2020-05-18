#include "stdafx.h"
#include "Collisions.h"

#include "IInertial.h"

#include <Sdk/Math.h>


namespace Physics_NS
{
  std::optional<Sdk::Vector2D> getCollision(const IInertial& i_object1, const IInertial& i_object2)
  {
    auto rect1 = i_object1.getShape();
    auto rect2 = i_object2.getShape();

    rect1.move(i_object1.getPosition());
    rect2.move(i_object2.getPosition());

    const bool isCollision = rect1.intersectRect(rect2);
    if (!isCollision)
      return std::nullopt;

    const auto side = Sdk::getSide(rect1.center() - rect2.center());
    switch (side)
    {
    case Sdk::Side::Up:
      return Sdk::Vector2D{ 0, -1 };
    case Sdk::Side::Down:
      return Sdk::Vector2D{ 0, 1 };
    case Sdk::Side::Left:
      return Sdk::Vector2D{ 1, 0 };
    case Sdk::Side::Right:
      return Sdk::Vector2D{ -1, 0 };

    default:
      CONTRACT_ASSERT(false);
    }
  }

} // Physics_NS
