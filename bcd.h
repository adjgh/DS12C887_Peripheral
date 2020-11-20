#ifndef __BCD_H_
#define __BCD_H_
#include <stdint.h>

#define ONES_MASK      0xf0000
#define TENS_MASK      0xf00000
#define HUNDREDS_MASK   0xf000000
#define THOUSANDS_MASK 0xf0000000

#pragma SAVE
#pragma REGPARMS

extern uint32_t bin2bcd(uint16_t bin); 
//BCD CODE:0-9999

#pragma RESTORE