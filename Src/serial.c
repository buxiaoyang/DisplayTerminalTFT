/************************************************************/
/*��Ŀ��DisplayTerminalTFT
/*ģ�飺����ģ��
/*���ڣ�2014��2��17��
/*�޸ģ������D
/************************************************************/

#include "reg52stc.h"
#include "serial.h"

/******************** ȫ�ֱ������� *******************/
uchar get_i=0;  //��ȡ���ݵļ���
uchar LenToSend=0;
uint DataToSend;
#define    RELOAD_COUNT    0xe6    //12MHz,0xf3, 12T,SMOD=0,2400bps; 24MHz 0xe6
#define    Self_Define_ISP_Download_Command    0x7f

/******************** �ӳٺ���ms *******************/
void delayms(uint tt)
{
    uchar i;
	uchar j;
    while(tt>0)
    {
        tt--;
        for(j=0;j<5;j++)
	    {
		    for(i=0;i<168;i++)
			{
			}
        }
    }
}

/******************** ��λ���� *******************/
void soft_reset_to_ISP_Monitor(void)
{
	IAP_CONTR = 0x60;   //0110��0000  ��λ��ϵͳISP�����
}

/******************** ���ڽ����жϺ��� *******************/
void UART_Interrupt_Receive(void) interrupt 4 //using 1
{
	uchar k;
	if(RI==1)
	{
		RI = 0;
		k = SBUF;
		if((k==Self_Define_ISP_Download_Command)||(0x1f==k))        //���Զ�����������
		{
			get_i++;
			if (10==get_i)
			{
				delayms(200); //zxy
				soft_reset_to_ISP_Monitor();    //��λ��ϵͳISP�����
			}
		}
		else
		{
			if ((0==TI)&&(0==LenToSend))
			{
				SBUF=0xa5;  //Serial OK !!!
			}
			get_i=0;
		}
	}
	else
	{
		TI = 0;
		if (0!=LenToSend)
		{
			LenToSend--;
			if (0==LenToSend)
				SBUF=DataToSend>>8;
			else
				SBUF=DataToSend;
		}
	}
}

/******************** ���ڷ��ͺ��� *******************/
void SerialSend(uint Data, uchar Len)
{
	if (0==TI)
	{
		SBUF=Data;
		Len--;
	}
	LenToSend=Len;
	DataToSend=Data;
}

