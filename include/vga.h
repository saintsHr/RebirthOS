#pragma once

#include <stdint.h>

#define VGA_ADDRESS 0xB8000
#define VGA_WIDTH 80
#define VGA_HEIGHT 25

#define VGA_CMD_PORT  0x3D4
#define VGA_DATA_PORT 0x3D5

#define VGA_BLACK 0x0
#define VGA_BLUE 0x1
#define VGA_GREEN 0x2
#define VGA_CYAN 0x3
#define VGA_RED 0x4
#define VGA_MAGENTA 0x5
#define VGA_BROWN 0x6
#define VGA_LGRAY 0x7
#define VGA_DGRAY 0x8
#define VGA_LBLUE 0x9
#define VGA_LGREEN 0xA
#define VGA_LCYAN 0xB
#define VGA_LRED 0xC
#define VGA_LMAGENTA 0xD
#define VGA_YELLOW 0xE
#define VGA_WHITE 0xF

extern uint16_t* const VGA_BUFFER;

void vga_putEntry(uint8_t bg, uint8_t fg, char ch, uint8_t x, uint8_t y);
void vga_print(uint8_t bg, uint8_t fg, char* str);
void vga_moveCursor(uint8_t x, uint8_t y);
void vga_getCursor(uint8_t* x, uint8_t* y);
