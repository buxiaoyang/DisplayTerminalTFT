/************************************************************/
/*项目：DisplayTerminalTFT
/*模块：串口模块头文件
/*日期：2014年2月17日
/*修改：卜晓旸
/************************************************************/

#ifndef _SERIAL_
#define _SERIAL_

#define uchar unsigned char
#define uint unsigned int

/******************** 函数定义 *******************/
void SerialSend(uint Data, uchar len);
void delayms(uint tt);

#endif
