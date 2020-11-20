#include "ds12c887.h"

void SetTimeEx(uint8_t year,uint8_t month,uint8_t day,uint8_t weekday,
					uint8_t hour,uint8_t minute,uint8_t second)
{
   TIME time;
   time.year    = year;
   time.month   = month;
   time.day     = day;
   time.weekday = weekday;
   time.hour    = hour;
   time.minute  = minute;
   time.second  = second;
   _settime(&time);
}