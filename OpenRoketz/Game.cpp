#include "stdafx.h"
#include "Game.h"

#include "IApp.h"
#include "SettingsProvider.h"

#include <Dx/IRenderer2d.h>
#include <Dx/IResourceController.h>


Game::Game(IApp& i_app, Dx::IResourceController& i_resourceController)
  : d_app(i_app)
  , d_resourceController(i_resourceController)
{
}


void Game::update(double i_dt)
{
}

void Game::render(Dx::IRenderer2d& i_renderer) const
{
}
