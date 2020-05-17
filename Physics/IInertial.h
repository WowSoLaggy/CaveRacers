#pragma once

#include "CollisionInfo.h"
#include "Force.h"

#include <Sdk/Rect.h>
#include <Sdk/Vector.h>


namespace Physics_NS
{
  class IInertial
  {
  public:
    virtual ~IInertial() = default;

    /// Returns whether the object is affected by gravity
    virtual bool isGravityAffected() const = 0;

    /// Returns sum of all actives forces that affect this object
    virtual Force getActiveForcesSum() const = 0;

    /// Returns mass of the object
    virtual double getMass() const = 0;

    /// Returns whether the object is movable
    virtual bool isMovable() const = 0;

    /// Returns speed of the object
    virtual Sdk::Vector2D getSpeed() const = 0;
    /// Sets speed of the object
    /// \param[in] i_speed - new speed of the object
    virtual void setSpeed(Sdk::Vector2D i_speed) = 0;

    /// Returns position of the object
    virtual Sdk::Vector2D getPosition() const = 0;
    /// Sets position of the object
    /// \param[in] i_position - new position of the object
    virtual void setPosition(Sdk::Vector2D i_position) = 0;

    /// Returns rotation speed of the object
    virtual double getRotationSpeed() const = 0;
    
    /// Returns angle of the rotation of the object
    virtual double getRotation() const = 0;
    /// Sets angle of the rotation of the object
    virtual void setRotation(double i_rotation) = 0;

    /// Returns the 'forward' direction depending on the current rotation angle
    Sdk::Vector2D getDirection() const;

    /// Returns angle of the speed vector
    double getSpeedAngle() const;

    /// Returns whether the object always looks towards the speed
    virtual bool isRotateToSpeed() const = 0;

    /// Returns shape of the object (only rectangle is supported so far)
    virtual Sdk::RectD getShape() const = 0;

    /// Calls on each physics update to notify object about all its collisions
    /// \param[in] i_collisions - all collisions on the current frame
    virtual void updateCollisions(const std::vector<CollisionInfo>& i_collisions);
  };

} // Physics_NS
