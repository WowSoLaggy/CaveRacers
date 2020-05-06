#include "stdafx.h"
#include "GaugePanel.h"

#include "ILevelView.h"
#include "IRocket.h"
#include "LevelEvents.h"

#include <Dx/IRenderer2d.h>
#include <Dx/IResourceController.h>


namespace
{
  const std::string TextureName = "GaugePanel.png";
} // anonymous NS


GaugePanel::GaugePanel(Dx::IResourceController& i_resourceController,
                       ILevelView& i_levelView)
{
  d_sprite.setTexture(&i_resourceController.getTextureResource(TextureName));
  d_sprite.setPosition({ 10, 10 });

  connectTo(i_levelView);
  d_controlledRocket = std::dynamic_pointer_cast<IRocket>(i_levelView.getControlledObjectView());
}


void GaugePanel::processEvent(const Sdk::IEvent& i_event)
{
  if (const auto& onControlledObjectChange = dynamic_cast<const OnControlledObjectChange*>(&i_event))
  {
    d_controlledRocket = onControlledObjectChange->getControlledRocket();
  }
}


void GaugePanel::update(double i_dt)
{
  if (!d_controlledRocket)
  {
    d_sprite.setFrame(0);
    return;
  }

  const int frame = (int)(d_controlledRocket->getFuelPercentage() * 10);
  d_sprite.setFrame(frame);
}

void GaugePanel::render(Dx::IRenderer2d& i_renderer) const
{
  i_renderer.resetTranslation();
  i_renderer.renderSprite(d_sprite);
}
