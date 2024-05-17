// PlatformGreeting class to determine platform-specific path separator
#ifndef PLATFORM_GREETING_H
#define PLATFORM_GREETING_H

#include <cstdlib>
#include <iostream>

// PlatformGreeting class to determine platform-specific details
class PlatformGreeting {
public:
  // Returns the path separator based on the operating system
  std::string getPathSeparator() {
#ifdef _WIN32
    // Return backslash for Windows
    return "\\";
#else
    // Return forward slash for Unix-like systems (Linux, macOS, etc.)
    return "/";
#endif
  }

  // Returns the home directory of the current user
  std::string getHomeDirectory() {
#ifdef _WIN32
    // On Windows, use the USERPROFILE environment variable
    const char *homeDir = getenv("USERPROFILE");
    if (homeDir == nullptr) {
      std::cerr << "Error getting home directory" << std::endl;
      exit(1);
    }
#else
    // On Unix-like systems, use the HOME environment variable
    const char *homeDir = getenv("HOME");
    if (homeDir == nullptr) {
      std::cerr << "Error getting home directory" << std::endl;
      exit(1);
    }
#endif
    // Return the home directory as a string
    return std::string(homeDir);
  }
};

#endif // PLATFORM_GREETING_H
