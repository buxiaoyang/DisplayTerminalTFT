/************************************************************/
/*项目：DisplayTerminalTFT
/*模块：s6d0154驱动头文件
/*日期：2014年2月17日
/*修改：卜晓旸
/************************************************************/

#ifndef _S6D0154_DRV_
#define _S6D0154_DRV_

#define uchar unsigned char
#define uint unsigned int

/******************** 引脚定义 *******************/
sbit LCD_CS  =  P1^0;
sbit LCD_DC  =  P1^1;
sbit LCD_WR  =  P1^2;
sbit LCD_RD  =  P1^3;
sbit LCD_RST =  P1^4;
#define  LCD_DataPortH P2     //高8位数据口,8位模式下只使用高8位 
#define  LCD_DataPortL P0     //低8位数据口	,8位模式下低8位可以不接线

/******************** 变量定义 *******************/
#define  LCD_SIZE_X		240
#define  LCD_SIZE_Y		320

/******************** 函数声明 *******************/
void LCD_Writ_Bus(char VH,char VL);     //并行数据写入函数
void LCD_Write_COM(char VH,char VL);    //发送命令
void LCD_Write_DATA(char VH,char VL);	//发送数据
void LCD_Init(void);    //初始化s6d0154 TFT
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

