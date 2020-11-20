#include "ds12c887.h"

void SetAlarm(uint8_t hour,uint8_t minute,uint8_t second)
{
   TIME time;
   time.hour    = hour;
   time.minute  = minute;
   time.second  = second;
   _alarm_enable(&time);
}