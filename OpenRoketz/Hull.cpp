#include "stdafx.h"
#include "Hull.h"

#include "IHullPrototype.h"


Hull::Hull(const IHullPrototype& i_prototype)
  : d_prototype(i_prototype)
{
}


const IHullPrototype& Hull::getPrototype() const
{
  return d_prototype;
}


double Hull::getArmor() const
{
  return d_armor;
}

double Hull::getMass() const
{
  return getPrototype().getMass();
}
