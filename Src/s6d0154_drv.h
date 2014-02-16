#ifndef _S6D0154_DRV_
#define _S6D0154_DRV_
//******************************************************************
//  #define
//------------------------------------------------------------------
#define uchar unsigned char
#define uint unsigned int

void LCD_Writ_Bus(char VH,char VL);     //并行数据写入函数
void LCD_Write_COM(char VH,char VL);    //发送命令
void LCD_Write_DATA(char VH,char VL);	//发送数据
void LCD_Init(void);    //初始化s6d0154 TFT

#define  LCD_SIZE_X		240
#define  LCD_SIZE_Y		320

extern  uint colors[];
//------------------------------------------------------------------

void LCD_ShowString(uint x,uint y, uint size, uint For_color,uint Bk_color,char *p);
void LCD_ShowChar(uint x,uint y,uint size, For_color,uint Bk_color, char ch);
void ChineseChar(uint x,uint y,int size,uint For_color,uint Bk_color ,char c);
void ChineseString(uint x,uint y,int size,uint For_color,uint Bk_color ,char *p);
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
void Display_Loding(void);
void Display_Loading_Image(void);

void Display_Running(void);
void Display_Running_Image(void);

void Display_Running1(void);
void Display_Running2(void);
void Display_Running3(void);
//******************************************************************
//  
//------------------------------------------------------------------
#endif // _S6D0154_DRV_