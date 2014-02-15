#include "STC_NEW_8051.H"
#include "SERIAL.H"
#include "HEAD.H"

unsigned char get_i=0;  //读取数据的计数
unsigned char LenToSend=0;
unsigned int DataToSend;
//******************************************************************
//  STC89/12(MPC89/82)软复位程序
//------------------------------------------------------------------

#define    RELOAD_COUNT    0xf3    //12MHz,12T,SMOD=0,2400bps
#define    Self_Define_ISP_Download_Command    0x7f
//#define    RELOAD_COUNT    0xfd    //11.0592MHz,12T,SMOD=0,9600bps
//#define    Self_Define_ISP_Download_Command    0x0d

void soft_reset_to_ISP_Monitor(void)
{
  IAP_CONTR = 0x60;   //0110，0000  软复位到系统ISP监控区
}

void UART_Interrupt_Receive(void) interrupt 4 //using 1
{
  unsigned char k;
  
  if(RI==1)
  {
    RI   =    0;
    k    =    SBUF;
    if(k==Self_Define_ISP_Download_Command)        //是自定义下载命令
    {
      get_i++;
      if (10==get_i)
      {
        Delay(100); //zxy
        soft_reset_to_ISP_Monitor();    //软复位到系统ISP监控区
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

void SerialSend(unsigned int Data, unsigned char Len)
{
  if (0==TI)
  {
    SBUF=Data;
    Len--;
  }
  LenToSend=Len;
  DataToSend=Data;
}