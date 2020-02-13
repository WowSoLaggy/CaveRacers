#include "stdafx.h"
#include "CreateGame.h"

#include "Game.h"


std::unique_ptr<IGame> createGame(IApp& i_app, Dx::IResourceController& i_resourceController)
{
  return std::make_unique<Game>(i_app, i_resourceController);
}
