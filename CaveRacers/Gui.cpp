#include "stdafx.h"
#include "Gui.h"


Gui::Gui(Dx::IResourceController& i_resourceController,
         ILevelView& i_levelView)
  : d_gaugePanel(i_resourceController, i_levelView)
{
}


void Gui::update(double i_dt)
{
  d_gaugePanel.update(i_dt);
}

void Gui::render(Dx::IRenderer2d& i_renderer) const
{
  d_gaugePanel.render(i_renderer);
}
