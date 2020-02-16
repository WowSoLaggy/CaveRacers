#pragma once

#include "ILevelView.h"
#include "IScene.h"

#include <Dx/LaggyDxFwd.h>
#include <Dx/Sprite.h>
#include <Sdk/Rect.h>


class BattleScene : public IScene
{
public:
  BattleScene(const ILevelView& io_levelView,
              Dx::IResourceController& i_resourceController,
              Sdk::RectI i_viewport);

  virtual void update(double i_dt) override;
  virtual void render(Dx::IRenderer2d& i_renderer) const override;

  virtual void showDebug(bool i_show) override;
  virtual void toggleDebug() override;

private:
  const ILevelView& d_levelView;
  Dx::IResourceController& d_resourceController;

  Sdk::Vector2I d_cameraOffset;
  Sdk::RectI d_viewport;

  std::optional<Dx::Sprite> d_background;

  double d_time = 0.0;
  const Dx::IFontResource& d_font;

  bool d_showDebug = false;

  void renderBackgound(Dx::IRenderer2d& i_renderer) const;
};
