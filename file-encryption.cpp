#include <dirent.h>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>
#include <sys/stat.h>

// this function will encryption SIngle file
void encryptiFile(std::string filePath) {
  // File is the file will be encryption
  // tempFile is temprary file wich save encrypted data
  std::fstream file, tempFile;
  std::string tempFilePath = "temp.txt";

  // open file streams
  //  Openfile to read, temp file to write
  file.open(filePath, std::ios::in);
  tempFile.open(tempFilePath, std::ios::out);

  // Read byte by byte through file
  char byte;
  while (file >> std::noskipws >> byte) {
    // Encrypt the byte by add 1 to it
    byte += 1;
    // Save tis byte into temp filePath
    tempFile << byte;
  }

  // close file streams
  file.close();
  tempFile.close();

  // open file streams
  // But this time we will open file to write and temp file to Read
  file.open(filePath, std::ios::in);
  tempFile.open(tempFilePath, std::ios::in);

  // Read through temp file byte byte by byte
  while (tempFile >> std::noskipws >> byte) {
    // Save this byte into filePath
    file << byte;
  }

  // close file streams
  file.close();
  tempFile.close();

  // Delete temp file
  remove(tempFilePath.c_str());
}
