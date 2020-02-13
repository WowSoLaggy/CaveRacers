#pragma once

#include "IRocketControl.h"
#include "ISceneObject.h"


class IRocket : public ISceneObject, public IRocketControl
{
};
