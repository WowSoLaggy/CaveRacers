#pragma once

#include "CollisionInfo.h"
#include "Fwd.h"
#include "Settings.h"

#include <Sdk/Vector.h>


namespace Physics_NS
{
  class Physics
  {
  public:
    /// Returns physics settings
    Settings& getSettings();
    /// Returns physics settings
    const Settings& getSettings() const;

    /// TODO: ae Detail what exactly is updated
    /// \param[in, out] io_objects - objects to update
    /// \param[in]      i_dt       - delta time to update objects on
    void update(
      const std::vector<std::shared_ptr<IInertial>>& io_objects,
      double i_dt) const;

  private:
    /// Stores physics settings
    Settings d_settings;

    /// Map of collisions for every updated object last frame
    mutable std::unordered_map<const IInertial*, std::vector<CollisionInfo>> d_collisionsMap;

    void updateObject(IInertial& io_object, double i_dt) const;
    void updateLinear(IInertial& io_object, double i_dt) const;
    void updateAngular(IInertial& io_object, double i_dt) const;
    Sdk::Vector2D getAcceleration(IInertial& i_object) const;
  };

} // Physics_NS
