#include "ds12c887.h" 

uint8_t DS12C887_Is_LowPower(void)
{
  if (DS12C887_Peri_Read(CR_D) & 0x80 == 0)
   return LOW_POWER;
  return 0;
}