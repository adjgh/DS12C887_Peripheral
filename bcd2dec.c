#include "ds12c887.h" 

uint8_t bcd2dec(uint8_t dat)
{
    uint8_t temp;

    temp = ((dat >> 4) * 10 + (dat & 0x0f));
    return temp;
}