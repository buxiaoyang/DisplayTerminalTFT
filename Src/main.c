//******************************************************************
//  CPU:STC11L60XE
//  CRY:11.0592Mhz
//  LCM:s6d0154-2.6 TFT
//  PCB:v1
//  NAM:彩屏程序                                            20120906
//******************************************************************
//#include <REG54.H>
#include <reg51.h>
#define uchar unsigned char
#define uint unsigned int

#include <HEAD.H>

//#include"init_tft.h"
#include"s6d0154_drv.h"

//---------------------------------
#define T0_H 0xfc
#define T0_L 0x66
#define T1_H 0xfe
#define T1_L 0x31
void Delay(unsigned int);
#include <serial.h> //串口功能
#include <SysTem.H>
//****************************************************************
//  延时1ms程序
//****************************************************************
//           fosc=12MHz;count=10;j=5, i=62; Keil uV2=9.977ms
//STC12c4042:fosc=12Mhz;count=1; j=10,i=169;KEIL750 =1.000ms!!!不准!!!实际长了
//STC12c5410AD:内置5.756373M;count=10;j=10,i=78;KEIL750=10.000ms!
void Delay(unsigned int count)// delay=1ms*count
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
    ChineseChar(14+46,10,2,colors[2],colors[7],1);	//伤
    ChineseChar(46+46,10,2,colors[2],colors[7],2);	//心
    ChineseChar(78+46,10,2,colors[2],colors[7],3);	//液
    ChineseChar(110+46,10,2,colors[2],colors[7],4);	//晶
	//---------------------------------
    ChineseChar( 0,60,1,colors[0],colors[7],1);	    //靠
    ChineseChar(24,60,1,colors[0],colors[7],2);	    //!
    
    ChineseChar( 48,60,1,colors[1],colors[7],3);    //
    ChineseChar( 72,60,1,colors[2],colors[7],4);    //
    ChineseChar( 96,60,1,colors[3],colors[2],5);    //
    ChineseChar(120,60,1,colors[4],colors[7],6);	//
    ChineseChar(144,60,1,colors[5],colors[7],7);	//
    ChineseChar(168,60,1,colors[6],colors[7],8);	//
    ChineseChar(192,60,1,colors[5],colors[2],9);	//片
	//---------------------------------
    ChineseChar( 0,90,1,colors[4],colors[7],10);    //
	ChineseChar(24,90,1,colors[4],colors[7],11);	//
	ChineseChar(48,90,1,colors[6],colors[7],12);	//
	ChineseChar(72,90,1,colors[6],colors[7],13);	//
	
	ChineseChar( 96,90,1,colors[2],colors[7],14);	//
	ChineseChar(120,90,1,colors[2],colors[7],15);	//
	ChineseChar(144,90,1,colors[2],colors[7],16);	//
	ChineseChar(168,90,1,colors[4],colors[7],17);	//
	ChineseChar(192,90,1,colors[4],colors[7],18);	//
	//---------------------------------
    ChineseChar( 0,120,1,colors[4],colors[7],19);   //
	ChineseChar(24,120,1,colors[5],colors[2],20);	//
	ChineseChar(48,120,1,colors[5],colors[2],21);	//
	ChineseChar(72,120,1,colors[5],colors[2],22);	//
	
	ChineseChar( 96,120,1,colors[2],colors[7],23);	//
	ChineseChar(120,120,1,colors[2],colors[7],24);	//
	ChineseChar(144,120,1,colors[2],colors[7],25);	//
	ChineseChar(168,120,1,colors[4],colors[7],26);	//
	ChineseChar(192,120,1,colors[4],colors[7],27);	//
	//---------------------------------
    ChineseChar( 0,150,1,colors[4],colors[7],28);   //
	ChineseChar(24,150,1,colors[1],colors[7],29);	//
	ChineseChar(48,150,1,colors[2],colors[7],30);	//
	ChineseChar(72,150,1,colors[3],colors[2],31);	//
	
	ChineseChar( 96,150,1,colors[2],colors[7],32);	//?
	//---------------------------------
    
    //LCD_ShowString(12,60,colors[0],colors[7],"-");
    //LCD_ShowString(0,90,colors[0],colors[5],"WWW.PRINTER.com");
    //LCD_ShowString(216,120,colors[4],colors[7],":");
    
	LCD_ShowString(0,180,colors[7],colors[2],"www.s6d0154.com");//www.s6d0154.com.net若超出字符不予显示
    //LCD_ShowString(12,180,colors[0],colors[7],"TELL:");
    
    LCD_ShowString(0,210,colors[2],colors[7],"T: 010-12345678");	
    LCD_ShowString(0,240,colors[2],colors[7],"abcdefJhiJKLMNOP"); 
    LCD_ShowString(0,265,colors[2],colors[7],"pqrstuvwxyz!@#$"); 
    LCD_ShowString(0,290,colors[2],colors[7],"<>CDEF^&*()/,[]");
    //---------------------------------
	LCD_CS =1;  //关闭片选使能
}
//******************************************************************
//  主程序
//------------------------------------------------------------------
void main(void)
{
    Delay(100);
	InitSys();//初始化timer/serial-isp
    //---------------------------------
    Delay(100);
    LCD_Init();//-yuan
    Delay(100);
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
            Delay(3000);
            //while(1);
            
    while(1)
    {
        Display_Red();
        Delay(300);
        Display_Green();
        Delay(300);
        Display_Blue();
        Delay(300);
        Display_White();
        Delay(300);
        Display_Black();
        Delay(300);
        //---------------------------------
        while(1)
        {
            Pant(0xff,0xff);    //TFT清屏
            //Delay(100);
            Display_Image();    //显示图片240*80
            Delay(3000);
            //---------------------------------
            //Pant(0xff,0xff);  //不清屏的话就在上幅Image上覆盖
            //Delay(100);
            ViewTFT();          //在TFT上显示字符
            Delay(3000);
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
