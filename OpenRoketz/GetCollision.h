#pragma once

#include "Fwd.h"

#include <Sdk/Vector.h>


std::optional<Sdk::Vector2D> getCollisionNormal(const IInertial& i_left, const IInertial& i_right);
