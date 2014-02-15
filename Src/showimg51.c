/*****************************************************************************

                     51ϵ��ģ�����ߺ�ģ��SPI��ʾͼƬ
                         �߶��Ż� V0.1 2012.11.10

*****************************************************************************/

#include "STC_NEW_8051.H"
#include "SD_MMC.h"
#include "s6d0154_drv.h"
#include "FAT3216.h"
#include "showimg51.h"
#include "picture.h"

extern LongByte  File_length, Next_cluster;
extern LongByte Addr;                   //SD�����������ַ

extern unsigned char gSector_count; //����������
extern unsigned char FatType;
extern unsigned long FAT_base;
extern unsigned long Dat_base;
extern unsigned char Cluster_size;
extern unsigned char Shift_bits;

//******************************************************************
//  ROMͼƬ��ʾ(��240*80dotģʽ)
//------------------------------------------------------------------
void Show_ROMImage(void)
{
    unsigned char i,j,t;
   
	LCD_CS =0;  //��Ƭѡʹ��
	Address_set(0,0,239,319);
    LCD_DC=1;
    for(t=4;t!=0;t--)  //��ʾ4��->����240x320�ռ�
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
//  TF��ͼƬ��ʾ(240*320dotģʽ)
//------------------------------------------------------------------
unsigned char Show_TFImage(void)
{
//  unsigned char i;
  unsigned int k;

  LCD_CS =0;  //��Ƭѡʹ��
  Address_set(0,0,239,319);
  LCD_DC=1;

  for (k=300; k!=0; k--)   //��ȡ300 * 512�ֽ�
  {
  //------------------- ����������ȡ���� -----------------
  SD_send_read_cmd();
  //-------------------- ��ȡһ�������� ---------------------
  Wait_start_token();         //�ȴ�SD����Ӧ
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
//		Ϊ�˼�������ͼƬ�������˸ߵ��ֽ�˳��
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
    SD_read_block_complete();                     //����һ�ο������

    //------------------- ������һ������ַ --------------------
    if (--gSector_count != 0)
    {                           //����ͬһ����
      Addr.all += 512;          //����һ������ַ����512
    }
    else                        //����Ҫ������һ�ص�ַ
    {
      Set_block_size(0);                            //�趨SD�����СΪ4�ֽ�
      if (FatType)
        Next_cluster.all = Next_cluster.all << 1;
      Addr.all = FAT_base + (Next_cluster.all << 1);//���ݴ������������ַ
      SD_send_read_cmd();                           //���Ͷ�ȡָ��
      gSector_count = Cluster_size;                  //��������������
      Wait_start_token();                           //�ȴ�SD����Ӧ
      Next_cluster.byte[3] = SD_read_byte();        //��ȡ��һ�شغ�
      Next_cluster.byte[2] = SD_read_byte();
      Next_cluster.byte[1] = SD_read_byte();
      Next_cluster.byte[0] = SD_read_byte();
      if(!FatType)
	  {
        Next_cluster.byte[1] = 0;
        Next_cluster.byte[0] = 0;
	  }
	  SD_read_block_complete();                     //����һ�ο������
      Addr.all = Dat_base + (Next_cluster.all << Shift_bits);//������һ�ص�ַ

      Set_block_size(1);                            //�����趨SD�����СΪ512�ֽ�

      if (FatType)
      {
        if (( Next_cluster.byte[3]                    //�ж��Ƿ�Ϊ����������־ 0x0fffffff
            & Next_cluster.byte[2]
            & Next_cluster.byte[1]) == 0xff
           && Next_cluster.byte[0]  == 0x0f)
        {
		  return 0;
        }
      }                               //����ǣ�����1
      else
      {
        if (( Next_cluster.byte[3]            //�ж��Ƿ�Ϊ����������־ 0xffff
            & Next_cluster.byte[2]) == 0xff)
        {
          return 0;
        }
      }
    }                                                 
    File_length.all--;                                //�ļ����ȵݼ�
    if ((File_length.byte[1]                          //�ж��ļ�����
       | File_length.byte[2]                          
       | File_length.byte[3]) == 0)                   
    {
      return 2;
    }									//����ǣ�����2
  }
  return 0;                                
}
