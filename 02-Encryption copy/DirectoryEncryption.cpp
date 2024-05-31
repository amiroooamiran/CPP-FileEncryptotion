#include "DirectoryEncryption.h"
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

void DirectoryEncryptor::encryptDirectory(const std::string &directoryPath) {
  for (const auto &entry : fs::directory_iterator(directoryPath)) {
    if (entry.is_directory()) {
      encryptDirectory(entry.path().string());
    } else if (entry.is_regular_file()) {
      FileEncryptor fileEncryptor;
      fileEncryptor.encrypt(entry.path().string());
    }
  }
}

void DirectoryEncryptor::encrypt(const std::string &directoryPath) {
  encryptDirectory(directoryPath);
}
