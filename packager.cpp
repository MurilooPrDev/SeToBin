#include "../include/packager.h"
#include <iostream>
#include <cstdlib>

namespace STE {
    void Packager::create_tar(const std::string& path) {
        std::cout << "[STE] Compressing " << path << "..." << std::endl;
        std::string cmd = "tar -czvf " + path + ".tar.gz " + path;
        
        if (std::system(cmd.c_str()) == 0) {
            std::cout << "[SUCCESS] Generated: " << path << ".tar.gz" << std::endl;
        } else {
            std::cerr << "[ERROR] Tar command failed." << std::endl;
        }
    }
}
