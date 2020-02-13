#pragma once


class IPrototype
{
public:
  virtual ~IPrototype() = default;

  virtual const std::string& getName() const = 0;
};
