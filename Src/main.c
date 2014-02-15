//******************************************************************
//  CPU:STC11L60XE
//  CRY:11.0592Mhz
//  LCM:s6d0154-2.6 TFT
//  PCB:v1
//  NAM:彩屏程序                                            20120906
//******************************************************************
//#include <REG54.H>
//#include <reg51.h>
#include "STC_NEW_8051.H"
#define uchar unsigned char
#define uint unsigned int

#include "HEAD.H"

//#include"init_tft.h"
#include"s6d0154_drv.h"
#include "SD_MMC.h"
#include "FAT3216.h"
#include "showimg51.h"

//---------------------------------
#define T0_H 0xF8 //0xFC  1ms from 12MHz 998 to 24MHz 1998
#define T0_L 0x32 //0x1A
#define T1_H 0xfe
#define T1_L 0x31
#include "serial.h" //串口功能
#include "SysTem.H"
extern unsigned char xdata Buffer[512];

//****************************************************************
//  延时1ms程序
//****************************************************************
//           fosc=12MHz;count=10;j=5, i=62; Keil uV2=9.977ms
//STC12c4042:fosc=12Mhz;count=1; j=10,i=169;KEIL750 =1.000ms!!!不准!!!实际长了
//STC12c5410AD:内置5.756373M;count=10;j=10,i=78;KEIL750=10.000ms!
void Delay(unsigned int count)// delay=1ms*count 12MHz with 11L60XE
{
    unsigned char i,j;
    while(count--!=0)
    {   for(j=0;j<10;j++)
	    {    for(i=0;i<168;i++);
}   }   }
//******************************************************************
//  在TFT上显示字符
//------------------------------------------------------------------
void ViewTFT(void)
{
    LCD_CS =0;  //打开片选使能
    //---------------------------------
    ChineseChar(14+46,10,2,colors[2],colors[7],1);	//晶
    ChineseChar(46+46,10,2,colors[2],colors[7],2);	//液
    ChineseChar(78+46,10,2,colors[2],colors[7],3);	//心
    ChineseChar(110+46,10,2,colors[2],colors[7],4);	//伤
	//---------------------------------
    ChineseChar( 0,50,1,colors[0],colors[7],1);	    //靠
    ChineseChar(24,50,1,colors[0],colors[7],2);	    //!
    
    ChineseChar( 48,50,1,colors[1],colors[7],3);    //
    ChineseChar( 72,50,1,colors[2],colors[7],4);    //
    ChineseChar( 96,50,1,colors[3],colors[2],5);    //
    ChineseChar(120,50,1,colors[4],colors[7],6);	//
    ChineseChar(144,50,1,colors[5],colors[7],7);	//
    ChineseChar(168,50,1,colors[6],colors[7],8);	//
    ChineseChar(192,50,1,colors[5],colors[2],9);	//片
	//---------------------------------
    ChineseChar( 0,75,1,colors[4],colors[7],10);    //
	ChineseChar(24,75,1,colors[4],colors[7],11);	//
	ChineseChar(48,75,1,colors[6],colors[7],12);	//
	ChineseChar(72,75,1,colors[6],colors[7],13);	//
	
	ChineseChar( 96,75,1,colors[2],colors[7],14);	//
	ChineseChar(120,75,1,colors[2],colors[7],15);	//
	ChineseChar(144,75,1,colors[2],colors[7],16);	//
	ChineseChar(168,75,1,colors[4],colors[7],17);	//
	ChineseChar(192,75,1,colors[4],colors[7],18);	//
	//---------------------------------
    ChineseChar( 0,100,1,colors[4],colors[7],19);   //
	ChineseChar(24,100,1,colors[5],colors[2],20);	//
	ChineseChar(48,100,1,colors[5],colors[2],21);	//
	ChineseChar(72,100,1,colors[5],colors[2],22);	//
	
	ChineseChar( 96,100,1,colors[2],colors[7],23);	//
	ChineseChar(120,100,1,colors[2],colors[7],24);	//
	ChineseChar(144,100,1,colors[2],colors[7],25);	//
	ChineseChar(168,100,1,colors[4],colors[7],26);	//
	ChineseChar(192,100,1,colors[4],colors[7],27);	//
	//---------------------------------
    ChineseChar( 0,125,1,colors[4],colors[7],28);   //
	ChineseChar(24,125,1,colors[1],colors[7],29);	//
	ChineseChar(48,125,1,colors[2],colors[7],30);	//
	ChineseChar(72,125,1,colors[3],colors[2],31);	//
	
	ChineseChar( 96,125,1,colors[2],colors[7],32);	//?
	//---------------------------------
    
    //LCD_ShowString(12,60,colors[0],colors[7],"-");
    //LCD_ShowString(0,90,colors[0],colors[5],"WWW.PRINTER.com");
    //LCD_ShowString(216,120,colors[4],colors[7],":");
    
	LCD_ShowString(0,150,colors[7],colors[2],"www.s6d0154.com");//www.s6d0154.com.net若超出字符不予显示
    //LCD_ShowString(12,180,colors[0],colors[7],"TELL:");
    
    LCD_ShowString(0,174,colors[2],colors[7],"T: 010-12345678");	
    LCD_ShowString(0,198,colors[2],colors[7],"abcdefJhiJKLMNOP"); 
    LCD_ShowString(0,222,colors[2],colors[7],"pqrstuvwxyz!@#$"); 
    LCD_ShowString(0,246,colors[2],colors[7],"<>CDEF^&*()/,[]");
    //---------------------------------
	LCD_CS =1;  //关闭片选使能
}

void TestDelay(uchar timer)
{
//  uint DelayTime;

  etx0=0;
  TH0=T0_H;
  TL0=T0_L;
  if (1==timer)
  {
    TR0=1;
    Delay(1);
    TR0=0;
  }
  else
  {
    TR0=1;
    delayms(1);
    TR0=0;
  }
//  DelayTime=(TH0<<8)|TL0;
  SerialSend(etx0,2);
}

unsigned int etx0;
uchar idata Display[16]={0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,
                   0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x00};
void HEXtoASC(uint HEX, uchar index)
{
  uchar i;// temp;
  index +=4;
  Display[index]=0;
  for (i=4;i!=0;i--)
  {
    index--;
    Display[index]=(HEX%10)+'0';
	HEX/=10;
  }
/*	if (4==i)
	  temp=HEX>>12;
    else if (3==i)
	  temp=HEX>>8;
    else if (2==i)
	  temp=((uchar)HEX)>>4;
	else
	  temp=HEX;
	temp&=0x0f;
	if (temp>9)
	  Display[index]=temp+'A'-10;
	else
	  Display[index]=temp+'0';
	index++;
  }*/
}

//******************************************************************
//  主程序
//------------------------------------------------------------------
void main(void)
{
    uchar res;
	uchar count;

    LCD_Init();
	InitSys();//初始化timer/serial-isp
    //---------------------------------
    res=SD_init();                  //SD卡初始化
    /*
            //---------------------------------
            Pant(0xff,0xff);  //TFT清屏
            Delay(100);
            //---------------------------------
            Display_Image();
            Delay(2000);
            //while(1);
    */
            ViewTFT();          //在TFT上显示字符
            Delay(1000);
            //while(1);
    if (!res) res=Get_disk_info();            //获取FAT32文件系统参数
//        Display_Red();
        Delay(1000);
    while(1)
    {
#define TXT 0
#define BIN 3            
      if (!res) res=Scan_file(200,TXT);
//        Display_Green();
        Delay(500);
      if (!res) res=Readfile();
	  if (!res)
	  {
            LCD_CS =0;  //打开片选使能
            LCD_ShowString(0,296,colors[0],colors[4],Buffer);
            LCD_CS =1;  //关闭片选使能
	  }
      Delay(2000);
      count	= 0;
      do
	  {
	    if (!res) res=Scan_file(count,BIN);
        if (!res) 
	    {
          Delay(500);
            etx0=0;
            TH0=T0_H;
            TL0=T0_L;
            TR0=1;
	      Show_TFImage();    //显示图片240*320
            TR0=0;
		    HEXtoASC(etx0, 0);
			Display[4]='m';
			Display[5]='s';
			Display[6]=0;
            LCD_CS =0;  //打开片选使能
          Delay(3000);
		  LCD_ShowString(0,296,colors[7],colors[4],Display);
	    }
	    count++;
	  }while (!res);
	  res=0;
	}
    while(1)
    {
        Display_White();
        Delay(400);
        Display_Black();
        Delay(400);

        etx0=0;
        TH0=T0_H;
        TL0=T0_L;
        TR0=1;
        Display_Red();
        TR0=0;
//        DelayTime=(etx0<<8);
//		DelayTime|=(etx0>>8);
        SerialSend(etx0,2);
		HEXtoASC(etx0, 0);
        Delay(400);

        Display_Green();
        Delay(400);
        Display_Blue();
        Delay(400);

        etx0=0;
        TH0=T0_H;
        TL0=T0_L;
        TR0=1;
        Pant(0x0,0x0);    //TFT黑色清屏
        TR0=0;
//        DelayTime=(etx0<<8);
//		DelayTime|=(etx0>>8);
        SerialSend(etx0,2);
		HEXtoASC(etx0, 5);
        Delay(400);
        //---------------------------------
//        while(1)
        {
            Pant(0xff,0xff);    //TFT白色清屏
            Delay(400);
            etx0=0;
            TH0=T0_H;
            TL0=T0_L;
            TR0=1;
            Show_ROMImage();    //显示图片240*80
            TR0=0;
//            DelayTime=(etx0<<8);
//			DelayTime|=(etx0>>8);
            SerialSend(etx0,2);
		    HEXtoASC(etx0, 10);
//		    Display[4]=Buffer[0];
//		    Display[9]=Buffer[1];
//		    Display[14]=Buffer[3];
            LCD_CS =0;  //打开片选使能
            LCD_ShowString(0,296,colors[7],colors[4],Display);
            LCD_CS =1;  //关闭片选使能
            Delay(3000);
            //---------------------------------
//            Pant(0xff,0xff);  //不清屏的话就在上幅Image上覆盖
//            Delay(500);
			TestDelay(1);
            ViewTFT();          //在TFT上显示字符
            Delay(2000);
		    TestDelay(2);
        }
    }
}
//while(1){Delay(500);PWM0=~PWM0;}
//******************************************************************
//  
//------------------------------------------------------------------

//---------------------------------

//******************************************************************
//  
//------------------------------------------------------------------
