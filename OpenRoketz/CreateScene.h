#pragma once

#include "ILevelView.h"
#include "IScene.h"

#include <Dx/LaggyDxFwd.h>
#include <Sdk/Rect.h>


std::unique_ptr<IScene> createBattleScene(const ILevelView& io_levelView,
                                          Dx::IResourceController& i_resourceController,
                                          const Sdk::RectI& i_viewport);
