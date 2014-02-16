//******************************************************************
//  文字
//------------------------------------------------------------------
const unsigned char code hz32[]={

//要把液晶头部向左倒下，而需要把字符向右倒下,取模要改宽高才正常：(字宽×字高＝33×32)PCtoLCD2002
//逐列式， 逆向， 垂直翻转

// 正(0) 在(1) 启(2) 动(3)

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x04,0x00,0x00,0x02,0x04,0x00,0x00,0x02,0x04,0x00,0x00,0x02,0xFC,0xFF,0x0F,0x02,
0xFC,0xFF,0x0F,0x02,0xFC,0xFF,0x07,0x02,0x04,0x00,0x06,0x02,0x04,0x00,0x00,0x02,0x04,0x00,0x00,0x02,0x04,0x00,0x00,0x02,0x04,0x00,0x00,0x02,0xFC,0xFF,0xFF,0x03,
0xFC,0xFF,0xFF,0x03,0xFC,0xFF,0xFF,0x03,0x04,0xC0,0x00,0x02,0x04,0xC0,0x00,0x02,0x04,0xC0,0x00,0x02,0x04,0xC0,0x00,0x02,0x04,0xC0,0x00,0x02,0x04,0xC0,0x00,0x02,
0x04,0xC0,0x01,0x02,0x04,0xC0,0x03,0x06,0x0C,0xC0,0x03,0x0E,0x1C,0xC0,0x00,0x0E,0x1C,0x40,0x00,0x0E,0x1C,0x00,0x00,0x06,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,/*"正",0*/
0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x0C,0x00,0x01,0x00,0x18,0x00,0x01,0x00,0x30,0x00,0x01,0x00,0x70,0x00,0x01,0x00,0xE0,0x00,0x01,0xFC,0xFF,0x03,0x01,
0xFC,0xFF,0x03,0x01,0xFC,0xFF,0x0F,0x01,0x10,0x00,0x1E,0x01,0x10,0x00,0x78,0x01,0x10,0x40,0xF0,0x01,0x10,0x40,0xE0,0x0F,0x10,0x40,0x80,0x7F,0x10,0x40,0x00,0x7F,
0x10,0x40,0x00,0x39,0x10,0x40,0x00,0x21,0xF0,0xFF,0x7F,0x01,0xF0,0xFF,0x7F,0x01,0xF0,0xFF,0x7F,0x01,0x10,0x40,0x00,0x01,0x10,0x40,0x00,0x01,0x10,0x40,0x00,0x01,
0x10,0x40,0x00,0x01,0x10,0xC0,0x00,0x01,0x10,0x80,0x01,0x03,0x30,0x80,0x01,0x06,0x30,0x80,0x00,0x06,0x30,0x00,0x00,0x02,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,/*"在",1*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0x70,0x00,0x00,0x00,0xE0,0x01,0x00,0x00,0xC0,0x3F,0x00,0x00,0x00,0xFF,0xFF,0x07,
0x00,0xF8,0xFF,0x07,0x00,0x00,0xFE,0x03,0x00,0x00,0x08,0x02,0xF8,0x7F,0x08,0x02,0xF8,0x7F,0x08,0x02,0xF8,0x7F,0x08,0x02,0x20,0x20,0x08,0x02,0x20,0x20,0x08,0x62,
0x20,0x20,0x08,0x7E,0x20,0x20,0x08,0x3E,0x20,0x20,0x08,0x1A,0x20,0x20,0x08,0x02,0x20,0x20,0x08,0x02,0x20,0x20,0x08,0x02,0x20,0x20,0x08,0x02,0x20,0x20,0x08,0x02,
0xF8,0x7F,0x08,0x02,0xF8,0x7F,0xFC,0x07,0xF8,0x7F,0xFC,0x07,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,/*"启",2*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x08,0x00,0x80,0x07,0x08,0x02,0x80,0x0F,0x08,0x02,0x00,0x39,0x08,0x02,0x00,0xF3,0x08,0x02,0x00,0xE3,0x0F,0x02,
0x00,0x83,0x0F,0x02,0x00,0x02,0x0F,0x02,0x00,0x02,0x0E,0x02,0x04,0x42,0x08,0x02,0x0C,0x72,0x08,0x06,0x08,0x3E,0x08,0x04,0x98,0x1F,0x18,0x04,0xF0,0x0F,0x10,0x00,
0xE0,0x03,0x50,0x00,0xC0,0x01,0x40,0x00,0x80,0x0F,0x40,0x00,0x00,0x7F,0x40,0x00,0x00,0xFC,0xFF,0x7F,0x10,0xF0,0xFF,0x7F,0x10,0x00,0xFE,0x3F,0x18,0x00,0x40,0x20,
0x1C,0x00,0x40,0x00,0x1C,0x00,0x40,0x00,0xF8,0x00,0x40,0x00,0xF8,0xFF,0xFF,0x00,0xE0,0xFF,0xFF,0x00,0x00,0xF8,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,/*"动",3*/




};

const unsigned char code hz24[] = {
/*
//--  文字:  带  --宋体18;  此字体下对应的点阵为：宽x高=24x24 
0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x18,0x03,0x80,0x10,0x01,0x80,0x10,0x11,0xFC,
0xFF,0x3F,0x80,0x10,0x01,0x80,0x10,0x01,0x80,0x18,0x01,0x00,0x00,0x20,0xF8,0xFF,
0x7F,0x0C,0x10,0x10,0x0C,0x10,0x08,0x40,0x10,0x06,0xC0,0xFF,0x05,0x40,0x10,0x04,
0x40,0x10,0x04,0x40,0x10,0x04,0x40,0x10,0x04,0x40,0x10,0x06,0x40,0xD0,0x07,0x00,
0x18,0x02,0x00,0x18,0x00,0x00,0x08,0x00,

//您
0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x18,0x00,0x60,0x18,0x00,0x20,0x0C,0x00,0x30,
0xFC,0x3F,0x30,0x22,0x08,0x28,0xC2,0x04,0x24,0x41,0x00,0x22,0x4C,0x02,0x20,0x44,
0x04,0x20,0x42,0x18,0x20,0x41,0x18,0xA0,0x78,0x10,0x20,0x60,0x00,0x00,0x04,0x00,
0x80,0x19,0x04,0x90,0x31,0x08,0x90,0x11,0x32,0x98,0x01,0x32,0x8C,0x01,0x22,0x80,
0x01,0x07,0x00,0xFF,0x03,0x00,0x00,0x00,

//进
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x02,0x10,0x10,0x02,0x30,0x10,0x02,0x60,
0x10,0x02,0x20,0x10,0x12,0x00,0xFF,0x0F,0x00,0x10,0x02,0x20,0x10,0x02,0x7E,0x10,
0x02,0x20,0x10,0x02,0x20,0x10,0x32,0x20,0xFF,0x0F,0x20,0x10,0x02,0x20,0x18,0x02,
0x20,0x08,0x02,0x20,0x04,0x02,0x30,0x02,0x02,0x4C,0x01,0x02,0x86,0x01,0x01,0x00,
0xFE,0x3F,0x00,0xF0,0x1F,0x00,0x00,0x00,

//入
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x03,0x00,0x00,0x04,0x00,0x00,
0x08,0x00,0x00,0x08,0x00,0x00,0x18,0x00,0x00,0x1C,0x00,0x00,0x3C,0x00,0x00,0x24,
0x00,0x00,0x26,0x00,0x00,0x42,0x00,0x00,0x43,0x00,0x00,0x81,0x00,0x80,0x80,0x01,
0xC0,0x00,0x03,0x60,0x00,0x06,0x30,0x00,0x0C,0x10,0x00,0x3C,0x08,0x00,0x30,0x06,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

//单
0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x81,0x01,0x00,0x83,0x00,0x00,0x42,0x00,0x00,
0x22,0x00,0xE0,0xFF,0x07,0x20,0x08,0x04,0x20,0x08,0x04,0x20,0x08,0x04,0xE0,0xFF,
0x07,0x20,0x08,0x04,0x20,0x08,0x04,0x20,0x08,0x04,0xE0,0xFF,0x07,0x20,0x08,0x00,
0x00,0x08,0x20,0xFE,0xFF,0x7F,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x00,
0x08,0x00,0x00,0x08,0x00,0x00,0x00,0x00,

//片
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0xC0,0x40,0x00,0x40,0x40,0x00,0x40,
0x40,0x00,0x40,0x40,0x00,0x40,0x40,0x10,0x40,0x40,0x38,0xC0,0xBF,0x07,0x40,0x00,
0x00,0x40,0x00,0x00,0x40,0x00,0x00,0xC0,0xFF,0x01,0x40,0x80,0x01,0x40,0x80,0x01,
0x60,0x80,0x01,0x20,0x80,0x01,0x20,0x80,0x01,0x10,0x80,0x01,0x18,0x80,0x01,0x08,
0x80,0x01,0x04,0x80,0x01,0x00,0x00,0x00,

//机
0x00,0x00,0x00,0x20,0x00,0x00,0x60,0x00,0x00,0x20,0x08,0x04,0x20,0xF8,0x07,0x20,
0x18,0x02,0x20,0x18,0x02,0xFE,0x1B,0x02,0x20,0x18,0x02,0x20,0x18,0x02,0x20,0x18,
0x02,0xF0,0x19,0x02,0x30,0x1B,0x02,0x30,0x1A,0x02,0x28,0x18,0x02,0x28,0x18,0x02,
0x24,0x08,0x02,0x22,0x08,0x22,0x22,0x0C,0x22,0x20,0x04,0x22,0x60,0x02,0x66,0x60,
0x02,0x7E,0xE0,0x01,0x00,0x00,0x00,0x00,

//世
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x06,0x10,0x0C,0x02,0x60,0x04,0x02,0x20,
0x04,0x02,0x20,0x04,0x02,0x20,0x04,0x02,0x20,0x04,0x32,0xFC,0xFF,0x0F,0x20,0x04,
0x02,0x20,0x04,0x02,0x20,0x04,0x02,0x20,0x04,0x02,0x20,0x04,0x02,0x20,0x04,0x02,
0x20,0xFC,0x03,0x20,0x04,0x02,0x20,0x04,0x00,0x20,0x00,0x00,0x20,0x00,0x20,0xF0,
0xFF,0x7F,0x20,0x00,0x00,0x00,0x00,0x00,

//界
0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x04,0xE0,0xFF,0x0F,0x60,0x18,0x04,0x60,
0x18,0x04,0xE0,0xFF,0x07,0x60,0x18,0x04,0x60,0x18,0x04,0x60,0x18,0x04,0xE0,0xEF,
0x07,0x00,0x46,0x00,0x00,0x83,0x00,0x80,0x01,0x03,0xC0,0x86,0x3D,0x20,0x82,0x38,
0x1C,0x82,0x00,0x00,0x83,0x00,0x00,0x81,0x00,0x80,0x81,0x00,0x80,0x80,0x00,0x60,
0x80,0x00,0x10,0x80,0x00,0x08,0x00,0x00,


//专
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x04,0x00,0x00,0x04,0x00,0x00,
0x04,0x06,0xF0,0xFF,0x01,0x00,0x06,0x00,0x00,0x02,0x00,0x00,0x02,0x30,0xFC,0xFF,
0x0F,0x00,0x03,0x00,0x00,0x01,0x00,0x00,0x01,0x00,0x80,0xFF,0x07,0x00,0x00,0x03,
0x00,0x00,0x01,0x00,0x80,0x00,0x00,0x46,0x00,0x00,0x3C,0x00,0x00,0x70,0x00,0x00,
0xE0,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,

//业 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x42,0x00,0x00,0x42,0x00,0x00,0x42,0x00,0x00,
0x42,0x00,0x00,0x42,0x00,0x04,0x42,0x10,0x04,0x42,0x38,0x08,0x42,0x18,0x10,0x42,
0x08,0x30,0x42,0x0C,0x30,0x42,0x04,0x60,0x42,0x06,0x60,0x42,0x02,0x60,0x42,0x01,
0x40,0xC2,0x00,0x00,0xC2,0x00,0x00,0x42,0x00,0x00,0x42,0x00,0x00,0x42,0x30,0xFE,
0xFF,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,

//技
0x00,0x00,0x00,0x20,0x00,0x00,0x60,0x80,0x01,0x60,0x80,0x00,0x60,0x80,0x00,0x60,
0x80,0x00,0x60,0x82,0x30,0xFC,0xFD,0x0F,0x60,0x80,0x00,0x60,0x80,0x00,0x60,0x80,
0x00,0x60,0xFF,0x1F,0xE0,0x10,0x08,0x7C,0x10,0x0C,0x64,0x20,0x04,0x60,0x20,0x06,
0x60,0x40,0x02,0x60,0x40,0x03,0x60,0x80,0x01,0x60,0xC0,0x01,0x60,0x20,0x06,0x78,
0x18,0x3C,0x30,0x07,0x30,0x00,0x00,0x00,

//术
0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x18,0x00,0x00,0x98,0x01,0x00,0x18,0x06,0x00,
0x18,0x04,0x00,0x18,0x00,0x00,0x18,0x30,0xFC,0xFF,0x0F,0x00,0x3C,0x00,0x00,0x3C,
0x00,0x00,0x5E,0x00,0x00,0x5B,0x00,0x00,0x99,0x00,0x80,0x98,0x01,0xC0,0x18,0x03,
0x60,0x18,0x06,0x30,0x18,0x0C,0x18,0x18,0x78,0x04,0x18,0x10,0x02,0x18,0x00,0x00,
0x18,0x00,0x00,0x18,0x00,0x00,0x00,0x00,

//论
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x30,0xE0,0x00,0x60,0xE0,0x00,0x60,
0x30,0x01,0x40,0x10,0x01,0x00,0x18,0x02,0x00,0x08,0x04,0x20,0x04,0x1C,0x7C,0x06,
0x78,0x20,0x39,0x10,0xA0,0x18,0x04,0x20,0x10,0x0E,0x20,0x10,0x01,0x20,0xD0,0x00,
0x20,0x32,0x00,0x20,0x11,0x00,0xA0,0x11,0x08,0xE0,0x10,0x08,0x60,0x10,0x10,0x20,
0x30,0x38,0x00,0xE0,0x0F,0x00,0x00,0x00,

//坛
0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x60,0x00,0x00,0x20,0x00,0x0C,0x20,
0xF8,0x03,0x20,0x00,0x00,0x20,0x00,0x00,0x20,0x01,0x00,0xFE,0x03,0x00,0x20,0x00,
0x30,0x20,0xFF,0x7F,0x20,0xC0,0x00,0x20,0xC0,0x00,0x20,0x40,0x00,0x20,0x20,0x00,
0x20,0x20,0x02,0x20,0x12,0x04,0xE0,0x11,0x08,0x3C,0x08,0x18,0x06,0x0C,0x3F,0x00,
0xFC,0x30,0x00,0x04,0x20,0x00,0x00,0x00,
*/

0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x18,0x00,0x40,0x18,0x06,0xA0,0xFF,0x01,0x10,0x18,0x00,0x00,0x18,0x30,0xFC,0xE7,0x0F,0x40,0x00,0x02,0xC0,0xFF,0x03,0x40,0x00,
0x02,0xC0,0xFF,0x03,0x40,0x21,0x00,0x00,0x62,0x10,0xFC,0xE3,0x3F,0x00,0x62,0x00,0x00,0x62,0x08,0xF8,0xE3,0x07,0x00,0x62,0x00,0x00,0xE2,0x3F,0xFC,0x63,0x00,0x00,
0x62,0x00,0x00,0x62,0x00,0x00,0x00,0x00,//靠0

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0xC0,0x01,0x00,0xC0,0x01,0x00,0xC0,0x00,0x00,0xC0,0x00,0x00,0xC0,0x00,0x00,0xC0,0x00,
0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x01,0x00,0xC0,0x01,0x00,0xC0,0x01,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//！0

0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x30,0x00,0x00,0x30,0x00,0x10,0x20,0x30,0xF0,0xDF,0x0F,0x30,0x30,0x00,0x30,0x30,0x00,0x30,0x30,0x00,0x10,0x30,0x18,0x10,0xF0,
0x07,0x10,0x30,0x00,0x10,0x30,0x00,0x10,0x30,0x00,0x10,0x31,0x08,0x10,0xCF,0x0F,0x10,0x01,0x08,0x18,0x01,0x08,0x08,0x01,0x08,0x08,0x01,0x08,0x04,0xFF,0x0F,0x04,
0x01,0x08,0x02,0x01,0x00,0x00,0x00,0x00,//店1

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x00,0x0C,0x00,0x00,0x18,0x00,0x00,0x18,0x00,0x00,0x08,0x10,0xF8,0xFF,0x3F,0x00,0x18,0x00,0x00,0x18,0x00,0x00,0x18,
0x00,0x00,0x18,0x00,0x00,0x18,0x00,0x00,0x18,0x04,0xF0,0xFF,0x0F,0x00,0x18,0x00,0x00,0x18,0x00,0x00,0x18,0x00,0x00,0x18,0x00,0x00,0x18,0x00,0x00,0x18,0x10,0xFE,
0xFF,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,//主2

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x18,0x60,0x00,0x30,0x20,0x10,0x30,0xFF,0x3F,0x00,0x10,0x00,0x00,0x58,0x00,0x00,0xC8,0x00,0x20,0xC4,0x00,0x3C,0xC6,
0x08,0x20,0xFE,0x1F,0x20,0xC0,0x00,0x20,0xC0,0x00,0x20,0xC0,0x10,0x20,0xFF,0x3F,0x20,0xC0,0x00,0x20,0xC0,0x00,0x30,0xC0,0x00,0xCC,0xC0,0x00,0x06,0x23,0x00,0x00,
0xFE,0x3F,0x00,0x80,0x1F,0x00,0x00,0x00,//连3

0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x18,0x00,0x00,0x1C,0x00,0x00,0x1C,0x00,0x00,0x26,0x00,0x00,0x43,0x00,0x00,0x81,0x00,0x80,0x89,0x01,0xC0,0x18,0x07,0x20,0x18,
0x1C,0x18,0x18,0x38,0x04,0x18,0x00,0x02,0x18,0x00,0x00,0x18,0x00,0x00,0x18,0x00,0x00,0x18,0x00,0x00,0x18,0x00,0x00,0x18,0x00,0x00,0x18,0x00,0x00,0x18,0x00,0x00,
0x18,0x00,0x00,0x18,0x00,0x00,0x00,0x00,//个4

0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x18,0x03,0x80,0x10,0x01,0x80,0x10,0x11,0xFC,0xFF,0x3F,0x80,0x10,0x01,0x80,0x10,0x01,0x80,0x18,0x01,0x00,0x00,0x20,0xF8,0xFF,
0x7F,0x0C,0x10,0x10,0x0C,0x10,0x08,0x40,0x10,0x06,0xC0,0xFF,0x05,0x40,0x10,0x04,0x40,0x10,0x04,0x40,0x10,0x04,0x40,0x10,0x04,0x40,0x10,0x06,0x40,0xD0,0x07,0x00,
0x18,0x02,0x00,0x18,0x00,0x00,0x08,0x00,//带5

0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x10,0xF8,0xFF,0x1F,0x18,0x06,0x10,0x18,0x82,0x10,0x18,0xFF,0x11,0x18,0x43,0x10,0x98,0x24,0x10,0x58,0x14,0x10,0x18,0x08,
0x10,0x18,0x34,0x10,0x18,0xE2,0x10,0x98,0x85,0x17,0x78,0x38,0x12,0x18,0x20,0x10,0x18,0x00,0x10,0x18,0x1E,0x10,0x18,0x70,0x10,0x18,0x40,0x10,0x18,0x00,0x10,0xF8,
0xFF,0x1F,0x18,0x00,0x10,0x00,0x00,0x00,//图6

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0xC0,0x40,0x00,0x40,0x40,0x00,0x40,0x40,0x00,0x40,0x40,0x00,0x40,0x40,0x10,0x40,0x40,0x38,0xC0,0xBF,0x07,0x40,0x00,
0x00,0x40,0x00,0x00,0x40,0x00,0x00,0xC0,0xFF,0x01,0x40,0x80,0x01,0x40,0x80,0x01,0x60,0x80,0x01,0x20,0x80,0x01,0x20,0x80,0x01,0x10,0x80,0x01,0x18,0x80,0x01,0x08,
0x80,0x01,0x04,0x80,0x01,0x00,0x00,0x00,//片7

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0xC0,0xFF,0x0F,0x40,0x00,0x06,0x40,0x00,0x06,0x40,0x00,0x06,0xC0,0xFF,0x07,0x40,0x00,0x06,0x40,0x00,0x06,0xC0,0xFF,
0x07,0x40,0x00,0x06,0x00,0x62,0x00,0x00,0x62,0x08,0x10,0x62,0x18,0x20,0x62,0x0C,0x60,0x62,0x04,0x40,0x62,0x02,0xC0,0x62,0x01,0x40,0xE2,0x00,0x00,0x62,0x10,0xFC,
0xFF,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,//显8

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0xE0,0xFF,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0xFC,0xFF,
0x0F,0x00,0x18,0x00,0x80,0x99,0x00,0xC0,0x18,0x01,0xC0,0x18,0x02,0x60,0x18,0x04,0x20,0x18,0x08,0x10,0x18,0x18,0x08,0x18,0x30,0x04,0x18,0x30,0x02,0x18,0x00,0x00,
0x1F,0x00,0x00,0x0C,0x00,0x00,0x00,0x00,//示9

0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x80,0x00,0x40,0xC0,0x00,0x40,0xC0,0x00,0x20,0x40,0x00,0xF8,0x67,0x30,0x08,0xA2,0x3F,0x08,0x32,0x10,0x08,0x12,0x10,0x08,0x0A,
0x10,0x08,0x22,0x10,0x08,0x42,0x10,0xF8,0xC3,0x10,0x08,0x82,0x10,0x08,0x82,0x10,0x08,0x02,0x10,0x08,0x02,0x10,0x08,0x02,0x10,0x08,0x02,0x18,0xF8,0x03,0x18,0x08,
0x82,0x0F,0x08,0x00,0x04,0x00,0x00,0x00,//的10

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x09,0x10,0xE0,0xFB,0x3F,0x5C,0x10,0x10,0x40,0x10,0x10,0x40,0x10,0x10,0x40,0x10,0x10,0x40,0x13,0x10,0xFC,0xFC,0x1F,0x60,0x08,
0x00,0xE0,0x00,0x30,0x70,0xF9,0x0F,0x50,0x03,0x01,0x50,0x02,0x01,0x48,0x00,0x01,0x48,0x00,0x11,0x44,0xF0,0x0F,0x42,0x00,0x01,0x40,0x00,0x01,0x60,0x00,0x21,0x60,
0xFE,0x7F,0x60,0x00,0x00,0x00,0x00,0x00,//程11

0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x18,0x00,0x00,0x10,0x10,0xF0,0xFF,0x3F,0x10,0x00,0x00,0x10,0x00,0x00,0x90,0xFF,0x0F,0x10,0x00,0x06,0x10,0x88,0x01,0x10,0x70,
0x00,0x10,0x60,0x00,0x10,0x20,0x30,0x90,0xFF,0x7F,0x10,0x60,0x18,0x18,0x60,0x04,0x08,0x60,0x00,0x08,0x60,0x00,0x08,0x60,0x00,0x04,0x60,0x00,0x04,0x60,0x00,0x02,
0x3C,0x00,0x00,0x30,0x00,0x00,0x00,0x00,//序12

0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x00,0x80,0x90,0x20,0x80,0xB0,0x3F,0xF8,0x9F,0x30,0x80,0x88,0x10,0x80,0x8C,0x10,0x80,0xA6,0x08,0xFC,0xFF,0x08,0x00,0x81,
0x04,0x80,0x80,0x08,0x50,0x98,0x10,0xB0,0x8F,0x30,0x28,0x88,0x20,0x26,0x88,0x20,0xE0,0x8F,0x20,0x20,0x88,0x20,0x20,0x88,0x3C,0x20,0x88,0x10,0xE0,0x8F,0x00,0x20,
0x88,0x00,0x20,0x80,0x00,0x00,0x00,0x00,//都13

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0xFC,0xFF,0x3F,0x00,0x10,0x00,0x00,0x18,0x00,0x00,0x08,0x00,0x00,0x0C,0x00,0x00,0x1C,0x00,0x00,0x1E,0x00,0x00,0x9B,
0x01,0x00,0x19,0x02,0x80,0x18,0x0C,0x40,0x18,0x18,0x20,0x18,0x38,0x10,0x18,0x30,0x08,0x18,0x20,0x06,0x18,0x00,0x00,0x18,0x00,0x00,0x18,0x00,0x00,0x18,0x00,0x00,
0x18,0x00,0x00,0x18,0x00,0x00,0x00,0x00,//不14

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0xF0,0xFF,0x0F,0x10,0x10,0x00,0x10,0x11,0x0C,0x10,0xEF,0x0F,0x10,0x01,0x0C,0x10,0xFF,0x0F,0x10,0x01,0x0C,0x10,0xFF,
0x0F,0x10,0x21,0x04,0x10,0x24,0x00,0x10,0x26,0x0F,0x10,0x21,0x18,0xD8,0x30,0x30,0x28,0x10,0x00,0x08,0x12,0x08,0x48,0x62,0x32,0x44,0x62,0x22,0x22,0x42,0x62,0x32,
0x02,0x06,0x10,0xFE,0x03,0x00,0x00,0x00,//愿15

0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x18,0x00,0x00,0x18,0x04,0xF8,0xFF,0x0F,0x00,0xC1,0x00,0x00,0x43,0x00,0x00,0x22,0x30,0xFC,0xFF,0x7F,0x00,0x00,0x00,0xE0,0xFF,
0x03,0x60,0x00,0x02,0x60,0x00,0x02,0xE0,0xFF,0x03,0x60,0x00,0x02,0xE0,0xFF,0x03,0x60,0x04,0x02,0x80,0x18,0x02,0x90,0x10,0x0D,0x90,0x10,0x19,0x88,0x00,0x31,0x8C,
0x00,0x31,0x80,0xFF,0x01,0x00,0x00,0x00,//意16

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x8C,0x00,0x20,0x06,0x03,0x30,0x06,0x06,0x30,0x06,0x06,0x10,0x02,0x00,0x18,0x02,0x30,0xE8,0xFF,0x0F,0x00,0x03,0x00,0x00,0x03,
0x00,0x00,0xFF,0x07,0x00,0x05,0x06,0x80,0x05,0x02,0x80,0x08,0x01,0xC0,0x90,0x01,0x40,0x90,0x00,0x60,0x60,0x00,0x20,0x60,0x00,0x10,0xB0,0x01,0x08,0x0C,0x07,0x04,
0x02,0x7C,0xC2,0x01,0x10,0x00,0x00,0x00,//发17

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x18,0x00,0x00,0x18,0x00,0x30,0x18,0x0C,0x30,0x18,0x04,0x30,0x18,0x04,0x30,0x18,0x04,0x30,0x18,0x04,0x30,0x18,
0x04,0xF0,0xFF,0x07,0x00,0x18,0x0C,0x00,0x18,0x00,0x10,0x18,0x08,0x10,0x18,0x18,0x10,0x18,0x08,0x10,0x18,0x08,0x10,0x18,0x08,0x10,0x18,0x08,0x10,0x18,0x08,0xF8,
0xE7,0x0F,0x00,0x00,0x08,0x00,0x00,0x00,//出18

0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x18,0x00,0x00,0x18,0x00,0x00,0x18,0x00,0x00,0x18,0x18,0xF0,0xFF,0x07,0x20,0x18,0x06,0xC0,0x18,0x02,0x80,0x19,0x01,0x80,0x98,
0x00,0x00,0x58,0x30,0xFC,0xBF,0x0F,0x00,0x3C,0x00,0x00,0x5E,0x00,0x00,0xDB,0x00,0x00,0x99,0x00,0x80,0x18,0x03,0x40,0x18,0x06,0x20,0x18,0x1C,0x18,0x18,0x78,0x04,
0x18,0x10,0x00,0x18,0x00,0x00,0x00,0x00,//来19

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x00,0x00,0x78,0x00,0x00,0x30,0x00,0x00,0x20,0x00,0x00,0x10,0x00,0x00,0x08,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//，20

0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x03,0x80,0xFF,0x03,0x80,0x00,0x03,0x80,0x00,0x03,0x80,0xFF,0x03,0x80,0x00,0x03,0x80,0x00,0x03,0x80,0x00,0x03,0x80,0xFF,
0x03,0x00,0x00,0x10,0x00,0x00,0x38,0xF8,0xFF,0x07,0x80,0x10,0x00,0xC0,0x10,0x08,0x40,0xF0,0x1F,0x40,0x10,0x00,0xE0,0x10,0x00,0x20,0x13,0x00,0x10,0x1C,0x00,0x08,
0xF0,0x3F,0x04,0x00,0x1F,0x00,0x00,0x00,//是21

0x00,0x00,0x00,0x00,0x00,0x00,0x60,0xB0,0x00,0x20,0x70,0x03,0x20,0x10,0x03,0x20,0x18,0x22,0x20,0xF9,0x7F,0xFC,0x08,0x01,0x20,0x0C,0x01,0x20,0x0C,0x01,0x20,0x0B,
0x31,0xE0,0xFA,0x0F,0x30,0x09,0x01,0x3C,0x09,0x01,0x26,0x08,0x01,0x20,0x08,0x31,0x20,0xF8,0x0F,0x20,0x08,0x01,0x20,0x08,0x01,0x20,0x08,0x21,0x20,0x08,0x71,0x38,
0xF8,0x0E,0x30,0x08,0x00,0x00,0x00,0x00,//推22

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x30,0x00,0x00,0x30,0x10,0xF0,0xFF,0x3F,0x10,0x00,0x00,0x10,0x00,0x00,0x10,0x00,0x00,0x10,0x00,0x00,0x10,0x00,
0x00,0x10,0x00,0x00,0x10,0x00,0x00,0x10,0x00,0x00,0x10,0x00,0x00,0x10,0x00,0x00,0x18,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x04,0x00,0x00,0x04,
0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,//广23

0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x08,0x00,0x00,0x18,0x00,0x00,0x10,0x10,0xFC,0xFF,0x3F,0x80,0x80,0x00,0x00,0x81,0x03,0x00,0x82,0x00,0x00,0x82,0x00,0x00,0x42,
0x10,0xF0,0xFF,0x3F,0x10,0x00,0x00,0x10,0x00,0x00,0x10,0x00,0x00,0x10,0x00,0x00,0x10,0x00,0x00,0x10,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x04,
0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,//产24

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0xFF,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0xFF,0x01,0x80,0x00,
0x01,0x00,0x00,0x00,0x00,0x02,0x00,0xF8,0xE7,0x1F,0x08,0x62,0x10,0x08,0x62,0x10,0x08,0x62,0x10,0x08,0x62,0x10,0x08,0x62,0x10,0x08,0x62,0x10,0xF8,0xE3,0x1F,0x08,
0x62,0x10,0x08,0x20,0x00,0x00,0x00,0x00,//品25

0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x80,0x00,0x40,0xC0,0x00,0x40,0xC0,0x00,0x20,0x40,0x00,0xF8,0x67,0x30,0x08,0xA2,0x3F,0x08,0x32,0x10,0x08,0x12,0x10,0x08,0x0A,
0x10,0x08,0x22,0x10,0x08,0x42,0x10,0xF8,0xC3,0x10,0x08,0x82,0x10,0x08,0x82,0x10,0x08,0x02,0x10,0x08,0x02,0x10,0x08,0x02,0x10,0x08,0x02,0x18,0xF8,0x03,0x18,0x08,
0x82,0x0F,0x08,0x00,0x04,0x00,0x00,0x00,//的26

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x08,0x00,0x00,0x0C,0x00,0x00,0x0C,0x18,0xFC,0xFF,0x07,0x00,0x14,0x00,0x00,0x26,0x00,0x00,0x22,0x00,0x00,0x43,
0x00,0x80,0x87,0x01,0xC0,0x1C,0x07,0x30,0x30,0x3E,0x0C,0x30,0x10,0x80,0x0C,0x02,0x80,0x19,0x04,0x90,0x30,0x18,0x90,0x20,0x39,0x98,0x00,0x31,0x8C,0x00,0x01,0x8C,
0x81,0x03,0x00,0xFF,0x01,0x00,0x00,0x00,//态27

0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x10,0x00,0x00,0x30,0x00,0x10,0x10,0x30,0xF0,0xEF,0x0F,0x10,0x0C,0x03,0x10,0x04,0x01,0x10,0x04,0x31,0xF0,0xFF,0x0F,0x10,0x04,
0x01,0x10,0x04,0x01,0x10,0xFC,0x01,0x18,0x02,0x00,0x98,0xFF,0x07,0x08,0x04,0x03,0x08,0x08,0x01,0x08,0x88,0x01,0x08,0xD0,0x00,0x04,0x60,0x00,0x04,0xD8,0x01,0x02,
0x06,0x3F,0xE2,0x01,0x1C,0x00,0x00,0x00,//度28

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x38,0x00,0x00,0x0C,0x00,0x00,0x0C,0x00,0x00,0x06,0x00,0x00,0x03,0x00,0x00,0xC1,0x01,0x80,0xC0,0x00,0x40,0x60,
0x00,0x20,0x60,0x00,0x10,0x30,0x00,0x08,0x18,0x00,0x04,0x88,0x00,0x00,0x04,0x01,0x00,0x02,0x02,0x00,0x01,0x06,0x80,0x00,0x0C,0xE0,0xFF,0x1B,0xE0,0x03,0x18,0x00,
0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,//么29

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x03,0x00,0x10,0x06,0x00,0x10,0x04,0x00,0x18,0x04,0x00,0x10,0x06,0x00,0x00,0x02,0x00,0x00,0x03,
0x00,0x80,0x01,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0xC0,0x01,0x00,0xC0,0x01,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//？30

};

//******************************************************************
//  
//------------------------------------------------------------------

const unsigned char code hz16[]= {
    
/*--  文字:  专  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
0x80,0x00,0x80,0x00,0xFC,0x1F,0x40,0x00,0x40,0x00,0xFF,0x7F,0x20,0x00,0x10,0x04,
0xF0,0x0F,0x00,0x04,0x00,0x02,0x40,0x01,0x80,0x00,0x00,0x01,0x00,0x02,0x00,0x00,

/*--  文字:  业  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
0x20,0x02,0x20,0x02,0x20,0x02,0x20,0x22,0x22,0x62,0x24,0x32,0x24,0x12,0x28,0x0A,
0x38,0x0A,0x28,0x06,0x20,0x02,0x20,0x02,0x20,0x22,0xFF,0x7F,0x00,0x00,0x00,0x00,

/*--  文字:  技  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
0x08,0x04,0x08,0x04,0x08,0x04,0xBF,0x7F,0x08,0x04,0x28,0x04,0x98,0x3F,0x8C,0x10,
0x0B,0x11,0x08,0x09,0x08,0x06,0x08,0x06,0x08,0x09,0x88,0x70,0x6A,0x20,0x04,0x00,

/*--  文字:  术  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
0x80,0x00,0x80,0x04,0x80,0x08,0x80,0x00,0xFF,0x7F,0x80,0x00,0xC0,0x01,0xA0,0x02,
0xA0,0x04,0x90,0x08,0x88,0x18,0x84,0x70,0x83,0x20,0x80,0x00,0x80,0x00,0x00,0x00,

/*--  文字:  论  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
0x02,0x02,0x04,0x02,0x0C,0x05,0x04,0x09,0x80,0x10,0x40,0x60,0xA7,0x20,0x84,0x08,
0x84,0x1C,0x84,0x03,0x84,0x00,0xA4,0x00,0x94,0x20,0x8C,0x20,0x04,0x3F,0x00,0x00,

/*--  文字:  坛  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
0x00,0x00,0x88,0x3F,0x08,0x00,0x08,0x00,0x08,0x00,0x3F,0x00,0xC8,0x7F,0x08,0x02,
0x08,0x06,0x08,0x01,0x38,0x11,0x8C,0x20,0x43,0x7E,0xE0,0x63,0x40,0x20,0x00,0x00,

};
//******************************************************************
//  
//------------------------------------------------------------------






