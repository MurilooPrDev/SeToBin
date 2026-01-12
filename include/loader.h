#ifndef LOADER_H
#define LOADER_H

#include <string>

namespace STE {
    class BinaryLoader {
    public:
        void setup_environment();
        void persist(const std::string& source);
        void list_saved_files();
        bool execute_from_memory(const std::string& dll_path);
    };
}
#endif
