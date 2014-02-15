/*****************************************************************************

                     51系列模拟总线和模拟SPI显示图片
                         高度优化 V0.1 2012.11.10

*****************************************************************************/

#include "STC_NEW_8051.H"
#include "SD_MMC.h"
#include "s6d0154_drv.h"
#include "FAT3216.h"
#include "showimg51.h"
#include "picture.h"

extern LongByte  File_length, Next_cluster;
extern LongByte Addr;                   //SD卡数据物理地址

extern unsigned char gSector_count; //扇区计数器
extern unsigned char FatType;
extern unsigned long FAT_base;
extern unsigned long Dat_base;
extern unsigned char Cluster_size;
extern unsigned char Shift_bits;

//******************************************************************
//  ROM图片显示(仅240*80dot模式)
//------------------------------------------------------------------
void Show_ROMImage(void)
{
    unsigned char i,j,t;
   
	LCD_CS =0;  //打开片选使能
	Address_set(0,0,239,319);
    LCD_DC=1;
    for(t=4;t!=0;t--)  //显示4次->填满240x320空间
    {
#pragma asm
		mov DPTR, #Image
#pragma endasm
        
        for(j=80;j!=0;j--)
        {
            for(i=240;i!=0;i--)
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
    }
}

//******************************************************************
//  TF卡图片显示(240*320dot模式)
//------------------------------------------------------------------
unsigned char Show_TFImage(void)
{
//  unsigned char i;
  unsigned int k;

  LCD_CS =0;  //打开片选使能
  Address_set(0,0,239,319);
  LCD_DC=1;

  for (k=300; k!=0; k--)   //读取300 * 512字节
  {
  //------------------- 发送扇区读取命令 -----------------
  SD_send_read_cmd();
  //-------------------- 读取一扇区数据 ---------------------
  Wait_start_token();         //等待SD卡响应
//  i=0;
//  do
//  {
//    LCD_WR = 0;
//      P2 = SD_read_byte();
//      P2 = *pBuffer;
//      pBuffer++;
//      P0 = SD_read_byte();
//      P2 = *pBuffer;
//      pBuffer++;
//		为了兼容现有图片，互换了高低字节顺序
#pragma asm
		mov a, P4
		anl a, #0FBH
		mov r5, a
		orl a, #04H
		mov r6, a
		mov r7, #0
repTF1:	clr LCD_WR
		REPT 8
//		clr CLK
		mov P4, r5
		mov c, MISO
//		setb CLK
		mov P4, r6
		rlc A
		ENDM
		mov P0, A

		REPT 8
		mov P4, r5
		mov c, MISO
		mov P4, r6
		rlc A
		ENDM
/*		clr CLK
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
*/		mov P2, A
		setb LCD_WR
		djnz r7, repTF1
#pragma endasm

//      LCD_WR = 1;
//      i--;
//	}while(i!=0);
    SD_read_block_complete();                     //结束一次块读操作

    //------------------- 计算下一扇区地址 --------------------
    if (--gSector_count != 0)
    {                           //如在同一簇内
      Addr.all += 512;          //则下一扇区地址增加512
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
      if(!FatType)
	  {
        Next_cluster.byte[1] = 0;
        Next_cluster.byte[0] = 0;
	  }
	  SD_read_block_complete();                     //结束一次块读操作
      Addr.all = Dat_base + (Next_cluster.all << Shift_bits);//计算下一簇地址

      Set_block_size(1);                            //重新设定SD卡块大小为512字节

      if (FatType)
      {
        if (( Next_cluster.byte[3]                    //判断是否为簇链结束标志 0x0fffffff
            & Next_cluster.byte[2]
            & Next_cluster.byte[1]) == 0xff
           && Next_cluster.byte[0]  == 0x0f)
        {
		  return 0;
        }
      }                               //如果是，返回1
      else
      {
        if (( Next_cluster.byte[3]            //判断是否为簇链结束标志 0xffff
            & Next_cluster.byte[2]) == 0xff)
        {
          return 0;
        }
      }
    }                                                 
    File_length.all--;                                //文件长度递减
    if ((File_length.byte[1]                          //判断文件读完
       | File_length.byte[2]                          
       | File_length.byte[3]) == 0)                   
    {
      return 2;
    }									//如果是，返回2
  }
  return 0;                                
}
