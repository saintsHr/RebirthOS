#include "vga.h"

uint16_t* const VGA_BUFFER = (uint16_t*)VGA_ADDRESS;

void vga_putEntry(uint8_t bg, uint8_t fg, char ch, uint8_t x, uint8_t y){
    uint16_t value = ((bg | fg) << 8) | ch;
    VGA_BUFFER[(y * VGA_WIDTH) + x] = value;
}

void vga_print(uint8_t bg, uint8_t fg, char* str, uint8_t x, uint8_t y){
    for (uint16_t i = 0; i < 60000; i++){
        if (str[i] == '\0') break;
        vga_putEntry(bg, fg, str[i], x + i, y);
    }
}