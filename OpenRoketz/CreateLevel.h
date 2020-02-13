#pragma once

#include "Fwd.h"
#include "ILevel.h"


std::unique_ptr<ILevel> createDefaultLevel(const ISession& i_session);
