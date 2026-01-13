#include "../include/EXEzecutor.h"
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <cstdlib>

namespace STE {

    void EXEzecutor::launch_from_disk(const std::string& path) {
        std::cout << "\033[1;36m[STE_EXE]\033[0m Preparando execucao: " << path << std::endl;

        // 1. Tenta dar permissão de execução (+x) ao arquivo
        if (chmod(path.c_str(), S_IRWXU | S_IRWXG | S_IRWXO) != 0) {
            std::cerr << "\033[1;31m[ERRO]\033[0m Falha ao definir permissoes no binario." << std::endl;
            return;
        }

        // 2. Monta o comando. Usamos "./" para garantir que o shell execute o binario local
        std::string cmd = "./" + path;
        
        std::cout << "\033[1;32m[STE_START]\033[0m --- Inicio da Saida do EXE ---" << std::endl;
        
        // 3. Executa no terminal
        int exit_code = std::system(cmd.c_str());
        
        std::cout << "\033[1;32m[STE_END]\033[0m --- Fim da Saida (Exit Code: " << exit_code << ") ---" << std::endl;
    }

    void EXEzecutor::launch_from_memory(const std::vector<unsigned char>& buffer, const std::string& temp_name) {
        // Se o EXE estiver dentro de um pacote do SeToElf, primeiro extraímos para um arquivo oculto
        std::string internal_path = "Bin/." + temp_name;
        
        std::ofstream outfile(internal_path, std::ios::binary);
        if (!outfile) {
            std::cerr << "[ERRO] Nao foi possivel extrair o EXE para execucao." << std::endl;
            return;
        }
        
        outfile.write(reinterpret_cast<const char*>(buffer.data()), buffer.size());
        outfile.close();

        // Agora executa o que foi extraído
        launch_from_disk(internal_path);
        
        // Opcional: remover após executar para não deixar rastros
        // std::remove(internal_path.c_str());
    }
}
