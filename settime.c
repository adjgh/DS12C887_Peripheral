#include "ds12c887.h"

 void _settime(PTIME time)
{
  unsigned char ctrl = 0;
  //�ر�ע���-�޸�-д
  ctrl = DS12C887_Peri_Read(CR_B);//��
  Set_Bit(ctrl,7);	//����SETλ����ֹ���£��޸�
  DS12C887_Peri_Write(CR_B,ctrl);//д

  DS12C887_Peri_Write(SEC,time->second);
  DS12C887_Peri_Write(MIN,time->minute);
  DS12C887_Peri_Write(HOUR,time->hour);
  DS12C887_Peri_Write(WEEKDAY,time->weekday);
  DS12C887_Peri_Write(DAY,time->day);
  DS12C887_Peri_Write(MONTH,time->month);
  DS12C887_Peri_Write(YEAR,time->year);
  //�ر�ע���-�޸�-д
  ctrl = DS12C887_Peri_Read(CR_B);//��
  Clr_Bit(ctrl,7);//����SETλ���ָ�����,�޸�
  DS12C887_Peri_Write(CR_B,ctrl);//д
}