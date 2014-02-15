/*****************************************************************************

                         FAT3216 文件系统51裁剪版
                      (仅支持根目录文件搜索与读取)

*****************************************************************************/

#include "STC_NEW_8051.H"
#include "SD_MMC.h"
#include "FAT3216.h"
#include "s6d0154_drv.h"
#include "head.h"

LongByte  File_length, Next_cluster;
LongByte Addr;                   //SD卡数据物理地址
unsigned char gSector_count; //扇区计数器
unsigned char FatType;
unsigned int BPB_RootEntCnt;
unsigned char xdata Buffer[512];

unsigned long FAT_base;
unsigned long Dat_base;

unsigned char Cluster_size;
unsigned char Shift_bits;
//#define Cluster_size TH1
//#define Shift_bits   TL1
//char data * xdata str;         /* ptr in xdata to data char */
//int xdata * data numtab;       /* ptr in data to xdata int */
//long code * idata powtab;      /* ptr in idata to code long */

unsigned char idata BufferChar[16];
unsigned char idata* HEXtoASCL(unsigned long HEX, unsigned char index, unsigned char len)
{
  unsigned char i, j, temp;
  unsigned int tempi;
  if ((0==len)||((index+len)>15))
  {
    BufferChar[0]=0;
    return BufferChar;	
  }
  i=len&3;
  j=(len)>>2;
  if (!i)
  {
    j--;
	i=4;
  }
  if (j)
    tempi=(unsigned int)(HEX>>16);
  else
    tempi=HEX;
  do
  {
    for (;i!=0;i--)
    {
      if (4==i)
	    temp=tempi>>12;
      else if (3==i)
	    temp=tempi>>8;
      else if (2==i)
	    temp=tempi>>4;
	  else
	    temp=tempi;
	  temp&=0x0f;
	  if (temp>9)
	    BufferChar[index]=temp+'A'-10;
	  else
	    BufferChar[index]=temp+'0';
	  index++;
    }
	i=4;
    tempi=HEX;
  }while(0!=j--);
  BufferChar[index]=0;
  return BufferChar;	
}

unsigned char HalftoASC(unsigned char half)
{
  unsigned char i='0';
  if (half>9)
    i = 'A';
//  else 
//    half += '0';
  return half+i;
}

/******************************** 获取磁盘参数 ******************************/
unsigned char Get_disk_info(void)
{
    unsigned int  Reserved;     //保留区
    unsigned char Signature;    //启动扇区标识符
    unsigned char i, res;

/*    LCD_CS =0;  //打开片选使能
    Addr.all = 0x12345678;
    HEXtoASCL(Addr.all,0, 1);
	LCD_ShowString(0,0,colors[0],colors[4], BufferChar);
    HEXtoASCL(Addr.all,0, 2);
	LCD_ShowString(112,0,colors[1],colors[4], BufferChar);
    HEXtoASCL(Addr.all,0, 3);
	LCD_ShowString(0,24,colors[2],colors[4], BufferChar);
    HEXtoASCL(Addr.all,0, 4);
	LCD_ShowString(112,24,colors[3],colors[4], BufferChar);
    HEXtoASCL(Addr.all,0, 5);
	LCD_ShowString(0,48,colors[4],colors[7], BufferChar);
    HEXtoASCL(Addr.all,0, 6);
	LCD_ShowString(112,48,colors[5],colors[4], BufferChar);
    HEXtoASCL(Addr.all,0, 7);
	LCD_ShowString(0,72,colors[6],colors[4], BufferChar);
    HEXtoASCL(Addr.all,0, 8);
	LCD_ShowString(112,72,colors[7],colors[4], BufferChar);
*/    res=0;
    Addr.all = 0;               //指向0号扇区
    SD_send_read_cmd();         //发送读取指令
    Wait_start_token();         //等待SD卡响应

    Signature = SD_read_byte();  //读取首字节
    SD_read_byte();              //跳过1节字节
    Skip_nwords(222);           //跳过444字节

    if (Signature == 0xeb)      //是否为跳指令"0xeb"
    {                           //如是，判断为DBR扇区
        Skip_nwords(0x20);      //空读64字节
    }
    else                        //否则判断为MBR引导扇区
    {
        i = 4;                  //最多为4个分区
        while(1)                //顺序搜索4个分区信息
        {
            Read_nbytes(0x10);  //读取16字节分区信息
            if (Buffer[8] | Buffer[9])         //如不为零，信息有效
            {
                Addr.byte[0] = Buffer[11];     //获取分区起始扇区号
                Addr.byte[1] = Buffer[10];
                Addr.byte[2] = Buffer[9];
                Addr.byte[3] = Buffer[8];     
//    HEXtoASCL(Addr.all,0);
//	LCD_ShowString(0,0,colors[2],colors[4], BufferChar);
                Addr.all = Addr.all << 9;      //转换为地址
//    HEXtoASCL(Addr.all,0);
//	LCD_ShowString(0,24,colors[2],colors[4], BufferChar);
                while(--i) Read_nbytes(0x10);  //空读剩余字节
                break; 
            }
            else
            {
                if(--i == 0)
				{
				  Error(6);        //未找到分区信息，报错
				  res=1;
				}
            }
        }
    }

    Signature = SD_read_byte();                 //读取最后两字节
	i =	SD_read_byte();
    SD_read_block_complete();                  //结束一次块读操作
	if (res) return res;
    if (i != 0xaa || Signature != 0x55)        //最后两字节应为0x55aa
	{
	  Error(6);
	  res=2;
	  return res;
	}

    //---------------------- 读取DBR扇区进行处理 ---------------------------
    SD_send_read_cmd();                           //发送读取指令
    Wait_start_token();                           //等待SD卡响应
    Read_nbytes(64);                              //读取64字节

    //------------------ 分析扇区结构是否符合FAT32规范 ---------------------
    if (Buffer[0] != 0xeb)
	{
	  Error(7);              //跳转指令0xeb
	  res=3;
	}
    if (Buffer[0x0c] != 0x02 ||
        Buffer[0x0b] != 0x00 ||                   //扇区大小为应为512字节
//        Buffer[0x2c] != 0x02 ||                   //根目录簇号应为2
//       (Buffer[0x2d]|Buffer[0x2e]|Buffer[0x2f]) != 0 || 
        Buffer[0x10] != 0x02 ||                //FAT表应为两个
        Buffer[0x0d] == 0x00)           //每簇扇区数不能为0
	 {
	   Error(8);
	   res=4;
	 }
    //-------------------------- 保存有用的信息 ----------------------------
    Cluster_size = Buffer[0x0d];
    Reserved = Buffer[0x0e] + (Buffer[0x0f]<<8);  //保留区扇区数
    FAT_base = Addr.all + (Reserved<<9);          //FAT基址 = DBR基址 + 保留区大小

	for(Shift_bits = 9; (Buffer[0x0d] & 1) == 0; Shift_bits++) Buffer[0x0d] >>= 1;
                                                  //计算簇号转为地址时需要移位次数
    if (Buffer[0x16] == 0x00 &&
        Buffer[0x17] == 0x00)
	{
      FatType=1;
	  BPB_RootEntCnt=(Buffer[0x12]<<8)|Buffer[0x11];
	  File_length.byte[0] = Buffer[0x27];           //获取每个FAT占用的扇区数(最高字节为0)
      File_length.byte[1] = Buffer[0x26];
      File_length.byte[2] = Buffer[0x25];
      File_length.byte[3] = Buffer[0x24];
//      Dat_base = FAT_base + (File_length.all << 10);//根目录地址 = FAT基址 + 两个FAT大小
//      Dat_base -= 2ul << Shift_bits;				  //由于簇号从2算起，把数据区起始地址向前移2簇
	}
	else
	{
      FatType=0;
      File_length.byte[0] = 0;           //获取每个FAT占用的扇区数(最高字节为0)
      File_length.byte[1] = 0;
      File_length.byte[2] = Buffer[0x17];
      File_length.byte[3] = Buffer[0x16];
	  BPB_RootEntCnt=(Buffer[0x12]<<8)|Buffer[0x11];
	  File_length.all+=	(BPB_RootEntCnt>>5);		  //两个sector大小
//      Dat_base = FAT_base + (File_length.all << 10);//根目录地址 = FAT基址 + 两个FAT大小
//      Dat_base -= 2ul << Shift_bits;				  //由于簇号从2算起，把数据区起始地址向前移2簇
	}                
    Dat_base = FAT_base + (File_length.all << 10);//根目录地址 = FAT基址 + 两个FAT大小
    Dat_base -= 2ul << Shift_bits;				  //由于簇号从2算起，把数据区起始地址向前移2簇
    LCD_CS =0;  //打开片选使能
//    HEXtoASCL(FAT_base,0);
//	LCD_ShowString(0,72,colors[2],colors[4], BufferChar);
    HEXtoASCL(Dat_base,0,8);
	LCD_ShowString(0,96,colors[2],colors[4], BufferChar);

    Skip_nwords(223);                             //略过446字节
    Signature = SD_read_byte();                    //检测最后两字节应为0x55aa
    if (SD_read_byte() != 0xaa || Signature != 0x55) Error(7);
    SD_read_block_complete();                     //结束一次块读操作
    LCD_CS =0;  //打开片选使能
    LCD_ShowString(0,296,colors[7],colors[4],"Get disk in OK!");
    LCD_CS =1;  //关闭片选使能
	return res;
}

/***************************** 搜查根目录中的文件 ****************************/
unsigned char Scan_file(unsigned char n, unsigned char File_type)
{
    unsigned char Cluster_count;
    unsigned char Sector_count;
    unsigned char i,j,k;
    unsigned char code NameExt[] =            
    {
        " TXTBIN"                  
    };

//    LCD_CS =0;  //打开片选使能
//    LCD_ShowString(0,272,colors[0],colors[4],"Scaning file...");
    for (k = 3; k != 0; k--)                //预载文件名于Buffer，以便进行比较
    {
        Buffer[k + 2] = ' ';
        Buffer[k + 5] = ' ';
        Buffer[k + 7] = NameExt[File_type+k]; //
        Buffer[k - 1] = (n%10)+'0';          //依次载入个十百位的ASC码
        n = n / 10;                         //十进制右移一位
    }
	Buffer[11]=0;  
    LCD_CS =0;  //打开片选使能
    LCD_ShowString(0,272,colors[2],colors[4],Buffer);

    Cluster_count = 100;                    //限制根目录搜索深度，防止数据错误导致死读
	Next_cluster.all = 2;                   //根目录从簇号2开始
    if (FatType)
	{
//	  Next_cluster.all = 2;                   //根目录从簇号2开始
      gSector_count =	Cluster_size;
	}
	else
	{
      gSector_count =	32;
//	  Next_cluster.all = 0;                   //根目录从簇号2开始
	  Next_cluster.all -= (unsigned char)(BPB_RootEntCnt>>4)/Cluster_size;
	}
	do                                      //按簇链依次进行文件搜索
    {
        Sector_count = 0;
        Addr.all = Dat_base + (Next_cluster.all << Shift_bits); //计算簇基址
        do                                  //搜索簇内各个扇区
        {  
    LCD_ShowChar(208,272,colors[2],colors[4], HalftoASC(Cluster_count>>4));
    LCD_ShowChar(224,272,colors[2],colors[4], HalftoASC(Cluster_count&15));
            SD_send_read_cmd();             //发送读取指令
    HEXtoASCL(Addr.all,0,8);
	LCD_ShowString(0,248,colors[2],colors[4], BufferChar);
            Addr.all += 512;                //计算下一扇区地址
//    LCD_ShowString(0,224,colors[0],colors[4],"Wait token...");
            Wait_start_token();             //等待SD卡响应
            for (j = 16; j != 0; j--)       //搜索扇区内各个文件记录
            {   
                for (i = 0; i != 12; i++)   //比较文件名的11个字符
                {                           //只比较文件名前三位数字和扩展名，其它忽略
                    if (SD_read_byte() != Buffer[i] && (i & 0x07) < 3) break;
                }
                 
                if (i == 12)                                  //匹配成功
                {
                    Cluster_count = 0;                        //清零簇计数器，标记搜索完成
                    Read_nbytes(20);                          //获取文件记录信息
                    Next_cluster.byte[0] = Buffer[0x15-12];   //获取文件的起始簇号
                    Next_cluster.byte[1] = Buffer[0x14-12];
                    Next_cluster.byte[2] = Buffer[0x1b-12];
                    Next_cluster.byte[3] = Buffer[0x1a-12];
//                    if (!FatType)
//					  Next_cluster.all--;
					Addr.all = Dat_base + (Next_cluster.all << Shift_bits);//计算得文件的起始地址
					gSector_count = Cluster_size;        //扇区计数器初始化
//                    if (!FatType)
//					  Next_cluster.all++;

                    File_length.byte[0] = Buffer[0x1f-12];    //获取文件的长度
                    File_length.byte[1] = Buffer[0x1e-12];
                    File_length.byte[2] = Buffer[0x1d-12];
                    File_length.byte[3] = Buffer[0x1c-12];
                    File_length.all = File_length.all >> 9;   //计算文件占用的扇区数量

                    while(--j) Skip_nwords(16);               //读完一扇区的剩余字节
                    break;
                }
                else                                          //匹配不成功，则略过剩余字节
                {
                    i = 31 - i;
                    do
                    {
                         SD_read_byte();
                    }
                    while(--i);
                }
            }
            SD_read_block_complete();                         //结束一次块读操作

            if (Cluster_count == 0)
			{
    LCD_CS =0;  //打开片选使能
    HEXtoASCL(Addr.all,0,8);
	LCD_ShowString(0,224,colors[1],colors[4], BufferChar);
    LCD_ShowString(0,200,colors[7],colors[4],"Scan file OK!");
    LCD_CS =1;  //关闭片选使能
			  return 0;                 //搜索成功，返回
			}
        }
        while(++Sector_count != gSector_count);                //继续搜索簇内下一扇区

        if (!FatType)
		  return 1;
		else
		{
		  //------------------------- 根据簇链取得下一簇号 ------------------------------
          Set_block_size(0);                                    //设定SD卡块大小为4字节
          if (FatType)
		    Next_cluster.all = Next_cluster.all << 1;
		  Addr.all = FAT_base + (Next_cluster.all << 1);        //根据簇链计算链表地址
          SD_send_read_cmd();                                   //发送读取指令
//    LCD_ShowString(0,224,colors[2],colors[4],"Wait token...");
          Wait_start_token();                                   //等待SD卡响应
          Next_cluster.byte[3] = SD_read_byte();//获取下一簇簇号
          Next_cluster.byte[2] = SD_read_byte();
          Next_cluster.byte[1] = SD_read_byte();
          Next_cluster.byte[0] = SD_read_byte();
          SD_read_block_complete();             //结束一次块读操作

          Set_block_size(1);                    //重新设定SD卡块大小为512字节
//          if (FatType)
		  {
		    if (( Next_cluster.byte[3]            //判断是否为簇链结束标志 0x0fffffff
              & Next_cluster.byte[2]
              & Next_cluster.byte[1]) == 0xff
              && Next_cluster.byte[0]  == 0x0f)
              break;
		  }
/*		  else
		  {
            Next_cluster.byte[1] = 0;
            Next_cluster.byte[0] = 0;
		    if (( Next_cluster.byte[3]            //判断是否为簇链结束标志 0xffff
              & Next_cluster.byte[2]) == 0xff)
              break;
		  }
*/		}
    }
    while(--Cluster_count != 0);              //循环搜索下一簇，直至达到最大数目
    return 1;
}


unsigned char Readfile(void)
{
  unsigned char xdata * pBuffer;
  unsigned char i, j;

  //------------------- 发送扇区读取命令 -----------------
  SD_send_read_cmd();
  //-------------------- 读取一扇区数据 ---------------------
  Wait_start_token();         //等待SD卡响应
  pBuffer=Buffer;
  for (j=2; j!=0; j--)   //读取512字节
  {
    i=0;
	do
	{
	  *pBuffer = SD_read_byte();
	  pBuffer++;
	  i--;
	}while(i!=0);
  }
  SD_read_block_complete();                     //结束一次块读操作
    LCD_CS =0;  //打开片选使能
    LCD_ShowString(0,192,colors[1],colors[4],"Read file OK!");
    LCD_CS =1;  //关闭片选使能

            //------------------- 计算下一扇区地址 --------------------
            if (--gSector_count != 0)
            {                           //如在同一簇内
                Addr.all += 512;        //则下一扇区地址增加512
            }
            else                        //否则要查找下一簇地址
            {
                Set_block_size(0);                            //设定SD卡块大小为4字节
                if (FatType)
		          Next_cluster.all = Next_cluster.all << 1;
				Addr.all = FAT_base + (Next_cluster.all << 1);//根据簇链计算链表地址
                SD_send_read_cmd();                           //发送读取指令
                gSector_count = Cluster_size;                  //扇区计数器重置
                Wait_start_token();                           //等待SD卡响应
                Next_cluster.byte[3] = SD_read_byte();        //获取下一簇簇号
                Next_cluster.byte[2] = SD_read_byte();
                Next_cluster.byte[1] = SD_read_byte();
                Next_cluster.byte[0] = SD_read_byte();
                SD_read_block_complete();                     //结束一次块读操作
				if (!FatType)
				{
                  Next_cluster.byte[1] = 0;
                  Next_cluster.byte[0] = 0;
				}
                Addr.all = Dat_base + (Next_cluster.all << Shift_bits);//计算下一簇地址

                Set_block_size(1);                            //重新设定SD卡块大小为512字节

                if (FatType)
				{
                  if (( Next_cluster.byte[3]                    //判断是否为簇链结束标志 0x0fffffff
                      & Next_cluster.byte[2]
                      & Next_cluster.byte[1]) == 0xff
                     && Next_cluster.byte[0]  == 0x0f)
                    {return 0;}
				}                               //如果是，返回1
		        else
		        {
		          if (( Next_cluster.byte[3]            //判断是否为簇链结束标志 0xffff
                    & Next_cluster.byte[2]) == 0xff)
                    return 0;
		        }
            }                                                 
            File_length.all--;                                //文件长度递减
            if ((File_length.byte[1]                          //判断文件读完
               | File_length.byte[2]                          
               | File_length.byte[3]) == 0)                   
               {return 2;}									//如果是，返回2
  return 0;                                
}
/*
unsigned char Disp_TFImage(void)
{
//  unsigned char xdata * pBuffer;
  unsigned char i;
  unsigned int k;

    LCD_CS =0;  //打开片选使能
    HEXtoASCL(Addr.all,0,8);
	LCD_ShowString(0,296,colors[0],colors[4], BufferChar);
    LCD_ShowString(0,192,colors[1],colors[4],"Reading file...");
	LCD_CS =0;  //打开片选使能
	Address_set(0,0,239,319);
    LCD_DC=1;

  for (k=300; k!=0; k--)   //读取300 * 512字节
  {
  //------------------- 发送扇区读取命令 -----------------
  SD_send_read_cmd();
  //-------------------- 读取一扇区数据 ---------------------
  Wait_start_token();         //等待SD卡响应
  i=0;
//    pBuffer=Buffer;
//	do
//	{
//	  *pBuffer = SD_read_byte();
//	  pBuffer++;
//	  *pBuffer = SD_read_byte();
//	  pBuffer++;
//	  i--;
//	}while(i!=0);
//    pBuffer=Buffer;
	do
	{
      LCD_WR = 0;
//      P2 = SD_read_byte();
//      P2 = *pBuffer;
//	  pBuffer++;
//      P0 = SD_read_byte();
//      P2 = *pBuffer;
//	  pBuffer++;
 #pragma asm
		clr CLK
		mov c, MISO
		setb CLK
		rlc A
		clr CLK
		mov c, MISO
		setb CLK
		rlc A
		clr CLK
		mov c, MISO
		setb CLK
		rlc A
		clr CLK
		mov c, MISO
		setb CLK
		rlc A
		clr CLK
		mov c, MISO
		setb CLK
		rlc A
		clr CLK
		mov c, MISO
		setb CLK
		rlc A
		clr CLK
		mov c, MISO
		setb CLK
		rlc A
		clr CLK
		mov c, MISO
		setb CLK
		rlc A
		mov P2, A

		clr CLK
		mov c, MISO
		setb CLK
		rlc A
		clr CLK
		mov c, MISO
		setb CLK
		rlc A
		clr CLK
		mov c, MISO
		setb CLK
		rlc A
		clr CLK
		mov c, MISO
		setb CLK
		rlc A
		clr CLK
		mov c, MISO
		setb CLK
		rlc A
		clr CLK
		mov c, MISO
		setb CLK
		rlc A
		clr CLK
		mov c, MISO
		setb CLK
		rlc A
		clr CLK
		mov c, MISO
		setb CLK
		rlc A
		mov P0, A
#pragma endasm
      LCD_WR = 1;
	  i--;
	}while(i!=0);
    SD_read_block_complete();                     //结束一次块读操作
//    LCD_CS =0;  //打开片选使能
//    LCD_ShowString(0,192,colors[1],colors[4],"Read file OK!");
//    LCD_CS =1;  //关闭片选使能

            //------------------- 计算下一扇区地址 --------------------
            if (--gSector_count != 0)
            {                           //如在同一簇内
                Addr.all += 512;        //则下一扇区地址增加512
            }
            else                        //否则要查找下一簇地址
            {
                Set_block_size(0);                            //设定SD卡块大小为4字节
                if (FatType)
		          Next_cluster.all = Next_cluster.all << 1;
				Addr.all = FAT_base + (Next_cluster.all << 1);//根据簇链计算链表地址
                SD_send_read_cmd();                           //发送读取指令
                Addr.all = Dat_base + (Next_cluster.all << Shift_bits);//计算下一簇地址
                gSector_count = Cluster_size;                  //扇区计数器重置
                Wait_start_token();                           //等待SD卡响应
                Next_cluster.byte[3] = SD_read_byte();        //获取下一簇簇号
                Next_cluster.byte[2] = SD_read_byte();
                Next_cluster.byte[1] = SD_read_byte();
                Next_cluster.byte[0] = SD_read_byte();
                SD_read_block_complete();                     //结束一次块读操作

                Set_block_size(1);                            //重新设定SD卡块大小为512字节
                if (FatType)
				{
                  if (( Next_cluster.byte[3]                    //判断是否为簇链结束标志 0x0fffffff
                      & Next_cluster.byte[2]
                      & Next_cluster.byte[1]) == 0xff
                     && Next_cluster.byte[0]  == 0x0f)
                    {return 0;}
				}                               //如果是，返回1
		        else
		        {
                  Next_cluster.byte[1] = 0;
                  Next_cluster.byte[0] = 0;
		          if (( Next_cluster.byte[3]            //判断是否为簇链结束标志 0xffff
                    & Next_cluster.byte[2]) == 0xff)
                    return 0;
		        }
            }                                                 
            File_length.all--;                                //文件长度递减
            if ((File_length.byte[1]                          //判断文件读完
               | File_length.byte[2]                          
               | File_length.byte[3]) == 0)                   
               {return 2;}									//如果是，返回2
  }
  return 0;                                
}
*/