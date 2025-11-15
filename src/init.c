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