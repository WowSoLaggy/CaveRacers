#pragma once

#include "Fwd.h"


std::shared_ptr<Rocket> createRocket(const std::string& i_fuelTankName,
                                     const std::string& i_engineName,
                                     const std::string& i_hullName);

std::shared_ptr<SceneObject> createWall();
std::shared_ptr<SceneObject> createLandingSite();

std::shared_ptr<SceneObject> createProjectile();
