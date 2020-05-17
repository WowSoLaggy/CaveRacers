#pragma once

#include "Fwd.h"

#include <Dx/AnimatedSprite.h>
#include <Dx/LaggyDxFwd.h>
#include <Sdk/EventHandler.h>


class GaugePanel : public Sdk::EventHandler
{
public:
  GaugePanel(Dx::IResourceController& i_resourceController,
             ILevelView& i_levelView);

  virtual void processEvent(const Sdk::IEvent& i_event) override;

  void update(double i_dt);
  void render(Dx::IRenderer2d& i_renderer) const;

private:
  Dx::AnimatedSprite d_sprite;
  std::shared_ptr<Rocket> d_controlledRocket;
};
