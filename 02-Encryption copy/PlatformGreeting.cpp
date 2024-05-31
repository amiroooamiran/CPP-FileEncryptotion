#include "PlatformGreeting.h"
#include <cstdlib>

std::string PlatformGreeting::getPathSeparator() const {
  return "\\";
}

std::string PlatformGreeting::getHomeDirectory() const {
  const char *homedir = getenv("USERPROFILE");
  if (homedir == nullptr) {
    homedir = ".";
  }
  return std::string(homedir);
}
