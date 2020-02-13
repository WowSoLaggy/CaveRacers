#pragma once

#include <Dx/LaggyDxFwd.h>


class IGame
{
public:
  virtual ~IGame() = default;

  virtual void update(double i_dt) = 0;
  virtual void render(Dx::IRenderer2d& i_renderer) const = 0;

  virtual void handleKeyboard(const Dx::KeyboardState& i_keyboardState) = 0;
  virtual void handleMouse(const Dx::MouseState& i_mouseState) = 0;
};
