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

#define  LCD_DataPortH P2     //高8位数据口,8位模式下只使用高8位 
#define  LCD_DataPortL P0     //低8位数据口	,8位模式下低8位可以不接线
//------------------------------------------------------------------
//  #define
//------------------------------------------------------------------
#define uchar unsigned char
#define uint unsigned int

#define  LCD_SIZE_X		240
#define  LCD_SIZE_Y		320

extern  uint colors[];
//------------------------------------------------------------------

void LCD_Writ_Bus(char VH,char VL);     //并行数据写入函数
void LCD_Write_COM(char VH,char VL);    //发送命令
void LCD_Write_DATA(char VH,char VL);	//发送数据
void LCD_Init(void);    //初始化s6d0154 TFT

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