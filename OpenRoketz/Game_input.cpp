#include "stdafx.h"
#include "Game.h"

#include "IApp.h"

#include <Dx/KeyboardState.h>
#include <Dx/MouseState.h>


void Game::handleKeyboard(const Dx::KeyboardState& i_keyboardState)
{
  const auto& pressedKeys = i_keyboardState.getPressedKeys();
  const auto& currentKeys = i_keyboardState.getCurrentKeys();
  const auto& releasedKeys = i_keyboardState.getCurrentKeys();

  if (pressedKeys.Escape)
    d_app.stop();
}

void Game::handleMouse(const Dx::MouseState& i_mouseState)
{
  const auto& mousePosRaw = i_mouseState.getPosition();
  if (i_mouseState.getMode() == Dx::MouseMode::Absolute)
  {
    //if (mousePosRaw != d_gui.getCursor().getPosition())
    {
      //d_gui.getCursor().setPosition(mousePosRaw);
      onMouseMove();
    }
  }
  else
  {
    if (mousePosRaw != Sdk::Vector2I{ 0, 0 })
    {
      //d_gui.getCursor().movePosition(mousePosRaw);
      onMouseMove();
    }
  }

  if (int wheelChange = i_mouseState.getWheelPositionChange(); wheelChange != 0)
    onMouseWheelChange(wheelChange > 0 ? +1 : -1);

  if (i_mouseState.getLeftButtonState() == Dx::ButtonState::Pressed)
    onMouseClick(Dx::MouseKey::Left);
  else if (i_mouseState.getLeftButtonState() == Dx::ButtonState::Released)
    onMouseRelease(Dx::MouseKey::Left);

  if (i_mouseState.getRightButtonState() == Dx::ButtonState::Pressed)
    onMouseClick(Dx::MouseKey::Right);
  else if (i_mouseState.getRightButtonState() == Dx::ButtonState::Released)
    onMouseRelease(Dx::MouseKey::Right);
}


void Game::onMouseClick(Dx::MouseKey i_button)
{
}

void Game::onMouseRelease(Dx::MouseKey i_button)
{
}

void Game::onMouseMove()
{
}

void Game::onMouseWheelChange(int i_wheelChange)
{
}
