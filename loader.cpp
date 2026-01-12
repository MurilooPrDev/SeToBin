#include "../include/loader.h"
#include "../include/pe_structures.h"
#include <iostream>
#include <fstream>
#include <sys/mman.h>
#include <cstring>

namespace STE {
    bool BinaryLoader::execute_from_memory(const std::string& dll_path) {
        std::ifstream file(dll_path, std::ios::binary | std::ios::ate);
        if (!file.is_open()) {
            return false;
        }

        std::streamsize size = file.tellg();
        file.seekg(0, std::ios::beg);

        void* exec_addr = mmap(NULL, size, PROT_READ | PROT_WRITE | PROT_EXEC, 
                               MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

        if (exec_addr == MAP_FAILED) return false;

        file.read(static_cast<char*>(exec_addr), size);
        unsigned char* raw = static_cast<unsigned char*>(exec_addr);

        // Header Swap: Windows MZ to Linux ELF
        raw[0] = 0x7F; raw[1] = 0x45; raw[2] = 0x4C; raw[3] = 0x46; 

        std::cout << "[STE] Headers swapped. Memory mapped at: " << exec_addr << std::endl;
        return true;
    }
}
