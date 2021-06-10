#include <stdint.h>

// from osdev GDT tutorial


struct GDT_entry
{
	uint32_t base;
	uint32_t limit;
	uint8_t type;
};

void encodeGdtentry(uint8_t *target, struct GDT_entry source);

void init_gdt();

