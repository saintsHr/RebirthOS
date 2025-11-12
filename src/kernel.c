#include "vga.h"

void kmain(void){
    vga_print(VGA_BLACK, VGA_LGRAY, "Hello, World!", 10, 10);
}