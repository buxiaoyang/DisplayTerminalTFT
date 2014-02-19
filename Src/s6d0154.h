/************************************************************/
/*��Ŀ��DisplayTerminalTFT
/*ģ�飺s6d0154����ͷ�ļ�
/*���ڣ�2014��2��17��
/*�޸ģ������D
/************************************************************/

#ifndef _S6D0154_DRV_
#define _S6D0154_DRV_

#define uchar unsigned char
#define uint unsigned int

/******************** ���Ŷ��� *******************/
sbit LCD_CS  =  P1^0;
sbit LCD_DC  =  P1^1;
sbit LCD_WR  =  P1^2;
sbit LCD_RD  =  P1^3;
sbit LCD_RST =  P1^4;
#define  LCD_DataPortH P2     //��8λ���ݿ�,8λģʽ��ֻʹ�ø�8λ 
#define  LCD_DataPortL P0     //��8λ���ݿ�	,8λģʽ�µ�8λ���Բ�����

/******************** �������� *******************/
#define  LCD_SIZE_X		240
#define  LCD_SIZE_Y		320

/******************** �������� *******************/
void LCD_Writ_Bus(char VH,char VL);     //��������д�뺯��
void LCD_Write_COM(char VH,char VL);    //��������
void LCD_Write_DATA(char VH,char VL);	//��������
void LCD_Init(void);    //��ʼ��s6d0154 TFT
void LCD_ShowString(uint x,uint y, uint size, uint For_color,uint Bk_color,char *p);
void LCD_ShowChar(uint x,uint y,uint size, For_color,uint Bk_color, char ch);
void ChineseChar(uint x,uint y,int size,uint For_color,uint Bk_color ,char c);
void ChineseString(uint x,uint y,int size,uint For_color,uint Bk_color ,char *p);
void Address_set(uint x1,uint y1,uint x2,uint y2);
void Display_Red(void);
void Display_Green(void);
void Display_Blue(void);
void Display_Black(void);
void Display_White(void);
void Display_Loding(void);
void Display_Loading_Image(void);
void Display_Running(void);
void Display_Running_Refresh(void);
void Display_Running_Image(void);
void Display_Running1(void);
void Display_Running2(void);
void Display_Running3(void);

#endif

