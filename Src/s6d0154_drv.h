#ifndef _S6D0154_DRV_
#define _S6D0154_DRV_
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
//------------------------------------------------------------------
//  #define
//------------------------------------------------------------------
#define uchar unsigned char
#define uint unsigned int

#define  LCD_SIZE_X		240
#define  LCD_SIZE_Y		320

extern  uint colors[];
//------------------------------------------------------------------

void LCD_Writ_Bus(char VH,char VL);     //��������д�뺯��
void LCD_Write_COM(char VH,char VL);    //��������
void LCD_Write_DATA(char VH,char VL);	//��������
void LCD_Init(void);    //��ʼ��s6d0154 TFT

void LCD_ShowString(uint x,uint y,uint For_color,uint Bk_color,char *p);
void LCD_ShowChar(uint x,uint y,uint For_color,uint Bk_color, char ch);
void ChineseChar(uint x,uint y,int size,uint For_color,uint Bk_color ,char c);

//void LCD_Init(void);
//void delayms(int count);
//void LCD_Writ_Bus(char VH,char VL);
//void LCD_Write_COM(char VH,char VL);
//void LCD_Write_DATA(char VH,char VL);

void Pant(char VH,char VL);
void Address_set(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2);
//------------------------------------------------------------------
//void Write_CMD(unsigned int i,unsigned int j);
//void Write_DAT(unsigned int i,unsigned int j);
//void Write_DAT_18(unsigned int i,unsigned int j,unsigned int k);

void Display_Red(void);
void Display_Green(void);
void Display_Blue(void);
void Display_Black(void);
void Display_White(void);
//void delay(long tt);
void Display_Image(void);
//******************************************************************
//  
//------------------------------------------------------------------
#endif // _S6D0154_DRV_