#include "gdt_helper.h"

extern void setGDT(uint32_t GDT_address, uint32_t GDT_size);

extern uint32_t gdt_start;
extern uint32_t gdt_end;


void encodeGdtentry(uint8_t *target, struct GDT_entry source)
{
        if ((source.limit > 65536) && ((source.limit & 0xFFF) != 0xFFF))
        {
                //this is an error!
        }
        if (source.limit < 65536)
        {
                source.limit = source.limit >> 12;
                target[6] = 0xC0;
        }
        else
        {
                target[6] = 0x40;
        }

        // Encode the limit
        target[0] = source.limit & 0xFF;
        target[1] = (source.limit >> 8) & 0xFF;
        target[6] |= (source.limit >> 16) & 0xF;

        // Encode the base
        target[2] = source.base & 0xFF;
        target[3] = (source.base >> 8) & 0xFF;
        target[4] = (source.base >> 16) & 0xFF;
        target[7] = (source.base >> 24) & 0xFF;

        // And... Type
        target[5] = source.type;
}

void init_gdt()
{
        struct GDT_entry null = {.base = 0x00000000, .limit = 0x00000000, .type = 0x00};
        struct GDT_entry code = {.base = 0x04000000, .limit = 0x03FFFFFF, .type = 0x9A};
        struct GDT_entry data = {.base = 0x08000000, .limit = 0x03FFFFFF, .type = 0x92};
	
	encodeGdtentry(gdt_start, null);
	encodeGdtentry(gdt_start + (uint32_t) 8, code);
	encodeGdtentry(gdt_start + (uint32_t) 16, data);
	
	setGDT(gdt_start, gdt_end - gdt_start);	

}
