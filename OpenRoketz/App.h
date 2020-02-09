#pragma once

#include "Game.h"
#include "IApp.h"

#include <Dx/IInputDevice.h>
#include <Dx/IRenderDevice.h>
#include <Dx/IRenderer2d.h>
#include <Dx/IResourceController.h>
#include <Sdk/Timer.h>
#include <Sdk/Window.h>


class App : public IApp
{
public:
  App();
  ~App();

  void run();
  virtual void stop() override;

private:
  std::unique_ptr<Game> d_game;

  Sdk::Timer d_timer;
  std::unique_ptr<Sdk::Window> d_window;
  std::unique_ptr<Dx::IInputDevice> d_inputDevice;
  std::unique_ptr<Dx::IRenderDevice> d_renderDevice;
  std::unique_ptr<Dx::IResourceController> d_resourceController;
  std::unique_ptr<Dx::IRenderer2d> d_renderer2d;

  bool d_continueLoop = false;
  bool getContinueLoop();
  void mainloop();
};
