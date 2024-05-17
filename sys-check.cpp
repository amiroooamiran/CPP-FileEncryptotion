// PlatformGreeting class to determine platform-specific path separator
#include <iostream>

class PlatformGreeting {
public:
  std::string getPathSeparator() {
#ifdef _WIN32
    return "\\";
#else
    return "/";
#endif
  }
};
