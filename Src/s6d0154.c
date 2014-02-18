/************************************************************/
/*项目：DisplayTerminalTFT
/*模块：s6d0154驱动
/*日期：2014年2月17日
/*修改：卜晓旸
/************************************************************/

#include "reg52stc.h"
#include "s6d0154.h"  
#include "picture.h"
#include "chinese.h"
#include "ascii.h"
#include "serial.h"

/******************** 颜色定义 *******************/
//   0      1      2      3      4      5      6      7
//  红     绿     蓝     黄     黑     青     紫     白
uint colors[]={
	0xf800,0x07e0,0x001f,0xffe0,0x0000,0x07ff,0xf81f,0xffff
};

/******************** 写数据函数 *******************/
void Write_DATA(uint i,uint j)
{
	//8080 interface
	LCD_CS = 0;
	LCD_DC = 1;
	LCD_RD = 1;
	P0  = j;
	P2  = i;
	LCD_WR = 0;
	LCD_WR = 1;
	LCD_CS = 1;
}

/******************** 写命令函数 *******************/
void Write_COMD(uint i,uint j)
{
	//8080 interface
	LCD_CS = 0;  
	LCD_RD = 1;
	LCD_DC = 0;
	P0  = j;	 
	P2  = i;
	LCD_WR = 0;
	LCD_WR = 1;
	LCD_CS = 1;
}

/******************** 刷屏程序 红 *******************/
void Display_Red(void)
{  
	uint i,j,k=0;
	LCD_CS =0;  //打开片选使能
	Address_set(0,0,239,319);
	Write_COMD(0x00,0x22); 
	for(i=0;i<320;i++)
	{
		for(j=0;j<240;j++)
		{
			Write_DATA(0xf8,0x00);//data_out18(0xfc,0x00,0x00);
		}
	}
	LCD_CS = 1;  //关闭片选使能
}

/******************** 刷屏程序 绿 *******************/
void Display_Green(void)
{  
	uint i,j;
	LCD_CS =0;  //打开片选使能
	Address_set(0,0,239,319);
	Write_COMD(0x00,0x22); 
	for(i=0;i<320;i++)
	{
		for(j=0;j<240;j++)
		{
			Write_DATA(0x07,0xe0);
		}
	}
	LCD_CS = 1;  //关闭片选使能
}

/******************** 刷屏程序 蓝 *******************/
void Display_Blue(void)
{  
	uint i,j;
	LCD_CS =0;  //打开片选使能
	Write_COMD(0x00,0x20);
	Write_DATA(0x00,0x00);
	Write_COMD(0x00,0x21);
	Write_DATA(0x00,0x00);
	Write_COMD(0x00,0x22);
	for(i=0;i<320;i++)
	{
		for(j=0;j<240;j++)
		{
			Write_DATA(0x00,0x1f);
		}
	}
	LCD_CS = 1;  //关闭片选使能
}

/******************** 刷屏程序 白 *******************/
void Display_White(void)
{
    uint i,j;
	LCD_CS =0;  //打开片选使能
	Address_set(0,0,239,319);
    for(i=0;i<320;i++)
    {
        for(j=0;j<240;j++)
	    {
            Write_DATA(0xff,0xff);
            //Write_Data_18(0xff,0xff,0xc0);
        }
    }
	LCD_CS = 1;  //关闭片选使能
}

/******************** 刷屏程序 黑 *******************/
void Display_Black(void)
{  
    uint i,j,k;
	LCD_CS =0;  //打开片选使能
	Address_set(0,0,239,319);
    for(i=0;i<240;i++)
    {
        Write_DATA(0xff,0xff);
    }
    for(i=0;i<318;i++)  //加外框
    {
        for(k=0;k<1;k++)
	    {
            Write_DATA(0xff,0xff);
	    }
	    for(j=0;j<238;j++)
	    {
		    Write_DATA(0x00,0x00);
	    }
	    for(k=0;k<1;k++)
	    {
	        Write_DATA(0xff,0xff);
	    }
    }
    for(i=0;i<240;i++)
    {
        Write_DATA(0xff,0xff);
    }
	LCD_CS = 1;  //关闭片选使能
}

/******************** 地址设置函数 *******************/
void Address_set(uint x1,uint y1,uint x2,uint y2)
{
    LCD_Write_COM(0x00,0x20);LCD_Write_DATA(x1>>8,x1);  //设置X坐标位置
    LCD_Write_COM(0x00,0x21);LCD_Write_DATA(y1>>8,y1);  //设置Y坐标位置	 
    LCD_Write_COM(0x00,0x37);LCD_Write_DATA(x1>>8,x1);  //开始X
	LCD_Write_COM(0x00,0x39);LCD_Write_DATA(y1>>8,y1);  //开始Y
    LCD_Write_COM(0x00,0x36);LCD_Write_DATA(x2>>8,x2);  //结束X
	LCD_Write_COM(0x00,0x38);LCD_Write_DATA(y2>>8,y2);  //结束Y
	LCD_Write_COM(0x00,0x22);										 
}

/******************** 写汉字函数 *******************/
void ChineseChar(uint x,uint y,int size,uint For_color,uint Bk_color ,char c)
{
    uint e,i,j;
    uint  ed;
    uint  ncols;
    uint  nrows;
    uint  nbytes;
    uchar *pfont;
    uchar *pchar;
    uchar *fonttable[]={(uchar *)hz16,(uchar *)hz24 , (uchar *)hz32};
    pfont=(uchar *)fonttable[size];
	LCD_CS =0;  //打开片选使能
    if(size==0)
    {
        ncols =16-1;
        nrows =16-1;
        nbytes =32;	 //(16*16)/8
    }
    else
    {    
        if(size==1)
        {
            ncols =24-1;
            nrows =24-1;
            nbytes =72;  //(24*24)/8
        }
        else
        {
            if(size==2)
            {
                ncols =32-1;
                nrows =32-1;
                nbytes =132;   //(32*32)/8
            }
        }
    }
    pchar=pfont + (nbytes*(c-1));
    Address_set(x,  y, x+nrows,y+ncols);
    for(i=0;i<nbytes;i++)
    {
        ed=*pchar++;
        if(size==0)
        {
            if(i%2==0)
                e=8;
            else
                e=4;
        }
        else
            e=8;
        for(j=0;j<e;j++)
        {
            if((ed>>j)&0x01)
            { 
	           LCD_Write_DATA(For_color>>8 , For_color  );  //textcolor
	        }
            else
            {
                LCD_Write_DATA( Bk_color>>8 ,  Bk_color);  //backcolor
	        }
        }
    }
	LCD_CS =1;  //关闭片选使能
}

/******************** 写汉字字符串函数 *******************/
void ChineseString(uint x,uint y,int size,uint For_color,uint Bk_color ,char *p)
{         
    while(*p!='\0')
    {       
		ChineseChar(x,y,size,For_color,Bk_color,*p - 47);
        y+=24;
        p++;
    }
}

/******************** 字符显示函数 *******************/
void LCD_ShowChar(uint x,uint y,uint size, For_color,uint Bk_color, char ch)
{       
    uchar temp , Bytes;
    uchar pos,t;
    uint  CHAR_W,CHAR_H;
	LCD_CS =0;  //打开片选使能
	if(size == 0)
	{
	    CHAR_W = 24;         //16*24
	    CHAR_H = 16;
	}
	else if(size == 1)
	{

	}
    if(x>(LCD_SIZE_X-CHAR_W)||y>(LCD_SIZE_Y-CHAR_H))
        return;
    Address_set(x, y, x+CHAR_W-1, y+CHAR_H-1);
    ch = ch-32;                       //按照ASCII编码顺序的到相应字母的编码
    Bytes = (CHAR_W*CHAR_H)/8;
    for(pos=0;pos<Bytes;pos++)  //CHAR_H 	(CHAR_W*CHAR_H)/8
    {
		if(size == 0)
		{
			temp= Font16x24[ch][pos];
		}
		else if(size == 1)
		{	
		}
        for(t=0;t<8;t++) //CHAR_W
        {                 
	       if(temp&0x80)
	           LCD_Write_DATA(For_color>>8 , For_color  );  //textcolor
	       else 
	           LCD_Write_DATA(Bk_color>>8 , Bk_color );  //backcolor
           temp<<=1; 
        }
    }
	LCD_CS =1;  //关闭片选使能
}  

/******************** 显示字符串子函数 *******************/
// x,y:起点坐标    *p:字符串起始地址
void LCD_ShowString(uint x,uint y, uint size, uint For_color,uint Bk_color,char *p)
{         
    while(*p!='\0')
    {       
        LCD_ShowChar(x,y,size, For_color,Bk_color,*p);
        y+=16;
        p++;
    }
}

/******************** 显示启动界面函数 *******************/
void Display_Loding()
{
	Display_White();
	Display_Loading_Image();
	ChineseChar(50,79,2,colors[4],colors[7],1);		//正
    ChineseChar(50,122,2,colors[4],colors[7],2);	//在
    ChineseChar(50,165,2,colors[4],colors[7],3);	//启
    ChineseChar(50,208,2,colors[4],colors[7],4);	//动
}

/******************** 树莓派大logo加载函数 *******************/
void Display_Loading_Image()
{
    uchar i,j;
	LCD_CS =0;  //打开片选使能
	Address_set(100,115,219,214);
    LCD_DC=1;

	#pragma asm
		mov DPTR, #RaspberryPiLogoBig
	#pragma endasm

    for(j=0;j<99;j++)
    {

        for(i=119;i!=0;i--)
        {
            LCD_WR = 0;
			#pragma asm
				clr A
				movc A, @A+DPTR
				mov P2, A
				inc DPTR
				clr A
				movc A, @A+DPTR
				mov P0, A
				inc DPTR
			#pragma endasm
            LCD_WR = 1;
        }
    }
	LCD_CS = 1;  //关闭片选使能
}

/******************** 显示测试函数 *******************/
void Display_Running()
{
	Display_White();
	Display_Running_Image();
	ChineseString(215,70,1,colors[4],colors[7],"KL");
	LCD_ShowString(215,118,0,colors[4],colors[7], ":");
	ChineseString(215,134,1,colors[4],colors[1],"MN");
}

/******************** 显示测试函数1 *******************/
void Display_Running1()
{
	Display_White();
	Display_Running_Image();
	LCD_ShowString(215,70,0,colors[4],colors[7],	"What is a Raspb");	
	LCD_ShowString(185,70,0,colors[4],colors[7],	"erry Pi?"); 
	LCD_ShowString(155,70,0,colors[4],colors[7],	"The Raspberry P"); 
	LCD_ShowString(125,5,0,colors[4],colors[7],		"i is a credit-card ");
	LCD_ShowString(95,5,0,colors[4],colors[7],		"sized computer that");
	LCD_ShowString(65,5,0,colors[4],colors[7],		" plugs into your TV"); 
	LCD_ShowString(35,5,0,colors[4],colors[7],		" and a keyboard. It");
	LCD_ShowString(5,5,0,colors[4],colors[7],		" is a capable littl");
}

/******************** 显示测试函数2 *******************/
void Display_Running2()
{
	Display_White();
	Display_Running_Image();
	LCD_ShowString(215,70,0,colors[4],colors[7],"e computer whic");	
	LCD_ShowString(185,70,0,colors[4],colors[7],"h can be used i"); 
	LCD_ShowString(155,70,0,colors[4],colors[7],"n electronics p"); 
	LCD_ShowString(125,5,0,colors[4],colors[7],	"rojects, and for ma");
	LCD_ShowString(95,5,0,colors[4],colors[7],	"ny of the things th");
	LCD_ShowString(65,5,0,colors[4],colors[7],	"at your desktop PC "); 
	LCD_ShowString(35,5,0,colors[4],colors[7],	"does, like spreadsh");
	LCD_ShowString(5,5,0,colors[4],colors[7],	"eets, word-processi");
}

/******************** 显示测试函数3 *******************/
void Display_Running3()
{
	Display_White();
	Display_Running_Image();
	LCD_ShowString(215,70,0,colors[4],colors[7],"ng and games. I");	
	LCD_ShowString(185,70,0,colors[4],colors[7],"t also plays hig"); 
	LCD_ShowString(155,70,0,colors[4],colors[7],"h-definition vid"); 
	LCD_ShowString(125,5,0,colors[4],colors[7],"eo. We want to see i");
	LCD_ShowString(95,5,0,colors[4],colors[7],"t being used by kids");
	LCD_ShowString(65,5,0,colors[4],colors[7]," all over the world "); 
	LCD_ShowString(35,5,0,colors[4],colors[7],"to learn programming");
	LCD_ShowString(5,5,0,colors[4],colors[7],".");
}

/******************** 树莓派小logo加载函数 *******************/
void Display_Running_Image()
{
    uchar i,j;
	LCD_CS =0;  //打开片选使能
	Address_set(174,5,233,54);
    LCD_DC=1;

	#pragma asm
			mov DPTR, #RaspberryPiLogoSmall
	#pragma endasm

    for(j=0;j<50;j++)
    {

        for(i=60;i!=0;i--)
        {
            LCD_WR = 0;
			#pragma asm
				clr A
				movc A, @A+DPTR
				mov P2, A
				inc DPTR
				clr A
				movc A, @A+DPTR
				mov P0, A
				inc DPTR
			#pragma endasm
            LCD_WR = 1;
        }
    }
	LCD_CS =1;  //关闭片选使能
}

/******************** 并行数据写入函数 *******************/
void LCD_Writ_Bus(char VH,char VL)
{
	LCD_DataPortH=VH;	//高位P口
	LCD_DataPortL=VL;	//低位P口
	LCD_WR=0;
	LCD_WR=1;
}

/******************** 发送命令函数 *******************/
void LCD_Write_COM(char VH,char VL)
{	
	LCD_DC=0;
	LCD_Writ_Bus(VH,VL);
}

/******************** 发送数据函数 *******************/
void LCD_Write_DATA(char VH,char VL)	//发送数据
{
	LCD_DC=1;
	LCD_Writ_Bus(VH,VL);
}

/******************** 液晶初始化函数 *******************/
void LCD_Init(void)
{
	LCD_RST=0;
	delayms(5);
	LCD_RST=1;
	LCD_CS =0;  //打开片选使能
	LCD_Write_COM(0x00,0x10); LCD_Write_DATA(0x00,0x00);  // Power Control 1  current consumption  STB
	delayms(10);
	LCD_Write_COM(0x00,0x11); LCD_Write_DATA(0x00,0x1c);  // Power Control 2
	LCD_Write_COM(0x00,0x12); LCD_Write_DATA(0x12,0x12);  // Power Control 3  BT2-0, DC11-10, DC21-20, DC31-30
	LCD_Write_COM(0x00,0x13); LCD_Write_DATA(0x00,0x41);  // Power Control 4  DCR_EX=0, DCR2-0, GVD6-0
	LCD_Write_COM(0x00,0x14); LCD_Write_DATA(0x40,0x50);  // Power Control 5  VCOMG=0, VCM6-0, VCMR=0, VML6-0
	LCD_Write_COM(0x00,0x10); LCD_Write_DATA(0x08,0x00);  // Power Control 1 
	LCD_Write_COM(0x00,0x11); LCD_Write_DATA(0x01,0x1c);  // Power Control 2
	delayms(300);//300ms
	LCD_Write_COM(0x00,0x11); LCD_Write_DATA(0x03,0x1c);  // Power Control 2
	delayms(300);//300ms
	LCD_Write_COM(0x00,0x11); LCD_Write_DATA(0x07,0x1c);  // Power Control 2
	delayms(300);//300ms
	LCD_Write_COM(0x00,0x11); LCD_Write_DATA(0x0f,0x1c);  // Power Control 2
	delayms(600);//600ms
	LCD_Write_COM(0x00,0x11); LCD_Write_DATA(0x0f,0x39);  // Power Control 2
	delayms(500);//500ms
	LCD_Write_COM(0x00,0x01); LCD_Write_DATA(0x01,0x28);  // Driver Output Control
	LCD_Write_COM(0x00,0x02); LCD_Write_DATA(0x01,0x00);  // LCD-Driving-Waveform Control
	LCD_Write_COM(0x00,0x03); LCD_Write_DATA(0x10,0x30);  // Entry Mode
	LCD_Write_COM(0x00,0x08); LCD_Write_DATA(0x08,0x08);  // Frame Cycle Control 
	LCD_Write_COM(0x00,0x0b); LCD_Write_DATA(0x11,0x05);  // Frame Cycle Control
	LCD_Write_COM(0x00,0x0c); LCD_Write_DATA(0x00,0x00);  // External Display Interface Control 
    LCD_Write_COM(0x00,0x15); LCD_Write_DATA(0x00,0x20);  //VCI Recycling (R15H)		//		VCIR=010	 0X0020
	LCD_Write_COM(0x00,0x30); LCD_Write_DATA(0x00,0x00);  //		SCN 0	Start from G1
	LCD_Write_COM(0x00,0x34); LCD_Write_DATA(0x01,0x3f);  //		SE1 = 100111111( 319)
	LCD_Write_COM(0x00,0x35); LCD_Write_DATA(0x00,0x00);  //		SS1 = 000000000
	LCD_Write_COM(0x00,0x36); LCD_Write_DATA(0x00,0xef);  //		HEA = 011101111(239)
	LCD_Write_COM(0x00,0x37); LCD_Write_DATA(0x00,0x00);  //		HSA = 000000000	
	LCD_Write_COM(0x00,0x38); LCD_Write_DATA(0x01,0x3f);  //		VEA = 100111111( 319)
    LCD_Write_COM(0x00,0x39); LCD_Write_DATA(0x00,0x00);  //		VSA = 000000000	
    LCD_Write_COM(0x00,0x50); LCD_Write_DATA(0x01,0x01);  // Gamma Control
	LCD_Write_COM(0x00,0x51); LCD_Write_DATA(0x09,0x03);
	LCD_Write_COM(0x00,0x52); LCD_Write_DATA(0x0b,0x08);
	LCD_Write_COM(0x00,0x53); LCD_Write_DATA(0x08,0x05);
	LCD_Write_COM(0x00,0x54); LCD_Write_DATA(0x01,0x01);
	LCD_Write_COM(0x00,0x55); LCD_Write_DATA(0x0d,0x06);
	LCD_Write_COM(0x00,0x56); LCD_Write_DATA(0x0e,0x0a);
	LCD_Write_COM(0x00,0x57); LCD_Write_DATA(0x01,0x00);
	LCD_Write_COM(0x00,0x58); LCD_Write_DATA(0x1f,0x0b);
	LCD_Write_COM(0x00,0x59); LCD_Write_DATA(0x02,0x01);
	LCD_Write_COM(0x00,0x20); LCD_Write_DATA(0x00,0x00);  //Set RAM Address
	LCD_Write_COM(0x00,0x21); LCD_Write_DATA(0x00,0x00);  //Set RAM Address
	LCD_Write_COM(0x00,0x0f); LCD_Write_DATA(0x1f,0x01);  // Start Oscillation
	delayms(300);//300ms
	LCD_Write_COM(0x00,0x07); LCD_Write_DATA(0x00,0x16);  // Display Control
	delayms(200);//200ms
	LCD_Write_COM(0x00,0x07); LCD_Write_DATA(0x00,0x17);
	LCD_CS =1;
}

