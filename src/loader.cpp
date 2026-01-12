#include "../include/loader.h"
#include "../include/pe_structures.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <sys/stat.h>
#include <dirent.h>
#include <iomanip>
#include <cstdlib>

namespace STE {
    void BinaryLoader::setup_environment() { mkdir("All", 0777); }
    void BinaryLoader::persist(const std::string& s) {}
    void BinaryLoader::list_saved_files() {
        DIR *dir; struct dirent *ent;
        std::cout << "\n--- [ SeToElf STORED BINARIES ] ---" << std::endl;
        if ((dir = opendir("All")) != NULL) {
            while ((ent = readdir(dir)) != NULL) {
                if (ent->d_name[0] != '.') std::cout << " > " << ent->d_name << std::endl;
            }
            closedir(dir);
        }
    }

    std::string read_string(const std::vector<unsigned char>& buf, uint32_t& ip) {
        std::string s = "";
        while (ip < buf.size() && buf[ip] != 0x00) { s += (char)buf[ip++]; }
        ip++; return s;
    }

    bool BinaryLoader::execute_from_memory(const std::string& dll_path) {
        setup_environment();
        list_saved_files();

        std::ifstream file(dll_path, std::ios::binary | std::ios::ate);
        if (!file.is_open()) return false;
        size_t size = file.tellg();
        file.seekg(0, std::ios::beg);
        std::vector<unsigned char> buffer(size);
        file.read((char*)buffer.data(), size);

        uint32_t ip = 0;
        // Detecta cabeçalho PE e pula pro EntryPoint
        if (size > 0x40 && buffer[0] == 'M' && buffer[1] == 'Z') {
            uint32_t pe_ptr; memcpy(&pe_ptr, &buffer[0x3C], 4);
            memcpy(&ip, &buffer[pe_ptr + 0x28], 4);
            std::cout << "[STE] Salto para EntryPoint: 0x" << std::hex << ip << std::dec << std::endl;
        }

        while (ip < size) {
            unsigned char opcode = buffer[ip++];

            if (opcode == 0x00) continue; // Pula zeros sem avisar

            switch(opcode) {
                case 0x10: { // Criar Pasta
                    std::string d = read_string(buffer, ip);
                    mkdir(d.c_str(), 0777);
                    std::cout << "\033[1;32m[OK]\033[0m Pasta Criada: " << d << std::endl;
                    break;
                }
                case 0x11: { // Criar Arquivo
                    std::string p = read_string(buffer, ip);
                    std::string c = read_string(buffer, ip);
                    std::ofstream f(p); f << c; f.close();
                    std::cout << "\033[1;32m[OK]\033[0m Arquivo Escrito: " << p << std::endl;
                    break;
                }
                case 0x12: { // Executar Comando do Sistema (Novo!)
                    std::string cmd = read_string(buffer, ip);
                    std::cout << "\033[1;34m[RUN]\033[0m Executando: " << cmd << std::endl;
                    system(cmd.c_str());
                    break;
                }
                default:
                    // Se for texto visível, imprime
                    if (opcode >= 32 && opcode <= 126) std::cout << (char)opcode;
                    break;
            }
        }
        std::cout << "\n[STE] Missao Cumprida." << std::endl;
        return true;
    }
}
