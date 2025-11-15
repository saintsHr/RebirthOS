#include "vga.h"
#include "multiboot.h"
#include "util.h"

void kernel_panic(char* msg){
    vga_clear(VGA_BLACK, VGA_BLACK);
    vga_moveCursor(32, 7);
    vga_print(VGA_BLACK, VGA_RED, "KERNEL PANIC!");
    vga_moveCursor(0, 13);
    vga_print(VGA_BLACK, VGA_LGRAY, "Message:");
    vga_moveCursor(0, 15);
    vga_print(VGA_BLACK, VGA_LGRAY, msg);
    asm volatile("cli; hlt");
}

void kmain(unsigned long magic, unsigned long addr){
    // checks for correct magic number
    if (magic != 0x2BADB002){
        kernel_panic("Invalid magic number provided");
    }

    // gets multiboot info
    multiboot_info_t* mb = (multiboot_info_t*) addr;

    // checks for memory info
    if (!(mb->flags & 0x1)) {
        kernel_panic("Memory info not available");
    }
}