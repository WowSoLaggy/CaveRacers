#pragma once

#include "Fwd.h"
#include "IGame.h"
#include "ILevel.h"
#include "IScene.h"
#include "Session.h"

#include <Dx/LaggyDxFwd.h>
#include <Dx/MouseKey.h>
#include <Sdk/Vector.h>


class Game : public IGame
{
public:
  Game(IApp& i_app, Dx::IResourceController& i_resourceController);

  virtual void update(double i_dt) override;
  virtual void render(Dx::IRenderer2d& i_renderer) const override;

  virtual void handleKeyboard(const Dx::KeyboardState& i_keyboardState) override;
  virtual void handleMouse(const Dx::MouseState& i_mouseState) override;

private:
  enum class State
  {
    NotLoaded,
    Loaded,
  };

private:
  IApp& d_app;
  Dx::IResourceController& d_resourceController;

  Sdk::Vector2I d_mousePos;

  State d_state = State::NotLoaded;

  std::unique_ptr<IScene> d_scene;
  std::unique_ptr<ILevel> d_level;
  std::optional<Session> d_session;

  void loadResources();
  void startNewLevel();

  void onMouseClick(Dx::MouseKey i_button);
  void onMouseRelease(Dx::MouseKey i_button);
  void onMouseMove();
  void onMouseWheelChange(int i_wheelChange);
};
