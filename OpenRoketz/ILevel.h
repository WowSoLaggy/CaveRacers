#pragma once

#include "ILevelModel.h"
#include "ILevelView.h"


class ILevel : public ILevelModel, public ILevelView
{
};
