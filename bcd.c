#include "ds12c887.h" 
//函数执行时间3.718ms
uint32_t bin2bcd(uint16_t bin)
{
	uint32_t bcd = bin;
	uint8_t shift_bits = 15;
	if (bcd < 10)
		return bcd;
	 do{
		if ((bcd & ONES_MASK) > 0x40000)
			bcd += 0x30000;
		if ((bcd & TENS_MASK) > 0x400000)
			bcd += 0x300000;
		if ((bcd & HUNDREDS_MASK) > 0x4000000)
			bcd += 0x3000000;
		if((bcd & THOUSANDS_MASK) > 0x40000000)
			bcd += 0x30000000;
		bcd <<= 1;
	 } while (shift_bits--);
	return (bcd >> 16);
}
