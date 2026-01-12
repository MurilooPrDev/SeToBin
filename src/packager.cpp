#include "../include/packager.h"
#include <iostream>
#include <string>
#include <cstdlib>

namespace STE {
    void Packager::compress_dll(const std::string& path) {
        std::cout << "[STE] Compressing " << path << "..." << std::endl;
        std::string command = "tar -czf " + path + ".tar.gz " + path;
        int result = std::system(command.c_str());
        if (result == 0) {
            std::cout << "[SUCCESS] Generated: " << path << ".tar.gz" << std::endl;
        } else {
            std::cout << "[ERROR] Compression failed." << std::endl;
        }
    }
}
