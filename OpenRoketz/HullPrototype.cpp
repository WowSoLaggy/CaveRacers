#include "stdafx.h"
#include "HullPrototype.h"


const std::string& HullPrototype::getName() const
{
  return d_name;
}

double HullPrototype::getMaxArmor() const
{
  return d_maxArmor;
}

double HullPrototype::getMass() const
{
  return d_mass;
}


void HullPrototype::setName(std::string i_name)
{
  d_name = std::move(i_name);
}

void HullPrototype::setMaxArmor(double i_maxArmor)
{
  d_maxArmor = i_maxArmor;
}

void HullPrototype::setMass(double i_mass)
{
  d_mass = i_mass;
}
