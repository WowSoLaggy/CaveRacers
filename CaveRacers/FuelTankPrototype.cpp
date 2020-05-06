#include "stdafx.h"
#include "FuelTankPrototype.h"


const std::string& FuelTankPrototype::getName() const
{
  return d_name;
}

double FuelTankPrototype::getMaxFuel() const
{
  return d_maxFuel;
}

double FuelTankPrototype::getMassEmpty() const
{
  return d_massEmpty;
}


void FuelTankPrototype::setName(std::string i_name)
{
  d_name = std::move(i_name);
}

void FuelTankPrototype::setMaxFuel(double i_maxFuel)
{
  d_maxFuel = i_maxFuel;
}

void FuelTankPrototype::setMassEmpty(double i_massEmpty)
{
  d_massEmpty = i_massEmpty;
}
