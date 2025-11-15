#include "str.h"
#include <stdint.h>
#include <stdarg.h>
#include <stdbool.h>

#define CONCAT_BUF_SIZE 512

char* str_concatStr(int count, ...){
    static char buffer[CONCAT_BUF_SIZE];
    uint32_t pos = 0;

    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++){
        char* str = va_arg(args, char*);
        if (!str) continue;

        while (*str && pos < CONCAT_BUF_SIZE - 1){
            buffer[pos++] = *str++;
        }
    }

    buffer[pos] = '\0';
    va_end(args);

    return buffer;
}

bool str_cmpStr(char* str1, char* str2){
    uint16_t i = 0;

    while (str1[i] != '\0' && str2[i] != '\0'){
        if (str1[i] != str2[i]){
            return false;
        }
        i++;
    }

    return str1[i] == str2[i];
}