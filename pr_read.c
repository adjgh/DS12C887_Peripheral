#include "ds12c887.h"

uint8_t DS12C887_Peri_Read(uint8_t offset)
{
    return (XBYTE[0x7f00 + offset]);
}