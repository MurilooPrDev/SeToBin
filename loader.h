#ifndef LOADER_H
#define LOADER_H
#include <string>

namespace STE {
    class BinaryLoader {
    public:
        bool execute_from_memory(const std::string& dll_path);
    };
}
#endif
