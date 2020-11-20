#include "ds12c887.h"


void DS12C887_Peri_Write(uint8_t offset,uint8_t dat)
{
  XBYTE[0x7f00 + offset] = dat;
} 	