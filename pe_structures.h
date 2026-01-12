#ifndef PE_STRUCTURES_H
#define PE_STRUCTURES_H
#include <cstdint>

namespace STE {
    // Cabeçalho DOS (O começo de toda DLL)
    struct DOSHeader {
        uint16_t e_magic;    // Deve ser 'MZ'
        uint16_t dummy[29];  // Espaço reservado
        uint32_t e_lfanew;   // Ponteiro para o cabeçalho PE (NT)
    };

    // Estrutura simplificada para achar o EntryPoint
    struct NTHeader {
        uint32_t Signature;  // Deve ser 'PE\0\0'
        uint16_t Machine;
        uint16_t NumberOfSections;
        uint32_t TimeDateStamp;
        uint8_t  unused[16];
        uint32_t AddressOfEntryPoint; // Onde o código começa!
    };
}
#endif
