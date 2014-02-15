//****************************************************************
//  CPU:STC12c5401AD_DIP28/MPC82G54AE_DIP28/ 
//  CRY:11.0592Mhz
//
//  �ӻ����ڳ���        20071117
//****************************************************************
#define SLAVE   0x04
//slave address:��ī��

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
//  ������ر���
//----------------------------------------------------------------
uchar bdata flag10;
sbit serial_flag    =   flag10^0;//����
sbit send_flag      =   flag10^1;//����
sbit TI_ing_flag    =   flag10^2; 
sbit viewget_flag   =   flag10^3;
sbit back_adc_flag  =   flag10^4;//����pc��ǰADֵ���� 

sbit s2_renew_flag  =   flag10^5;//��־���û���ʾ�ӻ�ˢ������

//----------------------------------------------------------------
uchar idata send_buff[8]={0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08};
uchar idata get_buff[8]={0,0,0,0,0,0,0,0};  //���ڻ���

uchar get_i=0;  //��ȡ���ݵļ���
//******************************************************************
//  �����жϳ���                        
//------------------------------------------------------------------
/*
void Serial(void) interrupt 4 using 3
{ 
	uchar get_addr=0,get_data=0;//�յ���ַ���յ����ݡ���������

    EA=0;
    ES=0;                   //�رմ����ж�!!!
    //-----------------------------	 
	if(RI)
	{      
	    RI=0;                   //����RI��־
	                            
		get_data=SBUF;          //���յ�һ������	
//----------------------------------------------------------------
        if(SM2==0)              //if sm2==0 ���յ�������֡ 
        {                   
            get_buff[get_i]=get_data;
            get_i=get_i+1;
             
            if(get_i>get_buff[1])//0x05) 
            {
                s2_renew_flag=1;//��־�������ݸ���
                get_i=0;        //�����û������ж�
                
                SM2=1;          //��λSM2Ϊ1���´ν��յ��ǵ�ַ֡
		        RB8=0;          //��Э�����3�ֽ�����(+1�ֽ�CRC,����)  
            }
        } 
//----------------------------------------------------------------      
        else//if( SM2==1 )      //SM2==1�ӻ����ڼ�����ַ��ʽ,
        {                       //ֻ���յ����ݵ�RB==1���ű�ʾ�ǵ�ַ�����ж��Ƿ��Ǳ�����ַ
            if( ((RB8 == 1) && (get_data == SLAVE)) )   
            {                   
                SM2=0;          //���SM2��׼��������һ�ֽ�������
		        RB8=0;          //����
		        
		        get_i=0;        //���㣬׼�����պ��������
		        get_buff[get_i]=get_data;
		        get_i=1;    
            }      
        }
//----------------------------------------------------------------
	}
    if(TI)//�������:�ж�  
    {
        TI=0;    
        if(send_en_flag)
        {
            send_en_flag=0;     //��һbyte���ݷ�����ϣ�׼�����͵ڶ��ֽ�����
           
            SBUF=send_buff[1];  //�ڶ������ݷ��� 
        }
        else
        {
            send_ok_flag=1;     //��byte���ݣ��������
            
            //SM2=1;//����д���ûʲô�ô�? 
        }
    }
    //-----------------------------	
	ES=1;                       //�ָ������ж� 
    EA=1;                       //�ָ����ж�
}
*/
//******************************************************************
//  STC89/12(MPC89/82)��λ����
//------------------------------------------------------------------

#define    RELOAD_COUNT    0xfd    //11.0592MHz,12T,SMOD=0,9600bps
#define    Self_Define_ISP_Download_Command    0x0d

//void serial_port_initial();
//void send_UART(unsigned char);
//void UART_Interrupt_Receive(void);
//void soft_reset_to_ISP_Monitor(void);

void soft_reset_to_ISP_Monitor(void)
{
    ISP_CONTR    =    0x60;   //0110��0000  ��λ��ϵͳISP�����
}
/*  (������:�Ѹĵ���initsys������)
void serial_port_initial()
{
    SCON    =    0x50; //0101,0000 8λ�ɱ䲨���ʣ�����żУ��λ
    TMOD    =    0x21; //0011,0001 ���ö�ʱ��1Ϊ8λ�Զ���װ������
    
    TH1     =    RELOAD_COUNT;    //���ö�ʱ��1�Զ���װ��
    TL1     =    RELOAD_COUNT;
    
    TR1     =    1;    //����ʱ��1
    ES      =    1;    //�������ж�
    EA      =    1;    //�����ж�
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
        if(k==Self_Define_ISP_Download_Command)        //���Զ�����������
        {
            //delay();    //��ʱ1����㹻��
            //delay();    //��ʱ1����㹻��
            Delay(100); //zxy
            
            soft_reset_to_ISP_Monitor();    //��λ��ϵͳISP�����
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