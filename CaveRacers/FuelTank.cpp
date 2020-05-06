#include "stdafx.h"
#include "FuelTank.h"

#include "IFuelTankPrototype.h"


FuelTank::FuelTank(const IFuelTankPrototype& i_prototype)
  : d_prototype(i_prototype)
{
}


const IFuelTankPrototype& FuelTank::getPrototype() const
{
  return d_prototype;
}


bool FuelTank::isEmpty() const
{
  return d_fuel < 0.01;
}

double FuelTank::getFuel() const
{
  return d_fuel;
}


void FuelTank::fill()
{
  d_fuel = getPrototype().getMaxFuel();
}

void FuelTank::fill(double i_value)
{
  CONTRACT_EXPECT(i_value >= 0.0);
  d_fuel = std::min(getPrototype().getMaxFuel(), d_fuel + i_value);
}


void FuelTank::waste()
{
  d_fuel = 0;
}

void FuelTank::waste(double i_value)
{
  CONTRACT_EXPECT(i_value >= 0.0);
  d_fuel = std::max(0.0, d_fuel - i_value);
}


double FuelTank::getMass() const
{
  return getPrototype().getMassEmpty() + d_fuel;
}
