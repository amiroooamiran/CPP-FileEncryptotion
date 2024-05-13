#include <cstddef>
#include <cstring>
#include <dirent.h>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>
#include <sys/stat.h>

// this function will encryption SIngle file
void encryptiFile(std::string filePath) {
  std::fstream file, tempFile;
  std::string tempFilePath = "temp.txt";

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
  file.open(filePath, std::ios::out); // Change mode to out to overwrite the original file
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


// This function will read through all directores and files in directory
// if it find a file, it will encrypt that filePath
// if it find a directory, it will through that directory
void encryptDirectory(std::string directoryPath) {
  DIR *directory;
  struct dirent *entry;
  struct stat status;
  std::string path;

  // Open the directoryPath
  if ((directory = opendir(directoryPath.c_str())) != nullptr) {
    // Loop through directory entries
    while ((entry = readdir(directory)) != nullptr) {
      // Check if this entry (file or directory) is the current directory (".") or parent directory ("..")
      if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
        // Get entry full path
        path = directoryPath + "/" + entry->d_name;
        // Check if this entry is a directory or a file
        if (stat(path.c_str(), &status) == 0) {
          if (S_ISDIR(status.st_mode)) {
            // This is a directory, recursively call encryptDirectory
            encryptDirectory(path);
          } else {
            // This is a file, encrypt it
            encryptiFile(path);
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


int main() {
  // Encryption directory
  encryptDirectory("/home/Au5t1n/Desktop/file_encryption/datas/");
  return 0;
}
