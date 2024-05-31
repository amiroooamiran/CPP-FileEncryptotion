#ifndef PLATFORMGREETING_H
#define PLATFORMGREETING_H

#include <string>

class PlatformGreeting {
public:
  std::string getPathSeparator() const;
  std::string getHomeDirectory() const;
};

#endif // PLATFORMGREETING_H