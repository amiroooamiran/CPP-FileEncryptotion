#include "file-encryption.cpp"
#include <cstring>
#include <dirent.h>
#include <iostream>
#include <string>
#include <sys/stat.h>

class DirectoryEncryptor {
private:
  PlatformGreeting platform;

  void encryptDirectory(std::string directoryPath) {
    DIR *directory;
    struct dirent *entry;
    struct stat status;
    std::string path;

    // Open the directoryPath
    if ((directory = opendir(directoryPath.c_str())) != nullptr) {
      // Loop through directory entries
      while ((entry = readdir(directory)) != nullptr) {
        // Check if this entry (file or directory) is the current directory
        // (".") or parent directory ("..")
        if (strcmp(entry->d_name, ".") != 0 &&
            strcmp(entry->d_name, "..") != 0) {
          // Get entry full path
          path = directoryPath + platform.getPathSeparator() + entry->d_name;
          // Check if this entry is a directory or a file
          if (stat(path.c_str(), &status) == 0) {
            if (S_ISDIR(status.st_mode)) {
              // This is a directory, recursively call encryptDirectory
              encryptDirectory(path);
            } else {
              // This is a file, encrypt it
              SingleFileEncryptor fileEncryptor;
              fileEncryptor.encrypt(path);
            }
          }
        }
      }
      // Close the directory
      closedir(directory);
    } else {
      std::cerr << "Error opening directory: " << directoryPath << std::endl;
    }
  }

public:
  void encrypt(std::string directoryPath) { encryptDirectory(directoryPath); }
};
