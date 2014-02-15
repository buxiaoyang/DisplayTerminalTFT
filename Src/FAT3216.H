/*****************************************************************************

                         FAT32_16 文件系统51裁剪版
                      (仅支持根目录文件搜索与读取)

*****************************************************************************/
#ifndef _FAT3216_
#define _FAT3216_

typedef union _LongByte
{
    unsigned long all;
    unsigned char byte[4];
}LongByte, *pLongByte;
typedef union _LongWord
{
    unsigned long all;
    unsigned int word[2];
}LongWord, *pLongWord;

extern LongByte File_length, Next_cluster;
extern LongByte Addr;                              //SD卡数据物理地址
extern unsigned char xdata Buffer[512]; //_at_ 0x14; //通用数据缓冲区,
                                    //定位0x14是为了配合汇编程序

/******************************** 获取磁盘参数 ******************************/
unsigned char Get_disk_info(void);

/***************************** 搜查根目录中的文件 ****************************/
unsigned char Scan_file(unsigned char n, unsigned char File_type);

unsigned char Readfile(void);

unsigned char Disp_TFImage(void);

#endif // _FAT3216_
