#ifndef __DS12C887_H
#define __DS12C887_H

#include <absacc.h>
#include <stdint.h>

#define ONES_MASK      0xf0000
#define TENS_MASK      0xf00000
#define HUNDREDS_MASK   0xf000000
#define THOUSANDS_MASK 0xf0000000

#define SEC        0x00
#define SEC_ALARM  0x01
#define MIN        0x02
#define MIN_ALARM  0x03
#define HOUR       0x04
#define HOUR_ALARM 0x05
#define WEEKDAY    0x06
#define DAY        0x07
#define MONTH      0x08
#define YEAR       0x09
#define CR_A       0x0A
#define CR_B       0x0B
#define CR_C       0x0C
#define CR_D       0x0D
#define CENTURY	   0x32

#define LOW_POWER  0x7F

#define Set_Bit(x,n)  x |= 1 << n
#define Clr_Bit(x,n)  x &= ~(1 << n)

#define OSCILLATOR_OPEN 0x20

#ifdef SQW_OUTPUT

#define SQW_256Hz_A  0x21
#define SQW_128Hz_A  0x22
#define SQW_8192Hz   0x23
#define SQW_4096Hz   0x24
#define SQW_2048Hz   0x25
#define SQW_1024Hz   0x26
#define SQW_512Hz    0x27
#define SQW_256Hz_B  0x28
#define SQW_128Hz_B  0x29
#define SQW_64Hz     0x2A
#define SQW_32Hz     0x2B
#define SQW_16Hz     0x2C
#define SQW_8Hz      0x2D
#define SQW_4Hz      0x2E
#define SQW_2Hz      0x2F
#define RESET        0x30
  
#endif

typedef struct time
{
  uint8_t year;
  uint8_t month;
  uint8_t day;
  uint8_t weekday;
  uint8_t hour;
  uint8_t minute;
  uint8_t second;
  uint8_t reserve;
}TIME,*PTIME;

#pragma SAVE
#pragma REGPARMS

extern void DS12C887_Peri_Write(uint8_t offset,uint8_t dat);   

extern uint8_t DS12C887_Peri_Read(uint8_t offset);

extern void SetTimeEx(uint8_t year,uint8_t month,uint8_t day,uint8_t weekday,
					  uint8_t hour,uint8_t minute,uint8_t second);

extern void _settime(PTIME time);

extern void _gettime(PTIME time);

extern void Today(PTIME time,uint8_t *str,int8_t *cmd);

extern uint8_t DS12C887_Is_LowPower(void);

extern void SetAlarm(uint8_t hour,uint8_t minute,uint8_t second);

extern void _alarm_enable(PTIME time);

extern void _alarm_disable(void);

extern void Init_DS12C887(void);

extern uint8_t bcd2dec(uint8_t dat);

extern uint32_t bin2bcd(uint16_t bin); 
//BCD CODE:0-9999

#ifdef SQW_OUTPUT

extern void Sqw_Output(uint8_t freq);

extern void Sqw_Output_NoIrq(uint8_t freq);

#endif

#pragma RESTORE

#endif