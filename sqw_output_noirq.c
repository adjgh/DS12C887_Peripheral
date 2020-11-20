#include "ds12c887.h" 

#ifdef SQW_OUTPUT

void Sqw_Output_NoIrq(unsigned char freq)
{
  unsigned char ctrl;
  ctrl = DS12C887_Peri_Read(CR_B);//特别注意读-修改-写
  Clr_Bit(ctrl,6);
  Set_Bit(ctrl,3);
  DS12C887_Peri_Write(CR_B,ctrl);

  ctrl = DS12C887_Peri_Read(CR_A);//特别注意读-修改-写
  ctrl |= freq;
  DS12C887_Peri_Write(CR_A,ctrl);
}

#endif