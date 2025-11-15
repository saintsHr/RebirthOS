#pragma once
#include <stdint.h>

uint8_t util_getNumberPlace(unsigned long long n, uint8_t place);
char* util_intToStr(unsigned long long n);
char* util_binaryToStr(uint64_t num, uint8_t bits);
uint16_t util_pitReadCounter();
void util_pitInitPolling();
void util_wait(uint32_t ms);
uint64_t util_decimalToBinary(uint64_t num, uint8_t bits);
uint64_t binary_to_decimal(uint64_t bin, uint8_t bits);