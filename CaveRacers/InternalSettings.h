#pragma once

#include <string>


struct InternalSettings
{
  std::string applicationName;

  fs::path dataFolder;
  fs::path assetsFolder;
  fs::path configFolder;
  fs::path savesFolder;

  fs::path componentPrototypesFile;

  std::string defaultFontName;
};
