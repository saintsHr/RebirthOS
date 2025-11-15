#include "vga.h"
#include "io.h"

uint16_t* const VGA_BUFFER = (uint16_t*)VGA_ADDRESS;

void vga_putEntry(uint8_t bg, uint8_t fg, char ch, uint8_t x, uint8_t y){
    uint16_t value = ((bg | fg) << 8) | ch;
    VGA_BUFFER[(y * VGA_WIDTH) + x] = value;
}

void vga_moveCursor(uint8_t x, uint8_t y){
    if (x > VGA_WIDTH) return;
    if (y > VGA_HEIGHT) return;

    uint16_t pos = y * VGA_WIDTH + x;
    outb(VGA_CMD_PORT, 0x0F);
    outb(VGA_DATA_PORT, (uint8_t)(pos & 0xFF));
    outb(VGA_CMD_PORT, 0x0E);
    outb(VGA_DATA_PORT, (uint8_t)((pos >> 8) & 0xFF));
}

void vga_getCursor(uint8_t* x, uint8_t* y){
    uint16_t pos = 0;

    outb(VGA_CMD_PORT, 0x0F);
    pos |= inb(VGA_DATA_PORT);
    outb(VGA_CMD_PORT, 0x0E);
    pos |= ((uint8_t)inb(VGA_DATA_PORT)) << 8;

    *y = pos / VGA_WIDTH;
    *x = pos % VGA_WIDTH;
}

void vga_clearScreen(){
    uint16_t* vram = (uint16_t*)0xB8000;
    uint16_t empty = (VGA_BLACK << 12) | (VGA_BLACK << 8) | ' ';

    for (int i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++) {
        vram[i] = empty;
    }
}

void vga_print(uint8_t bg, uint8_t fg, char* str){
    uint8_t x, y;
    vga_getCursor(&x, &y);

    for (uint16_t i = 0; str[i] != '\0'; i++){
        if (str[i] == '\n'){
            x = 0;
            y++;
            vga_moveCursor(x, y);
        }

        if (x >= VGA_WIDTH){
            x = 0;
            y++;
            vga_moveCursor(x, y);
        }

        vga_putEntry(bg, fg, str[i], x, y);
        x++;
        vga_moveCursor(x, y);
    }
}
