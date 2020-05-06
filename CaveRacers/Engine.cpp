#include "stdafx.h"
#include "Engine.h"

#include "IEnginePrototype.h"


Engine::Engine(const IEnginePrototype& i_prototype)
  : d_prototype(i_prototype)
{
}


const IEnginePrototype& Engine::getPrototype() const
{
  return d_prototype;
}


double Engine::getMass() const
{
  return d_prototype.getMass();
}
