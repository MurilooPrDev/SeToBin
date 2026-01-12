#ifndef PE_STRUCTURES_H
#define PE_STRUCTURES_H
#include <cstdint>

struct SectionHeader {
    char name[8];
    uint32_t virtual_size;
    uint32_t virtual_address;
    uint32_t raw_data_size;
    uint32_t raw_data_ptr;
    uint32_t reloc_ptr;
    uint32_t line_numbers_ptr;
    uint16_t reloc_count;
    uint16_t line_numbers_count;
    uint32_t characteristics;
};

struct PE_OptionalHeader {
    uint16_t magic;
    uint8_t major_linker_version;
    uint8_t minor_linker_version;
    uint32_t code_size;
    uint32_t entry_point;
    uint32_t image_base;
    uint32_t section_alignment;
    uint32_t file_alignment;
};
#endif
