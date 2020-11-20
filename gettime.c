#include "ds12c887.h"

void _gettime(PTIME time)
{
  while(DS12C887_Peri_Read(CR_A) & 0x80 != 0);
  time->second  = DS12C887_Peri_Read(SEC);
  while(DS12C887_Peri_Read(CR_A) & 0x80 != 0);
  time->minute  = DS12C887_Peri_Read(MIN);
  while(DS12C887_Peri_Read(CR_A) & 0x80 != 0);
  time->hour    = DS12C887_Peri_Read(HOUR);
  while(DS12C887_Peri_Read(CR_A) & 0x80 != 0);
  time->weekday = DS12C887_Peri_Read(WEEKDAY);
  while(DS12C887_Peri_Read(CR_A) & 0x80 != 0);
  time->day     = DS12C887_Peri_Read(DAY);
  while(DS12C887_Peri_Read(CR_A) & 0x80 != 0);
  time->month   = DS12C887_Peri_Read(MONTH);
  while(DS12C887_Peri_Read(CR_A) & 0x80 != 0);
  time->year    = DS12C887_Peri_Read(YEAR);
}