#include "ds12c887.h"

 void _settime(PTIME time)
{
  unsigned char ctrl = 0;
  //特别注意读-修改-写
  ctrl = DS12C887_Peri_Read(CR_B);//读
  Set_Bit(ctrl,7);	//设置SET位，禁止更新，修改
  DS12C887_Peri_Write(CR_B,ctrl);//写

  DS12C887_Peri_Write(SEC,time->second);
  DS12C887_Peri_Write(MIN,time->minute);
  DS12C887_Peri_Write(HOUR,time->hour);
  DS12C887_Peri_Write(WEEKDAY,time->weekday);
  DS12C887_Peri_Write(DAY,time->day);
  DS12C887_Peri_Write(MONTH,time->month);
  DS12C887_Peri_Write(YEAR,time->year);
  //特别注意读-修改-写
  ctrl = DS12C887_Peri_Read(CR_B);//读
  Clr_Bit(ctrl,7);//清零SET位，恢复更新,修改
  DS12C887_Peri_Write(CR_B,ctrl);//写
}