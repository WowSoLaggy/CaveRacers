#pragma once


class IRocketControl
{
public:
  virtual ~IRocketControl() = default;

  virtual void thrust() = 0;
  virtual void turnLeft() = 0;
  virtual void turnRight() = 0;

  virtual void fire() = 0;
  virtual void changeWeapon() = 0;
};
