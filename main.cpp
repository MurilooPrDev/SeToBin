#include <iostream>
#include <string>
#include "../include/loader.h"
#include "../include/packager.h"

void print_banner() {
    std::cout << "  ____ _____ _____ " << std::endl;
    std::cout << " / ___|_   _| ____|" << std::endl;
    std::cout << " \\___ \\ | | |  _|  " << std::endl;
    std::cout << "  ___) || | | |___ " << std::endl;
    std::cout << " |____/ |_| |_____|" << std::endl;
    std::cout << " [ SeToElf Binary Loader ]" << std::endl;
    std::cout << "---------------------------" << std::endl;
}

int main(int argc, char* argv[]) {
    print_banner();

    if (argc < 3) {
        std::cout << "Usage:" << std::endl;
        std::cout << "  ./STE -exc <file.dll>   (Execute DLL)" << std::endl;
        std::cout << "  ./STE --pack <file.dll>  (Pack to tar.gz)" << std::endl;
        return 1;
    }

    std::string option = argv[1];
    std::string target = argv[2];

    if (option == "-exc") {
        STE::BinaryLoader loader;
        if(loader.execute_from_memory(target)) {
            std::cout << "[INFO] Sequence Complete." << std::endl;
        }
    } 
    else if (option == "--pack") {
        STE::Packager pkg;
        pkg.create_tar(target);
    } 
    else {
        std::cerr << "[!] Invalid option: " << option << std::endl;
    }

    return 0;
}
