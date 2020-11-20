#include "ds12c887.h"
#include <string.h>

void Today(PTIME time,uint8_t *str,int8_t *cmd)
/*������
  cmd   ��"yy-mm-dd"ֻ����������
        ��"yy-mm-dd hh-mm-ss w"ȫ����
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


         