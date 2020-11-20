#include "ds12c887.h" 

#ifdef SQW_OUTPUT

void Sqw_Output_NoIrq(unsigned char freq)
{
  unsigned char ctrl;
  ctrl = DS12C887_Peri_Read(CR_B);//�ر�ע���-�޸�-д
  Clr_Bit(ctrl,6);
  Set_Bit(ctrl,3);
  DS12C887_Peri_Write(CR_B,ctrl);

  ctrl = DS12C887_Peri_Read(CR_A);//�ر�ע���-�޸�-д
  ctrl |= freq;
  DS12C887_Peri_Write(CR_A,ctrl);
}

#endif