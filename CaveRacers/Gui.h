#pragma once

#include "Fwd.h"
#include "GaugePanel.h"

#include <Dx/LaggyDxFwd.h>


class Gui
{
public:
  Gui(Dx::IResourceController& i_resourceController,
      ILevelView& i_levelView);

  void update(double i_dt);
  void render(Dx::IRenderer2d& i_renderer) const;

private:
  GaugePanel d_gaugePanel;
};
