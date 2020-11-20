#include "ds12c887.h" 

void _alarm_enable(PTIME time)
{
  unsigned char ctrl;
  ctrl = DS12C887_Peri_Read(CR_B);//特别注意读-修改-写
  Set_Bit(ctrl,7);	//设置SET位，禁止更新
  DS12C887_Peri_Write(CR_B,ctrl);

  DS12C887_Peri_Write(SEC_ALARM,time->second);
  DS12C887_Peri_Write(MIN_ALARM,time->minute);
  DS12C887_Peri_Write(HOUR_ALARM,time->hour);

  ctrl = DS12C887_Peri_Read(CR_B);//特别注意读-修改-写
  Set_Bit(ctrl,5);	//设置AIE位,闹钟
  Clr_Bit(ctrl,7);//清零SET位，恢复更新
  DS12C887_Peri_Write(CR_B,ctrl);
}