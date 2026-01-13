#ifndef EXEZECUTOR_H
#define EXEZECUTOR_H

#include <string>
#include <vector>

namespace STE {
    class EXEzecutor {
    public:
        // Executa um arquivo EXE que já existe no disco
        static void launch_from_disk(const std::string& path);
        
        // Recebe o buffer (de uma DLL/Packager), salva temporariamente e executa
        static void launch_from_memory(const std::vector<unsigned char>& buffer, const std::string& temp_name);
    };
}

#endif
