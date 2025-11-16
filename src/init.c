#include "init.h"
#include "vga.h"
#include "str.h"

void init_printLog(char* msg, char* type){
    vga_print(VGA_BLACK, VGA_LGRAY, "[ ");

    if (str_cmpStr(type, "info")){
        vga_print(VGA_BLACK, VGA_CYAN, "INFO ");
    }else if (str_cmpStr(type, "ok")){
        vga_print(VGA_BLACK, VGA_GREEN, " OK  ");
    }else if (str_cmpStr(type, "error")){
        vga_print(VGA_BLACK, VGA_RED, "ERROR");
    }else{
        return;
    }

    vga_print(VGA_BLACK, VGA_LGRAY, " ] ");

    vga_print(VGA_BLACK, VGA_LGRAY, msg);
    vga_newLine();
}

void init_welcome(){
    vga_moveCursor(1, 1);

    // Box
    vga_print(VGA_BLACK, VGA_LGRAY, "########################");
    for (uint8_t i = 2; i < 6; i++){
        vga_moveCursor(1, i);
        vga_print(VGA_BLACK, VGA_LGRAY, "#");
    }
    vga_print(VGA_BLACK, VGA_LGRAY, "########################");
    for (uint8_t i = 1; i < 6; i++){
        vga_moveCursor(25, i);
        vga_print(VGA_BLACK, VGA_LGRAY, "#");
    }

    // Title
    vga_moveCursor(8, 2);
    vga_print(VGA_BLACK, VGA_LGRAY, "Rebirth OS");
    vga_moveCursor(3, 4);
    vga_print(VGA_BLACK, VGA_LGRAY, "Version: v0.0.0");

    // Prompt
    vga_moveCursor(0, 7);
    vga_print(VGA_BLACK, VGA_LGRAY,"RebirthOS> ");
}