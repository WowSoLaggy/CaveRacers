#pragma once

#include "Fwd.h"
#include "IGame.h"

#include <Dx/LaggyDxFwd.h>


std::unique_ptr<IGame> createGame(IApp& i_app, Dx::IResourceController& i_resourceController);
