#include "stdafx.h"
#include "EnginePrototype.h"


const std::string& EnginePrototype::getName() const
{
  return d_name;
}

double EnginePrototype::getPower() const
{
  return d_power;
}

double EnginePrototype::getConsumption() const
{
  return d_consumption;
}

double EnginePrototype::getMass() const
{
  return d_mass;
}


void EnginePrototype::setName(std::string i_name)
{
  d_name = std::move(i_name);
}

void EnginePrototype::setPower(double i_power)
{
  d_power = i_power;
}

void EnginePrototype::setConsumption(double i_consumption)
{
  d_consumption = i_consumption;
}

void EnginePrototype::setMass(double i_mass)
{
  d_mass = i_mass;
}
