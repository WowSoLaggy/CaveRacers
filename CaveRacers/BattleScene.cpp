#include "stdafx.h"
#include "BattleScene.h"

#include "Rocket.h"

#include <Dx/ImageDescription.h>
#include <Dx/IResourceController.h>
#include <Dx/IRenderer2d.h>
#include <Dx/ITextureResource.h>
#include <Dx/Sprite.h>
#include <Sdk/StringUtils.h>


namespace
{
  constexpr double WorldScale = 10.0;
  const std::string FontName = "MyFont.spritefont";

} // anonymous NS


BattleScene::BattleScene(ILevelView& io_levelView,
                         Dx::IResourceController& i_resourceController,
                         Sdk::RectI i_viewport)
  : d_levelView(io_levelView)
  , d_resourceController(i_resourceController)
  , d_font(i_resourceController.getFontResource(FontName))
  , d_viewport(std::move(i_viewport))
  , d_gui(i_resourceController, io_levelView)
{
  if (const auto backgroundTextureName = d_levelView.getBackgroundTextureName())
  {
    Dx::Sprite backgroundSprite;

    backgroundSprite.setTexture(&d_resourceController.getTextureResource(*backgroundTextureName));
    backgroundSprite.setPosition(d_viewport.topLeft());

    d_background = std::move(backgroundSprite);
  }
}


void BattleScene::update(double i_dt)
{
  d_time += i_dt;
  d_dt = i_dt;

  if (const auto controlledObject = d_levelView.getControlledObjectView())
  {
    const auto position = controlledObject->getPosition();
    d_cameraOffset = { (int)(position.x * WorldScale), d_viewport.bottom() - (int)(position.y * WorldScale) };
  }
  
  d_gui.update(i_dt);
}

void BattleScene::render(Dx::IRenderer2d& i_renderer) const
{
  renderBackgound(i_renderer);

  i_renderer.setTranslation(d_cameraOffset - Sdk::Vector2I{ d_viewport.width2(), d_viewport.height2() });

  for (const auto& objectView : d_levelView.getObjects())
  {
    CONTRACT_ASSERT(objectView);

    Dx::Sprite sprite;

    const auto& texture = d_resourceController.getTextureResource(objectView->getTextureName());
    sprite.setTexture(texture);

    const auto position = objectView->getPosition();
    const auto size = texture.getDescription().size();
    sprite.setPosition({
      (int)(position.x * WorldScale) - size.x / 2,
      d_viewport.bottom() - (int)(position.y * WorldScale) - size.y / 2 });

    sprite.setRotation(objectView->getRotation());

    i_renderer.renderSprite(sprite);

    // Debug collisions
    if (!d_showDebug)
      continue;

    auto collisionRect = objectView->getShape();
    collisionRect.move(objectView->getPosition());
    collisionRect.p1 = collisionRect.p1 * WorldScale;
    collisionRect.p2 = collisionRect.p2 * WorldScale;
    collisionRect.p1.y = d_viewport.bottom() - collisionRect.p1.y;
    collisionRect.p2.y = d_viewport.bottom() - collisionRect.p2.y;
    i_renderer.renderRect(collisionRect, { 1, 0.9f, 0.1f, 1 });
  }

  d_gui.render(i_renderer);

  // Debug info
  if (!d_showDebug)
    return;

  i_renderer.resetTranslation();

  i_renderer.renderText("T: " + Sdk::toString(d_time, 2) +
                        "; dt: " + Sdk::toString(d_dt, 3), d_font, { 0, 0 });

  if (const auto controlledObject = d_levelView.getControlledObjectView())
  {
    const auto position = controlledObject->getPosition();
    i_renderer.renderText("x: " + Sdk::toString(position.x, 2) + "; "
                          "y: " + Sdk::toString(position.y, 2) + "\n" +
                          "V: " + Sdk::toString(controlledObject->getSpeed().length(), 2) + " m/s",
                          d_font, { 0, 20 });
  }
}

void BattleScene::renderBackgound(Dx::IRenderer2d& i_renderer) const
{
  if (!d_background)
    return;

  const auto& size = d_background->getSize();

  constexpr int SpeedMultiplier = 3;
  for (int y = -d_cameraOffset.y / SpeedMultiplier % size.y - size.y; y < d_viewport.bottom(); y += size.y)
  {
    for (int x = -d_cameraOffset.x / SpeedMultiplier % size.x - size.x; x < d_viewport.right(); x += size.x)
    {
      i_renderer.setTranslation({ -x, -y });
      i_renderer.renderSprite(*d_background);
    }
  }
}


void BattleScene::showDebug(bool i_show)
{
  d_showDebug = i_show;
}

void BattleScene::toggleDebug()
{
  showDebug(!d_showDebug);
}
