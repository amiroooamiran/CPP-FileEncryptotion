#include "DirectoryEncryption.h"
#include <iostream>
#include <string>

int main() {
  PlatformGreeting platformGreeting;
  DirectoryEncryptor directoryEncryptor;

  // Get the home directory
  std::string homeDirectory = platformGreeting.getHomeDirectory();

  // Construct the path to the encryption directory on the desktop
  std::string pathSeparator = platformGreeting.getPathSeparator();
  std::string encryptionDirectory = homeDirectory + pathSeparator + "Desktop" +
                                    pathSeparator + "datas";
  // Encrypt the directory
  directoryEncryptor.encrypt(encryptionDirectory);

  std::cout << "Encryption completed successfully." << std::endl;

  return 0;
}