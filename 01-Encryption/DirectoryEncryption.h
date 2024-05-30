#ifndef DIRECTORYENCRYPTION_H
#define DIRECTORYENCRYPTION_H

#include "PlatformGreeting.h"
#include "FileEncryption.h"
#include <string>

class DirectoryEncryptor {
private:
  PlatformGreeting platform;

  void encryptDirectory(const std::string &directoryPath);

public:
  void encrypt(const std::string &directoryPath);
};

#endif // DIRECTORYENCRYPTION_H
