#include "stdafx.h"
#include "Session.h"


const std::string& Session::getPlayerName() const
{
  return d_playerName;
}


const std::string& Session::getFuelTankName() const
{
  return d_fuelTankName;
}

const std::string& Session::getEngineName() const
{
  return d_engineName;
}

const std::string& Session::getHullName() const
{
  return d_hullName;
}


void Session::setPlayerName(std::string i_name)
{
  d_playerName = std::move(i_name);
}

void Session::setFuelTankName(std::string i_name)
{
  d_fuelTankName = std::move(i_name);
}

void Session::setEngineName(std::string i_name)
{
  d_engineName = std::move(i_name);
}

void Session::setHullName(std::string i_name)
{
  d_hullName = std::move(i_name);
}
