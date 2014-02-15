#ifndef _HEAD_
#define _HEAD_

//******************************************************************
//  CPU:STC11L60XE
//  CRY:12Mhz
//  LCM:s6d0154-2.6 TFT
//  PCB:v1
//  NAM:²ÊÆÁ³ÌÐò                                            20120906
//******************************************************************

void HEXtoASC(unsigned int HEX, unsigned char index);
unsigned char HalftoASC(unsigned char half);
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
//******************************************************************
//  
//------------------------------------------------------------------

//---------------------------------

//******************************************************************
//  
//------------------------------------------------------------------
#endif // _HEAD_