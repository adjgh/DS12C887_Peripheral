#include "ds12c887.h"
#include <string.h>

void Today(PTIME time,uint8_t *str,int8_t *cmd)
/*参数：
  cmd   ①"yy-mm-dd"只返回年月日
        ②"yy-mm-dd hh-mm-ss w"全日期
*/
{
   int8_t index;
   _gettime(time);
   if(strcmp("yy-mm-dd",cmd) == 0){
     str[0] = time->year;
	 str[1] = time->month;
	 str[2] = time->day;
	 }
   else if(strcmp("yy-mm-dd hh-mm-ss w",cmd) == 0){
     str[0] = time->year;
	 str[1] = time->month;
	 str[2] = time->day;
	 str[3] = time->hour;
	 str[4] = time->minute;
	 str[5] = time->second;
	 str[6] = time->weekday;
	 }
	 else
	  for(index = 0;index < sizeof(str);index++)
	    str[index] = 0xff;
}


         