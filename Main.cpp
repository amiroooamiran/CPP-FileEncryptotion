#include "directory-encryption.cpp"
#include <cstring>
#include <dirent.h>
#include <string>
#include <sys/stat.h>

int main() {
  DirectoryEncryptor directoryEncryptor;
  // Encryption directory
  directoryEncryptor.encrypt("/home/Au5t1n/Desktop/file_encryption/datas/");
  return 0;
}
