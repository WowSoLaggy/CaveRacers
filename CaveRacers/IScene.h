#pragma once

#include <Dx/LaggyDxFwd.h>


class IScene
{
public:
  virtual ~IScene() = default;

  virtual void update(double i_dt) = 0;
  virtual void render(Dx::IRenderer2d& i_renderer) const = 0;

  virtual void showDebug(bool i_activate) = 0;
  virtual void toggleDebug() = 0;
};
