#ifndef _KERNEL_KEYBOARD_H
#define _KERNEL_KEYBOARD_H
void set_key(unsigned char key);
unsigned char get_key();
void init_keyboard();
extern int end, current;
extern unsigned char key_buffer[256];
extern unsigned char key;

#endif
