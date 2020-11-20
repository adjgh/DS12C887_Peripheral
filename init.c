#include "ds12c887.h" 

void Init_DS12C887(void)
{ 
  unsigned char ctrl = 0;
  Clr_Bit(ctrl,2);	//BCD格式
  Set_Bit(ctrl,1);	//24小时制
  Clr_Bit(ctrl,0); //取消夏令时制
  DS12C887_Peri_Write(CR_B,ctrl);
  DS12C887_Peri_Write(CR_A,OSCILLATOR_OPEN);//振荡器开启
}