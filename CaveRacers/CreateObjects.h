#pragma once

#include "Fwd.h"


std::shared_ptr<Rocket> createRocket(ILevelModel& i_levelModel,
                                     const std::string& i_fuelTankName,
                                     const std::string& i_engineName,
                                     const std::string& i_hullName);

std::shared_ptr<Object> createWall(ILevelModel& i_levelModel);
std::shared_ptr<Object> createLandingSite(ILevelModel& i_levelModel);

std::shared_ptr<Object> createProjectile(ILevelModel& i_levelModel);
