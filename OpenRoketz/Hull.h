#pragma once

#include "IHull.h"


class Hull : public IHull
{
public:
  Hull(const IHullPrototype& i_prototype);

  virtual const IHullPrototype& getPrototype() const override;

  virtual double getArmor() const override;
  virtual double getMass() const override;

private:
  const IHullPrototype& d_prototype;
  double d_armor = 0.0;
};
