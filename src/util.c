#include "util.h"
#include "io.h"
#include <stdint.h>

uint8_t util_getNumberPlace(unsigned long long n, uint8_t place){
    if (place < 1) return 0;

    unsigned long long temp = n;
    uint8_t digits = 0;
    do{
        digits++;
        temp /= 10;
    }while (temp > 0);

    if (place > digits) return 0;

    uint8_t right_place = digits - place + 1;

    for (uint8_t i = 0; i < right_place - 1; i++) n /= 10;

    return n % 10;
}

char* util_intToStr(unsigned long long n){
    uint8_t count = 0;
    static char str[21];

    if (n == 0){
        str[0] = '0';
        str[1] = '\0';
        return str;
    }

    unsigned long long temp = n;
    while (temp > 0) {
        temp /= 10;
        count++;
    }
    
    for (uint8_t i = 0; i < count; i++){
        str[i] = '0' + util_getNumberPlace(n, i + 1);
    }
    str[count] = '\0';

    return str;
}

uint16_t util_pitReadCounter(){
    outb(0x43, 0x00);
    uint8_t lo = inb(0x40);
    uint8_t hi = inb(0x40);
    return (hi << 8) | lo;
}

void util_pitInitPolling(){
    outb(0x43, 0x34);
    outb(0x40, 0xFF);
    outb(0x40, 0xFF);
}

void util_wait(uint32_t ms){
    const uint32_t PIT_FREQ = 1193182;
    const uint32_t COUNTS_PER_MS = PIT_FREQ / 1000;

    uint32_t total_counts = COUNTS_PER_MS * ms;

    uint16_t prev = util_pitReadCounter();
    uint32_t elapsed = 0;

    while (elapsed < total_counts) {
        uint16_t now = util_pitReadCounter();

        if (now <= prev){
            elapsed += (prev - now);
        }else{
            elapsed += (prev + 65536 - now);
        }

        prev = now;
    }
}