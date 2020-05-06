#include "stdafx.h"
#include "IPrototypeCollection.h"

#include "PrototypeCollection.h"


namespace
{
  IPrototypeCollection& getInternal()
  {
    static PrototypeCollection prototypeCollection;
    return prototypeCollection;
  }

} // anonymous NS


const IPrototypeCollection& IPrototypeCollection::get()
{
  return getInternal();
}

void IPrototypeCollection::load()
{
  getInternal().loadInternal();
}
