#pragma once


class IRocketControl
{
public:
  virtual ~IRocketControl() = default;

  virtual void thrust(bool i_on) = 0;
  virtual void turnLeft(bool i_on) = 0;
  virtual void turnRight(bool i_on) = 0;

  virtual void fire1() = 0;

  virtual void refill() = 0;
};
