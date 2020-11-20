#include "ds12c887.h" 

void _alarm_enable(PTIME time)
{
  unsigned char ctrl;
  ctrl = DS12C887_Peri_Read(CR_B);//�ر�ע���-�޸�-д
  Set_Bit(ctrl,7);	//����SETλ����ֹ����
  DS12C887_Peri_Write(CR_B,ctrl);

  DS12C887_Peri_Write(SEC_ALARM,time->second);
  DS12C887_Peri_Write(MIN_ALARM,time->minute);
  DS12C887_Peri_Write(HOUR_ALARM,time->hour);

  ctrl = DS12C887_Peri_Read(CR_B);//�ر�ע���-�޸�-д
  Set_Bit(ctrl,5);	//����AIEλ,����
  Clr_Bit(ctrl,7);//����SETλ���ָ�����
  DS12C887_Peri_Write(CR_B,ctrl);
}