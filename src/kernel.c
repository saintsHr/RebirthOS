#include "vga.h"
#include "util.h"

void kmain(void){
    unsigned long long i = 0;

    vga_moveCursor(39, 12);

    while(1){
        vga_print(VGA_BLACK, VGA_LGRAY, util_intToStr(i));
        util_wait(1000);
        vga_clearScreen();
        i++;
        vga_moveCursor(39, 12);
    }
}