#include "ds12c887.h" 

void _alarm_disable(void)
{
  unsigned char ctrl;
  ctrl = DS12C887_Peri_Read(CR_B);//�ر�ע���-�޸�-д
  Clr_Bit(ctrl,5);	//����AIEλ
  DS12C887_Peri_Write(CR_B,ctrl);
}