#include "ds12c887.h" 

void _alarm_disable(void)
{
  unsigned char ctrl;
  ctrl = DS12C887_Peri_Read(CR_B);//特别注意读-修改-写
  Clr_Bit(ctrl,5);	//置零AIE位
  DS12C887_Peri_Write(CR_B,ctrl);
}