#ifndef FILEENCRYPTION_H
#define FILEENCRYPTION_H

#include <string>

class FileEncryptor {
private:
  std::string key = "amiran123"; // Default encryption key

  // Function to perform XOR encryption
  void xorEncrypt(std::string &data, const std::string &key);

  // Function to encrypt a file and change its extension
  void encryptFile(const std::string &filePath);

public:
  void encrypt(const std::string &filePath);
};

#endif // FILEENCRYPTION_H