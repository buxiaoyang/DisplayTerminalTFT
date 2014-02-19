/************************************************************/
/*项目：DisplayTerminalTFT
/*模块：ASCII字库
/*日期：2014年2月17日
/*修改：卜晓旸
/************************************************************/


/******************** 16*24字库 *******************/
// 取模方式：逐列式，顺向，16*24  
const unsigned char code Font16x24[96][48] =
{ 
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*" ",0*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0E,0x3F,0xF8,
	0x0E,0x3F,0xF8,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"!",1*/
	{0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x78,0x00,0x00,0x1E,
	0x00,0x00,0x66,0x00,0x00,0x78,0x00,0x00,0x1E,0x00,0x00,0x06},/*""",2*/
	{0x00,0xC3,0x00,0x0F,0xFF,0x00,0x0F,0xFF,0xF0,0x00,0xC3,0xF0,
	0x0F,0xFF,0x00,0x0F,0xFF,0xF0,0x00,0xC3,0xF0,0x00,0xC3,0x00},/*"#",3*/
	{0x00,0x00,0x00,0x0F,0x07,0xC0,0x1F,0x1F,0xE0,0x7F,0xFF,0xF8,
	0x7F,0xFF,0xF8,0x1F,0xF1,0xE0,0x0F,0xC1,0xC0,0x00,0x00,0x00},/*"$",4*/
	{0x00,0x1F,0xC0,0x18,0x20,0x20,0x07,0x9F,0xC0,0x00,0x70,0x00,
	0x0F,0xEF,0x00,0x10,0x10,0xE0,0x0F,0xE0,0x00,0x00,0x00,0x00},/*"%",5*/
	{0x07,0xE0,0x00,0x1F,0xFF,0xC0,0x18,0x7F,0xE0,0x19,0xFC,0x20,
	0x1F,0x8F,0xE0,0x1F,0xFF,0xC0,0x1C,0xFC,0x00,0x18,0x04,0x00},/*"&",6*/
	{0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x04,0x00,0x00,0x0C,
	0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"`",7*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xFF,0x00,
	0x0F,0xFF,0xE0,0x3E,0x00,0xF8,0x70,0x00,0x1C,0x40,0x00,0x04},/*"(",8*/
	{0x00,0x00,0x00,0x60,0x00,0x0C,0x70,0x00,0x3C,0x1E,0x00,0xF0,
	0x0F,0xFF,0xC0,0x01,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*")",9*/
	{0x00,0x42,0x00,0x00,0x66,0x00,0x00,0x7E,0x00,0x03,0xFF,0xC0,
	0x03,0xFF,0xC0,0x00,0x7E,0x00,0x00,0x66,0x00,0x00,0x42,0x00},/*"*",10*/
	{0x00,0x10,0x00,0x00,0x10,0x00,0x00,0x10,0x00,0x03,0xFF,0x80,
	0x03,0xFF,0x80,0x00,0x10,0x00,0x00,0x10,0x00,0x00,0x10,0x00},/*"+",11*/
	{0x80,0x00,0x00,0xCC,0x00,0x00,0x7C,0x00,0x00,0x3C,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*",",12*/
	{0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x10,0x00,0x00,0x10,0x00,
	0x00,0x10,0x00,0x00,0x10,0x00,0x00,0x10,0x00,0x00,0x10,0x00},/*"-",13*/
	{0x00,0x00,0x00,0x1C,0x00,0x00,0x1C,0x00,0x00,0x1C,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*".",14*/
	{0x00,0x00,0x00,0x60,0x00,0x00,0x7E,0x00,0x00,0x1F,0xC0,0x00,
	0x01,0xF8,0x00,0x00,0x3F,0x80,0x00,0x07,0xF0,0x00,0x00,0x7C},/*"/",15*/
	{0x00,0x00,0x00,0x03,0xFF,0x00,0x0F,0xFF,0xC0,0x1C,0x00,0xE0,
	0x10,0x00,0x20,0x1C,0x00,0xE0,0x0F,0xFF,0xC0,0x03,0xFF,0x00},/*"0",16*/
	{0x00,0x00,0x00,0x10,0x00,0x80,0x10,0x00,0x80,0x1F,0xFF,0xC0,
	0x1F,0xFF,0xC0,0x10,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00},/*"1",17*/
	{0x00,0x00,0x00,0x1C,0x03,0xC0,0x1F,0x03,0xE0,0x1B,0x80,0x20,
	0x18,0xE0,0x20,0x18,0x70,0x60,0x1E,0x1F,0xE0,0x1E,0x0F,0x80},/*"2",18*/
	{0x00,0x00,0x00,0x0F,0x03,0xC0,0x1F,0x03,0xE0,0x10,0x10,0x20,
	0x10,0x10,0x20,0x18,0x38,0x60,0x0F,0xEF,0xE0,0x07,0xC7,0x80},/*"3",19*/
	{0x00,0x00,0x00,0x00,0xF0,0x00,0x00,0xFC,0x00,0x10,0x8F,0x80,
	0x10,0x83,0xC0,0x1F,0xFF,0xF0,0x1F,0xFF,0xF0,0x10,0x80,0x00},/*"4",20*/
	{0x00,0x00,0x00,0x0F,0x3F,0xE0,0x1F,0x3F,0xE0,0x10,0x18,0x60,
	0x10,0x08,0x60,0x1C,0x18,0x60,0x0F,0xF0,0x60,0x03,0xE0,0x60},/*"5",21*/
	{0x00,0x00,0x00,0x03,0xFF,0x00,0x0F,0xFF,0xC0,0x1C,0x18,0xE0,
	0x10,0x08,0x20,0x1C,0x18,0xE0,0x0F,0xF0,0xC0,0x03,0xE0,0x00},/*"6",22*/
	{0x00,0x00,0x00,0x00,0x01,0xE0,0x00,0x01,0xE0,0x1F,0xE0,0x60,
	0x1F,0xFE,0x60,0x00,0x1F,0xE0,0x00,0x01,0xE0,0x00,0x00,0x60},/*"7",23*/
	{0x00,0x00,0x00,0x07,0x87,0xC0,0x0F,0xEF,0xE0,0x18,0x78,0x20,
	0x10,0x30,0x20,0x18,0x78,0x60,0x1F,0xEF,0xE0,0x07,0x87,0x80},/*"8",24*/
	{0x00,0x00,0x00,0x00,0x1F,0x80,0x0C,0x3F,0xC0,0x1C,0x60,0x60,
	0x10,0x40,0x20,0x1C,0x70,0xE0,0x0F,0xFF,0xC0,0x03,0xFF,0x00},/*"9",25*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x0E,0x00,
	0x1C,0x0E,0x00,0x1C,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*":",26*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x78,0x0C,0x00,
	0x38,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*";",27*/
	{0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x7C,0x00,0x00,0xEE,0x00,
	0x03,0x83,0x80,0x0F,0x01,0xE0,0x1C,0x00,0x70,0x10,0x00,0x10},/*"<",28*/
	{0x00,0x84,0x00,0x00,0x84,0x00,0x00,0x84,0x00,0x00,0x84,0x00,
	0x00,0x84,0x00,0x00,0x84,0x00,0x00,0x84,0x00,0x00,0x84,0x00},/*"=",29*/
	{0x00,0x00,0x00,0x18,0x00,0x30,0x1C,0x00,0x70,0x07,0x01,0xC0,
	0x03,0x83,0x80,0x00,0xEE,0x00,0x00,0x7C,0x00,0x00,0x10,0x00},/*">",30*/
	{0x00,0x00,0x00,0x00,0x03,0xC0,0x00,0x03,0xE0,0x1C,0x03,0x30,
	0x1C,0xE0,0x10,0x1C,0xF8,0x30,0x00,0x1F,0xF0,0x00,0x07,0xC0},/*"?",31*/
	{0x03,0xFF,0x00,0x0F,0xFF,0x80,0x1D,0xFC,0xE0,0x19,0xFF,0x60,
	0x11,0xFF,0x20,0x19,0xFF,0xE0,0x0F,0xFF,0xC0,0x06,0x7F,0x80},/*"@",32*/
	{0x10,0x00,0x00,0x1F,0x80,0x00,0x1F,0xFE,0x00,0x10,0x7F,0xE0,
	0x00,0x4F,0xE0,0x11,0xFF,0x80,0x1F,0xF0,0x00,0x1E,0x00,0x00},/*"A",33*/
	{0x10,0x00,0x20,0x1F,0xFF,0xE0,0x1F,0xFF,0xE0,0x10,0x10,0x20,
	0x10,0x18,0x60,0x18,0x3F,0xE0,0x0F,0xE7,0xC0,0x07,0xC0,0x00},/*"B",34*/
	{0x03,0xFE,0x00,0x0F,0xFF,0x80,0x1C,0x01,0xC0,0x10,0x00,0x60,
	0x10,0x00,0x20,0x1C,0x00,0x60,0x0E,0x01,0xE0,0x02,0x01,0xE0},/*"C",35*/
	{0x10,0x00,0x20,0x1F,0xFF,0xE0,0x1F,0xFF,0xE0,0x10,0x00,0x20,
	0x10,0x00,0x20,0x1E,0x00,0xE0,0x0F,0xFF,0xC0,0x01,0xFF,0x00},/*"D",36*/
	{0x10,0x00,0x20,0x1F,0xFF,0xE0,0x1F,0xFF,0xE0,0x10,0x10,0x20,
	0x10,0x7C,0x20,0x18,0x7C,0x20,0x1C,0x00,0xE0,0x0C,0x00,0xC0},/*"E",37*/
	{0x10,0x00,0x20,0x1F,0xFF,0xE0,0x1F,0xFF,0xE0,0x10,0x10,0x20,
	0x00,0x7C,0x20,0x00,0x7C,0x60,0x00,0x00,0xE0,0x00,0x00,0xC0},/*"F",38*/
	{0x03,0xFF,0x00,0x0F,0xFF,0xC0,0x1C,0x00,0xE0,0x10,0x00,0x20,
	0x10,0x40,0x20,0x1F,0xC0,0xE0,0x0F,0xC0,0xE0,0x00,0x40,0x00},/*"G",39*/
	{0x10,0x00,0x20,0x1F,0xFF,0xE0,0x1F,0xFF,0xE0,0x10,0x10,0x20,
	0x00,0x10,0x00,0x10,0x10,0x20,0x1F,0xFF,0xE0,0x1F,0xFF,0xE0},/*"H",40*/
	{0x00,0x00,0x00,0x10,0x00,0x20,0x10,0x00,0x20,0x1F,0xFF,0xE0,
	0x1F,0xFF,0xE0,0x10,0x00,0x20,0x10,0x00,0x20,0x00,0x00,0x00},/*"I",41*/
	{0x60,0x00,0x00,0xE0,0x00,0x00,0x80,0x00,0x20,0xC0,0x00,0x20,
	0x7F,0xFF,0xE0,0x3F,0xFF,0xE0,0x00,0x00,0x20,0x00,0x00,0x20},/*"J",42*/
	{0x10,0x00,0x20,0x1F,0xFF,0xE0,0x1F,0xFF,0xE0,0x10,0x3E,0x20,
	0x01,0xFF,0xA0,0x1F,0xC1,0xE0,0x1E,0x00,0x60,0x10,0x00,0x20},/*"K",43*/
	{0x10,0x00,0x20,0x1F,0xFF,0xE0,0x1F,0xFF,0xE0,0x10,0x00,0x20,
	0x10,0x00,0x00,0x10,0x00,0x00,0x1C,0x00,0x00,0x1C,0x00,0x00},/*"L",44*/
	{0x10,0x00,0x20,0x1F,0xFF,0xE0,0x1F,0xFF,0xE0,0x1F,0xFF,0xE0,
	0x1F,0xFF,0xE0,0x1F,0xFF,0xE0,0x1F,0xFF,0xE0,0x10,0x00,0x20},/*"M",45*/
	{0x10,0x00,0x20,0x1F,0xFF,0xE0,0x1F,0xFF,0xE0,0x10,0x1F,0xE0,
	0x00,0xFE,0x00,0x07,0xE0,0x20,0x1F,0xFF,0xE0,0x1F,0xFF,0xE0},/*"N",46*/
	{0x03,0xFF,0x00,0x0F,0xFF,0xC0,0x1C,0x00,0xE0,0x10,0x00,0x20,
	0x10,0x00,0x20,0x1E,0x00,0xE0,0x0F,0xFF,0xC0,0x01,0xFF,0x00},/*"O",47*/
	{0x10,0x00,0x20,0x1F,0xFF,0xE0,0x1F,0xFF,0xE0,0x10,0x20,0x20,
	0x00,0x20,0x20,0x00,0x30,0x60,0x00,0x1F,0xC0,0x00,0x0F,0x80},/*"P",48*/
	{0x03,0xFF,0x00,0x0F,0xFF,0xC0,0x1F,0x00,0xE0,0x11,0x00,0x20,
	0x3F,0x00,0x20,0x7E,0x00,0xE0,0x6F,0xFF,0xC0,0x63,0xFF,0x00},/*"Q",49*/
	{0x10,0x00,0x20,0x1F,0xFF,0xE0,0x1F,0xFF,0xE0,0x10,0x10,0x20,
	0x00,0xF0,0x20,0x07,0xF8,0x60,0x1F,0x8F,0xE0,0x1C,0x07,0xC0},/*"R",50*/
	{0x00,0x00,0x00,0x1E,0x07,0xC0,0x1E,0x0F,0xE0,0x18,0x18,0x20,
	0x10,0x30,0x20,0x18,0x60,0x60,0x1F,0xC0,0xE0,0x07,0x80,0xE0},/*"S",51*/
	{0x00,0x00,0xE0,0x00,0x00,0xE0,0x10,0x00,0x20,0x1F,0xFF,0xE0,
	0x1F,0xFF,0xE0,0x10,0x00,0x20,0x00,0x00,0xE0,0x00,0x00,0xE0},/*"T",52*/
	{0x00,0x00,0x20,0x0F,0xFF,0xE0,0x1F,0xFF,0xE0,0x18,0x00,0x20,
	0x10,0x00,0x00,0x18,0x00,0x20,0x1F,0xFF,0xE0,0x07,0xFF,0xE0},/*"U",53*/
	{0x00,0x00,0x20,0x00,0x03,0xE0,0x01,0xFF,0xE0,0x1F,0xFC,0x20,
	0x1F,0xC0,0x00,0x07,0xFE,0x20,0x00,0x3F,0xE0,0x00,0x01,0xE0},/*"V",54*/
	{0x00,0x7F,0xE0,0x1F,0xFF,0xE0,0x1F,0xF0,0x20,0x01,0xFF,0xE0,
	0x01,0xFF,0xE0,0x1F,0xF0,0x20,0x1F,0xFF,0xE0,0x00,0x7F,0xE0},/*"W",55*/
	{0x10,0x00,0x20,0x18,0x00,0xE0,0x1F,0x07,0xE0,0x17,0xFF,0x20,
	0x00,0xFC,0x00,0x13,0xFF,0xA0,0x1F,0x03,0xE0,0x1C,0x00,0xE0},/*"X",56*/
	{0x00,0x00,0x20,0x00,0x01,0xE0,0x10,0x1F,0xE0,0x1F,0xFE,0x20,
	0x1F,0xFF,0x20,0x10,0x0F,0xE0,0x00,0x01,0xE0,0x00,0x00,0x20},/*"Y",57*/
	{0x18,0x00,0xC0,0x1F,0x00,0xE0,0x17,0xC0,0x60,0x10,0xF8,0x20,
	0x10,0x3E,0x20,0x18,0x07,0xE0,0x1E,0x01,0xE0,0x0E,0x00,0x20},/*"Z",58*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xFF,0xFC,
	0x7F,0xFF,0xFC,0x40,0x00,0x04,0x40,0x00,0x04,0x40,0x00,0x04},/*"[",59*/
	{0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x01,0xF0,0x00,0x1F,0xC0,
	0x01,0xFE,0x00,0x1F,0xE0,0x00,0xFE,0x00,0x00,0xE0,0x00,0x00},/*"\",60*/
	{0x00,0x00,0x00,0x40,0x00,0x04,0x40,0x00,0x04,0x40,0x00,0x04,
	0x7F,0xFF,0xFC,0x7F,0xFF,0xFC,0x00,0x00,0x00,0x00,0x00,0x00},/*"]",61*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x1C,
	0x00,0x00,0x0C,0x00,0x00,0x0C,0x00,0x00,0x1C,0x00,0x00,0x10},/*"^",62*/
	{0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,
	0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00},/*"_",63*/
	{0x00,0x00,0x80,0x00,0x00,0xCC,0x00,0x00,0x7C,0x00,0x00,0x3C,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"'",64*/
	{0x00,0x00,0x00,0x0F,0x18,0x00,0x1F,0xDC,0x00,0x18,0xC4,0x00,
	0x10,0x64,0x00,0x18,0x24,0x00,0x1F,0xFC,0x00,0x1F,0xF8,0x00},/*"a",65*/
	{0x00,0x00,0x20,0x0F,0xFF,0xE0,0x0F,0xFF,0xE0,0x18,0x0C,0x00,
	0x10,0x04,0x00,0x1C,0x1C,0x00,0x0F,0xF8,0x00,0x03,0xE0,0x00},/*"b",66*/
	{0x00,0x00,0x00,0x07,0xE0,0x00,0x0F,0xF8,0x00,0x18,0x1C,0x00,
	0x10,0x04,0x00,0x18,0x04,0x00,0x1C,0x3C,0x00,0x04,0x38,0x00},/*"c",67*/
	{0x00,0x00,0x00,0x07,0xF0,0x00,0x0F,0xF8,0x00,0x18,0x0C,0x00,
	0x10,0x04,0x00,0x18,0x0C,0x20,0x1F,0xFF,0xE0,0x1F,0xFF,0xE0},/*"d",68*/
	{0x00,0x00,0x00,0x07,0xF0,0x00,0x0F,0xF8,0x00,0x18,0x4C,0x00,
	0x10,0x44,0x00,0x10,0x4C,0x00,0x1C,0x7C,0x00,0x0C,0x70,0x00},/*"e",69*/
	{0x00,0x00,0x00,0x10,0x04,0x00,0x10,0x04,0x00,0x1F,0xFF,0xC0,
	0x1F,0xFF,0xE0,0x10,0x04,0x60,0x10,0x04,0x20,0x00,0x04,0xE0},/*"f",70*/
	{0x00,0x00,0x00,0x7E,0xF8,0x00,0xFF,0xFC,0x00,0xCD,0x8C,0x00,
	0x8D,0x0C,0x00,0x89,0xFC,0x00,0xF8,0xFC,0x00,0x78,0x0C,0x00},/*"g",71*/
	{0x10,0x00,0x20,0x1F,0xFF,0xE0,0x1F,0xFF,0xE0,0x10,0x0C,0x00,
	0x00,0x04,0x00,0x10,0x04,0x00,0x1F,0xFC,0x00,0x1F,0xF8,0x00},/*"h",72*/
	{0x00,0x00,0x00,0x10,0x04,0x00,0x10,0x04,0x60,0x1F,0xFC,0x60,
	0x1F,0xFC,0x60,0x10,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00},/*"i",73*/
	{0x00,0x00,0x00,0xC0,0x00,0x00,0xC0,0x00,0x00,0x80,0x04,0x00,
	0xC0,0x04,0x60,0xFF,0xFC,0x60,0x3F,0xFC,0x60,0x00,0x00,0x00},/*"j",74*/
	{0x10,0x00,0x20,0x1F,0xFF,0xE0,0x1F,0xFF,0xE0,0x11,0xE0,0x00,
	0x13,0xFC,0x00,0x1F,0xBC,0x00,0x1C,0x0C,0x00,0x10,0x04,0x00},/*"k",75*/
	{0x00,0x00,0x00,0x10,0x00,0x20,0x10,0x00,0x20,0x1F,0xFF,0xF0,
	0x1F,0xFF,0xF0,0x10,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00},/*"l",76*/
	{0x10,0x04,0x00,0x1F,0xFC,0x00,0x1F,0xFC,0x00,0x10,0x0C,0x00,
	0x1F,0xFC,0x00,0x1F,0xFC,0x00,0x10,0x0C,0x00,0x1F,0xFC,0x00},/*"m",77*/
	{0x10,0x04,0x00,0x1F,0xFC,0x00,0x1F,0xFC,0x00,0x10,0x0C,0x00,
	0x00,0x04,0x00,0x10,0x04,0x00,0x1F,0xFC,0x00,0x1F,0xF8,0x00},/*"n",78*/
	{0x00,0x00,0x00,0x07,0xF0,0x00,0x0F,0xF8,0x00,0x18,0x0C,0x00,
	0x10,0x04,0x00,0x18,0x0C,0x00,0x0F,0xF8,0x00,0x07,0xF0,0x00},/*"o",79*/
	{0x80,0x04,0x00,0xFF,0xFC,0x00,0xFF,0xFC,0x00,0x98,0x0C,0x00,
	0x10,0x04,0x00,0x1C,0x1C,0x00,0x0F,0xF8,0x00,0x03,0xE0,0x00},/*"p",80*/
	{0x00,0x00,0x00,0x07,0xF0,0x00,0x0F,0xF8,0x00,0x18,0x0C,0x00,
	0x10,0x04,0x00,0x98,0x0C,0x00,0xFF,0xFC,0x00,0xFF,0xFC,0x00},/*"q",81*/
	{0x10,0x04,0x00,0x10,0x04,0x00,0x1F,0xFC,0x00,0x1F,0xFC,0x00,
	0x10,0x18,0x00,0x10,0x0C,0x00,0x00,0x0C,0x00,0x00,0x0C,0x00},/*"r",82*/
	{0x00,0x00,0x00,0x1C,0x78,0x00,0x1C,0x7C,0x00,0x18,0xC4,0x00,
	0x10,0xC4,0x00,0x11,0x84,0x00,0x1F,0x9C,0x00,0x0F,0x1C,0x00},/*"s",83*/
	{0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x06,0x00,0x0F,0xFF,0xC0,
	0x1F,0xFF,0xC0,0x18,0x04,0x00,0x08,0x04,0x00,0x00,0x00,0x00},/*"t",84*/
	{0x00,0x04,0x00,0x0F,0xFC,0x00,0x1F,0xFC,0x00,0x18,0x00,0x00,
	0x10,0x00,0x00,0x18,0x04,0x00,0x1F,0xFC,0x00,0x1F,0xFC,0x00},/*"u",85*/
	{0x00,0x04,0x00,0x00,0x1C,0x00,0x03,0xFC,0x00,0x1F,0xE4,0x00,
	0x1F,0x00,0x00,0x03,0xE4,0x00,0x00,0xFC,0x00,0x00,0x1C,0x00},/*"v",86*/
	{0x01,0xFC,0x00,0x1F,0xFC,0x00,0x1F,0xC4,0x00,0x03,0xFC,0x00,
	0x03,0xFC,0x00,0x1F,0xC4,0x00,0x1F,0xFC,0x00,0x01,0xFC,0x00},/*"w",87*/
	{0x00,0x00,0x00,0x10,0x04,0x00,0x1C,0x1C,0x00,0x1F,0x7C,0x00,
	0x13,0xF4,0x00,0x1F,0xFC,0x00,0x1C,0x1C,0x00,0x10,0x04,0x00},/*"x",88*/
	{0xC0,0x04,0x00,0xC0,0x1C,0x00,0xC0,0xFC,0x00,0xFF,0xE4,0x00,
	0x3F,0x00,0x00,0x07,0xF4,0x00,0x00,0xFC,0x00,0x00,0x0C,0x00},/*"y",89*/
	{0x00,0x00,0x00,0x18,0x1C,0x00,0x1E,0x1C,0x00,0x17,0x84,0x00,
	0x11,0xE4,0x00,0x10,0x7C,0x00,0x1C,0x1C,0x00,0x1C,0x04,0x00},/*"z",90*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x10,0x00,0x3F,0xFF,0xF8,0x7F,0xEF,0xFC,0x60,0x00,0x0C},/*"{",91*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00},/*"|",92*/
	{0x00,0x00,0x00,0x40,0x00,0x04,0x60,0x00,0x0C,0x7F,0xEF,0xFC,
	0x3F,0xFF,0xF8,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"}",93*/
	{0x00,0x00,0x00,0x00,0x00,0x1C,0x00,0x00,0x1E,0x00,0x00,0x02,
	0x00,0x00,0x0E,0x00,0x00,0x1C,0x00,0x00,0x30,0x00,0x00,0x20},/*"~",94*/
};


