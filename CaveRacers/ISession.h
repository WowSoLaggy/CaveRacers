#pragma once


class ISession
{
public:
  virtual ~ISession() = default;

  virtual const std::string& getPlayerName() const = 0;

  virtual const std::string& getFuelTankName() const = 0;
  virtual const std::string& getEngineName() const = 0;
  virtual const std::string& getHullName() const = 0;
};
