#pragma once

#include "ISession.h"


class Session : public ISession
{
public:
  virtual const std::string& getPlayerName() const override;

  virtual const std::string& getFuelTankName() const override;
  virtual const std::string& getEngineName() const override;
  virtual const std::string& getHullName() const override;

  void setPlayerName(std::string i_name);
  void setFuelTankName(std::string i_name);
  void setEngineName(std::string i_name);
  void setHullName(std::string i_name);

private:
  std::string d_playerName;

  std::string d_fuelTankName;
  std::string d_engineName;
  std::string d_hullName;
};
