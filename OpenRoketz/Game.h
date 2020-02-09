#pragma once

#include "Fwd.h"

#include <Dx/LaggyDxFwd.h>
#include <Dx/MouseKey.h>


class Game
{
public:
  Game(IApp& i_app, Dx::IResourceController& i_resourceController);

  void update(double i_dt);
  void render(Dx::IRenderer2d& i_renderer) const;

  void handleKeyboard(const Dx::KeyboardState& i_keyboardState);
  void handleMouse(const Dx::MouseState& i_mouseState);

private:
  IApp& d_app;
  Dx::IResourceController& d_resourceController;

  void onMouseClick(Dx::MouseKey i_button);
  void onMouseRelease(Dx::MouseKey i_button);
  void onMouseMove();
  void onMouseWheelChange(int i_wheelChange);
};
