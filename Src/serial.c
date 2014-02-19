/************************************************************/
/*项目：DisplayTerminalTFT
/*模块：串口模块
/*日期：2014年2月17日
/*修改：卜晓旸
/************************************************************/

#include "reg52stc.h"
#include "serial.h"


/******************** 显示数据缓存 *******************/

//年     月  日  时      分       状态  服务  cpu    内存    上传      下载      温度    IP地址
//0123	 45	 67	 9 10  12 13	   15	 17	  19 20	 22 23	25 26 27   29 30 31	 33 34	 36~50
uchar DisplayData[51] = "20140219,13:26,N,N,45,64,034,089,13,192.168.025.001";
uchar DisplayDataTemp[51] = "20140219,13:26,N,N,45,64,034,089,13,192.168.025.001";
//数据格式 BGI20140219,13:26,N,N,45,64,034,089,13,192.168.025.001STO

/******************** 全局变量定义 *******************/
uchar get_i=0;  //读取数据的计数
uchar LenToSend=0;
uint DataToSend;
#define    RELOAD_COUNT    0xe6    //12MHz,0xf3, 12T,SMOD=0,2400bps; 24MHz 0xe6
#define    Self_Define_ISP_Download_Command    0x7f

uchar readSerialCurrent = 0;
uchar readSerialNumber = 0;
uint readSerialTimeOut = 0; 
/******************** 延迟函数ms *******************/
void delayms(uint tt)
{
    uchar i;
	uchar j;
    while(tt>0)
    {
        tt--;
        for(j=0;j<5;j++)
	    {
		    for(i=0;i<168;i++)
			{
			}
        }
    }
}


/******************** 串口数据处理函数 *******************/
void readSerialProcess(uchar input)
{
	uchar i;
	switch(readSerialCurrent)
	{
		case 0:
			if(input == 'B')
				readSerialCurrent ++;
		break;	
		case 1:
			if(input == 'G')
				readSerialCurrent ++;	
			else
				readSerialCurrent = 0;
		break;	
		case 2:
			if(input == 'I')
			{
				readSerialCurrent ++;
				readSerialNumber = 0;	
			}
			else
				readSerialCurrent = 0;	
		break; 
		case 3:	 //read serial
			DisplayDataTemp[readSerialNumber] = input;
			readSerialNumber ++;	
			if(input == 'S')
				readSerialCurrent ++;
			if(readSerialNumber > 52)
				readSerialCurrent = 0;
		break;
		case 4:
			if(input == 'T')
				readSerialCurrent ++;	
			else
				readSerialCurrent = 0;
		case 5:
			if(input == 'O')
				readSerialCurrent ++;	
			else
				readSerialCurrent = 0;
		case 6:
			for(i=0; i<51; i++)
			{
				DisplayData[i] = DisplayDataTemp[i];	
			}
			readSerialTimeOut = 0;
			readSerialCurrent = 0;	
		break;
		default:
			readSerialCurrent = 0;
	}
}

/******************** 软复位函数 *******************/
void soft_reset_to_ISP_Monitor(void)
{
	IAP_CONTR = 0x60;   //0110，0000  软复位到系统ISP监控区
}

/******************** 串口接收中断函数 *******************/
void UART_Interrupt_Receive(void) interrupt 4 //using 1
{
	uchar k;
	if(RI==1)
	{
		RI = 0;
		k = SBUF;
		if((k==Self_Define_ISP_Download_Command)||(0x1f==k))        //是自定义下载命令
		{
			get_i++;
			if (10==get_i)
			{
				delayms(200); //zxy
				soft_reset_to_ISP_Monitor();    //软复位到系统ISP监控区
			}
		}
		else
		{
			if ((0==TI)&&(0==LenToSend))
			{
				SBUF=0xa5;  //Serial OK !!!
			}
			get_i=0;
		}
		readSerialProcess(k);
	}
	else
	{
		TI = 0;
		if (0!=LenToSend)
		{
			LenToSend--;
			if (0==LenToSend)
				SBUF=DataToSend>>8;
			else
				SBUF=DataToSend;
		}
	}	
}

/******************** 串口发送函数 *******************/
void SerialSend(uint Data, uchar Len)
{
	if (0==TI)
	{
		SBUF=Data;
		Len--;
	}
	LenToSend=Len;
	DataToSend=Data;
}

