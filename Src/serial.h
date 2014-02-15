//****************************************************************
//  CPU:STC12c5401AD_DIP28/MPC82G54AE_DIP28/ 
//  CRY:11.0592Mhz
//
//  从机串口程序        20071117
//****************************************************************
#define SLAVE   0x04
//slave address:供墨板

//STC89/12: ISP_IAP_EEPROM Register
/*
sfr ISP_DATA  = 0xe2;
sfr ISP_ADDRH = 0xe3;
sfr ISP_ADDRL = 0xe4;
sfr ISP_CMD   = 0xe5;
sfr ISP_TRIG  = 0xe6;
sfr ISP_CONTR = 0xe7;
*/
//STC10/11: 
sfr ISP_DATA  = 0xc2;
sfr ISP_ADDRH = 0xc3;
sfr ISP_ADDRL = 0xc4;
sfr ISP_CMD   = 0xc5;
sfr ISP_TRIG  = 0xc6;
sfr ISP_CONTR = 0xc7;
                   
//----------------------------------------------------------------
//  串口相关变量
//----------------------------------------------------------------
uchar bdata flag10;
sbit serial_flag    =   flag10^0;//接收
sbit send_flag      =   flag10^1;//发送
sbit TI_ing_flag    =   flag10^2; 
sbit viewget_flag   =   flag10^3;
sbit back_adc_flag  =   flag10^4;//返回pc当前AD值允许 

sbit s2_renew_flag  =   flag10^5;//标志给用户表示从机刷新数据

//----------------------------------------------------------------
uchar idata send_buff[8]={0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08};
uchar idata get_buff[8]={0,0,0,0,0,0,0,0};  //串口缓存

uchar get_i=0;  //读取数据的计数
//******************************************************************
//  串口中断程序                        
//------------------------------------------------------------------
/*
void Serial(void) interrupt 4 using 3
{ 
	uchar get_addr=0,get_data=0;//收到地址、收到数据、发送数据

    EA=0;
    ES=0;                   //关闭串口中断!!!
    //-----------------------------	 
	if(RI)
	{      
	    RI=0;                   //清零RI标志
	                            
		get_data=SBUF;          //接收的一个数据	
//----------------------------------------------------------------
        if(SM2==0)              //if sm2==0 接收的是数据帧 
        {                   
            get_buff[get_i]=get_data;
            get_i=get_i+1;
             
            if(get_i>get_buff[1])//0x05) 
            {
                s2_renew_flag=1;//标志串口数据更新
                get_i=0;        //进入用户程序判断
                
                SM2=1;          //置位SM2为1，下次接收的是地址帧
		        RB8=0;          //本协议接收3字节数据(+1字节CRC,暂无)  
            }
        } 
//----------------------------------------------------------------      
        else//if( SM2==1 )      //SM2==1从机处于监听地址方式,
        {                       //只有收到数据的RB==1，才表示是地址，再判断是否是本机地址
            if( ((RB8 == 1) && (get_data == SLAVE)) )   
            {                   
                SM2=0;          //清除SM2，准备接收下一字节是数据
		        RB8=0;          //清零
		        
		        get_i=0;        //清零，准备接收后面的数据
		        get_buff[get_i]=get_data;
		        get_i=1;    
            }      
        }
//----------------------------------------------------------------
	}
    if(TI)//发送完毕:中断  
    {
        TI=0;    
        if(send_en_flag)
        {
            send_en_flag=0;     //第一byte数据发送完毕，准备发送第二字节数据
           
            SBUF=send_buff[1];  //第二个数据返回 
        }
        else
        {
            send_ok_flag=1;     //两byte数据，发送完毕
            
            //SM2=1;//这里写这句没什么用处? 
        }
    }
    //-----------------------------	
	ES=1;                       //恢复串口中断 
    EA=1;                       //恢复总中断
}
*/
//******************************************************************
//  STC89/12(MPC89/82)软复位程序
//------------------------------------------------------------------

#define    RELOAD_COUNT    0xfd    //11.0592MHz,12T,SMOD=0,9600bps
#define    Self_Define_ISP_Download_Command    0x0d

//void serial_port_initial();
//void send_UART(unsigned char);
//void UART_Interrupt_Receive(void);
//void soft_reset_to_ISP_Monitor(void);

void soft_reset_to_ISP_Monitor(void)
{
    ISP_CONTR    =    0x60;   //0110，0000  软复位到系统ISP监控区
}
/*  (暂屏蔽:已改到主initsys里面了)
void serial_port_initial()
{
    SCON    =    0x50; //0101,0000 8位可变波特率，无奇偶校验位
    TMOD    =    0x21; //0011,0001 设置顶时器1为8位自动重装计数器
    
    TH1     =    RELOAD_COUNT;    //设置定时器1自动重装数
    TL1     =    RELOAD_COUNT;
    
    TR1     =    1;    //开定时器1
    ES      =    1;    //允许串口中断
    EA      =    1;    //开总中断
}
*/
void UART_Interrupt_Receive(void) interrupt 4
{
    unsigned char    k    =    0;
    unsigned char    m    =    0;
    
    if(RI==1)
    {
        RI   =    0;
        k    =    SBUF;
        if(k==Self_Define_ISP_Download_Command)        //是自定义下载命令
        {
            //delay();    //延时1秒就足够了
            //delay();    //延时1秒就足够了
            Delay(100); //zxy
            
            soft_reset_to_ISP_Monitor();    //软复位到系统ISP监控区
        }
        else
            SBUF=0xa5;  //Serial OK !!!
            //send_UART(0xa5);
    }
    else
    {
        TI    =    0;
    }
}

//******************************************************************
//  
//------------------------------------------------------------------