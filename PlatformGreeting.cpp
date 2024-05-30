#include "PlatformGreeting.h"
#include <cstdlib>

std::string PlatformGreeting::getPathSeparator() const {
#ifdef _WIN32
  return "\\";
#else
  return "/";
#endif
}

std::string PlatformGreeting::getHomeDirectory() const {
  const char *homedir;

#ifdef _WIN32
  homedir = getenv("USERPROFILE");
#else
  homedir = getenv("HOME");
#endif

  if (homedir == nullptr) {
    homedir = ".";
  }

  return std::string(homedir);
}
