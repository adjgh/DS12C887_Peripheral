#include "ds12c887.h" 

void Init_DS12C887(void)
{ 
  unsigned char ctrl = 0;
  Clr_Bit(ctrl,2);	//BCD��ʽ
  Set_Bit(ctrl,1);	//24Сʱ��
  Clr_Bit(ctrl,0); //ȡ������ʱ��
  DS12C887_Peri_Write(CR_B,ctrl);
  DS12C887_Peri_Write(CR_A,OSCILLATOR_OPEN);//��������
}