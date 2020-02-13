#include "stdafx.h"
#include "Game.h"

#include "CreateLevel.h"
#include "CreateScene.h"
#include "IApp.h"
#include "IPrototypeCollection.h"
#include "SettingsProvider.h"

#include <Dx/IRenderer2d.h>
#include <Dx/IResourceController.h>


Game::Game(IApp& i_app, Dx::IResourceController& i_resourceController)
  : d_app(i_app)
  , d_resourceController(i_resourceController)
  , d_state(State::NotLoaded)
{
}


void Game::update(double i_dt)
{
  if (d_state == State::NotLoaded)
  {
    loadResources();
    startNewLevel();
    d_state = State::Loaded;
  }

  CONTRACT_ASSERT(d_level);
  d_level->update(i_dt);

  CONTRACT_ASSERT(d_scene);
  d_scene->update(i_dt);
}

void Game::render(Dx::IRenderer2d& i_renderer) const
{
  if (d_scene)
    d_scene->render(i_renderer);
}


void Game::loadResources()
{
  IPrototypeCollection::load();
  d_resourceController.loadResources();
}

void Game::startNewLevel()
{
  Session session;
  session.setPlayerName("Laggy");
  session.setFuelTankName("Default");
  session.setEngineName("Default");
  session.setHullName("Default");
  d_session = std::move(session);

  d_level = createDefaultLevel(*d_session);

  const Sdk::RectI viewport{
    0, SettingsProvider::getDefaultExternalSettings().clientWidth,
    0, SettingsProvider::getDefaultExternalSettings().clientHeight };
  d_scene = createBattleScene(*d_level, d_resourceController, viewport);
}
