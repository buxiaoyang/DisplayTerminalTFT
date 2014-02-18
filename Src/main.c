/************************************************************/
/*项目：DisplayTerminalTFT
/*模块：主函数
/*CPU:	STC11L60XE
/*晶振:	24Mhz
/*液晶:	s6d0154-2.6 TFT
/*日期：2014年2月17日
/*修改：卜晓旸
/************************************************************/

#include "reg52stc.h"
#include "s6d0154.h"
#include "serial.h"

/******************** 定时器定义 *******************/
#define T0_H 0xF8 //0xFC  1ms from 12MHz 998 to 24MHz 1998
#define T0_L 0x32 //0x1A
#define T1_H 0xfe
#define T1_L 0x31

/******************** 定时器0中断函数 *******************/
void time0() interrupt 1 //using 1
{
    TR0=0;
    TH0=T0_H;   
    TL0=T0_L;   
    TR0=1;
}

/******************** 系统初始化函数 *******************/
void InitSys(void)
{
    EA=0;
    TCON=0x05;  //1->0 == EX0 INT !!!
    TMOD=0x21;  //time0:16bit;time1:serial
    TH1=0xe6;    //12MHz,0xf3, 12T,SMOD=0,2400bps; 24MHz 0xe6
    TL1=0xe6;
    PCON=0x00; 
    SCON=0x70; //MODE:1;   串口10位异步收发，定时器控制
    ES=1;      //串口中断开
    ET1=0;
    TR1=1;
    ET0=1;
    EA=1;
}

/******************** 主函数 *******************/
void main(void)
{
	InitSys();
    LCD_Init();
	Display_Running();
    while(1)
    {
		/*
  	   Display_Loding();
	   delayms(10000);
	   
	   delayms(20000);   
	   Display_Running1();
	   delayms(20000); 
	   Display_Running2();
	   delayms(20000); 
	   Display_Running3();
	   delayms(20000); 
	   */ 
    }
}


