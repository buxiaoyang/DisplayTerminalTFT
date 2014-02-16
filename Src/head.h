#ifndef _HEAD_
#define _HEAD_

//******************************************************************
//  CPU:STC11L60XE
//  CRY:12Mhz
//  LCM:s6d0154-2.6 TFT
//  PCB:v1
//  NAM:��������                                            20120906
//******************************************************************
//  I/O define
//---------------------------------

sbit LCD_CS  =  P1^0;
sbit LCD_DC  =  P1^1;
sbit LCD_WR  =  P1^2;
sbit LCD_RD  =  P1^3;

sbit LCD_RST =  P1^4;

#define  LCD_DataPortH P2     //��8λ���ݿ�,8λģʽ��ֻʹ�ø�8λ 
#define  LCD_DataPortL P0     //��8λ���ݿ�	,8λģʽ�µ�8λ���Բ�����

unsigned char code pic1[];
void Delay(unsigned int tt);
void delayms(unsigned int tt);
void comm_out(unsigned int j,unsigned int i);
void data_out(unsigned int j,unsigned int i);
void com_data(unsigned int j,unsigned int i);
void display_red(void);
void display_blue(void);
void display_green(void);
void display_white(void);
void display_black(void);
void display_image1(void);
void Pant(char VH,char VL);

#endif

