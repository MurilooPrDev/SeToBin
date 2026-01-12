#ifndef PACKAGER_H
#define PACKAGER_H
#include <string>

namespace STE {
    class Packager {
    public:
        void create_tar(const std::string& path);
    };
}
#endif
