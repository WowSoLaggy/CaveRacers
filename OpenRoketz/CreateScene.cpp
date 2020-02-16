#include "stdafx.h"
#include "CreateScene.h"

#include "BattleScene.h"


std::unique_ptr<IScene> createBattleScene(const ILevelView& io_levelView,
                                          Dx::IResourceController& i_resourceController,
                                          const Sdk::RectI& i_viewport)
{
  auto battleScene = std::make_unique<BattleScene>(io_levelView, i_resourceController, i_viewport);
  battleScene->showDebug(true);
  return battleScene;
}
