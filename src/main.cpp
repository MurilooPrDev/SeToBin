#include <iostream>
#include <string>
#include "../include/loader.h"
#include "../include/packager.h"

void show_banner() {
    std::cout << "  ____ _____ _____" << std::endl;
    std::cout << " / ___|_   _| ____|" << std::endl;
    std::cout << " \\___ \\ | | |  _|" << std::endl;
    std::cout << "  ___) || | | |___" << std::endl;
    std::cout << " |____/ |_| |_____|" << std::endl;
    std::cout << " [ SeToElf v1.0.1 - Emulator Mode ]" << std::endl;
    std::cout << "---------------------------" << std::endl;
}

int main(int argc, char* argv[]) {
    show_banner();

    if (argc < 3) {
        std::cout << "Usage: STE [option] [file]" << std::endl;
        std::cout << "Options: -exc (Emulate), --pack (Compress)" << std::endl;
        return 1;
    }

    std::string option = argv[1];
    std::string path = argv[2];

    if (option == "-exc") {
        STE::BinaryLoader loader;
        loader.execute_from_memory(path);
    } else if (option == "--pack") {
        STE::Packager packager;
        packager.compress_dll(path);
    }

    return 0;
}
