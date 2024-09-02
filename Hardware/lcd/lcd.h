#ifndef __LCD_H__
#define __LCD_H__

#include "main.h"
#include "spi.h"

#define NO_OPERATION            0x00    // 无操作
#define SWRESET                 0x01    // 软件复位
#define READ_DISPLAY_ID         0x04    // 读显示ID
#define READ_DISPLAY_STATUS     0x09    // 读显示状态
#define READ_DISPLAY_POWER      0x0A    // 读显示电源
#define READ_DISPLAY            0x0B    // 读显示
#define READ_DISPLAY_PIXEL      0x0C    // 读显示像素
#define READ_DISPLAY_IMAGE      0x0D    // 读显示图像
#define READ_DISPLAY_SIGNAL     0x0E    // 读显示信号
#define READ_DISPLAY_SD_RESULT  0x0F    // 读显示自检结果
#define SLEEP_IN                0x10    // 进入休眠模式
#define SLEEP_OUT               0x11    // 退出休眠模式
#define PART_MODE_ON            0x12    // 部分模式开启
#define PART_MODE_OFF           0x13    // 部分模式关闭
#define INVOFF                  0x20    // 显示反转关闭
#define INVON                   0x21    // 显示反转关闭
#define GAMSET                  0x26    // 显示反转开启
#define DISPOFF                 0x28    // 显示关闭
#define DISPON                  0x29    // 显示开启
#define CASET                   0x2A    // 列设置
#define RASET                   0x2B    // 行设置
#define RAMWR                   0x2C    // 内存写
#define RAMRD                   0x2E    // 内存读
#define PTLAR                   0x30    // 部分开始/结束地址设置
#define VSCRDEF                 0x33    // 垂直滚动定义
#define TEOFF                   0x34    // 行撕裂效果关闭
#define TEON                    0x35    // 行撕裂效果开启
#define MADCTL                  0x36    // 内存数据存取控制
#define VSCRSADD                0x37    // 垂直滚动开始地址
#define IDMOFF                  0x38    // 空闲模式关闭
#define IDMON                   0x39    // 空闲模式开启
#define COLMOD                  0x3A    // 接口像素格式
#define RAMWRC                  0x3C    // 内存连续写
#define RAMRDC                  0x3E    // 内存连续读
#define TESCAN                  0x44    // 设置泪损扫描线
#define RDTESCAN                0x45    // 获取扫描线
#define WRDISBV                 0x51    // 设置显示亮度
#define RDDISBV                 0x52    // 读显示亮度的值
#define WRCTRLD                 0x53    // 写控制显示
#define RDCTRLD                 0x54    // 读控制显示的值
#define WRCACE                  0x55    // 写内容适应的亮度控件和颜色增强 MNET
#define RDCABC                  0x56    // 读内容适应的亮度控件和颜色增强 MNET 的值
#define WRCABCMB                0x5E    // 写 CABC 最低亮度
#define RDCABCMB                0x5F    // 读 CABC 最低亮度的值
#define RDABCSDR                0x68    // 读取自动亮度控制自我诊断结果
#define RDID1                   0xDA    // 读 ID1
#define RDID2                   0xDB    // 读 ID2    
#define RDID3                   0xDC    // 读 ID3

#define LCD_RES_Set()           HAL_GPIO_WritePin(LCD_RES_GPIO_Port, LCD_RES_Pin, GPIO_PIN_SET)
#define LCD_RES_Clr()           HAL_GPIO_WritePin(LCD_RES_GPIO_Port, LCD_RES_Pin, GPIO_PIN_RESET)
#define LCD_DC_Set()            HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, GPIO_PIN_SET)
#define LCD_DC_Clr()            HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, GPIO_PIN_RESET)
#define LCD_CS_Set()            HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_SET)
#define LCD_CS_Clr()            HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_RESET)
#define LCD_BLK_Set()           HAL_GPIO_WritePin(LCD_BLK_GPIO_Port, LCD_BLK_Pin, GPIO_PIN_SET)
#define LCD_BLK_Clr()           HAL_GPIO_WritePin(LCD_BLK_GPIO_Port, LCD_BLK_Pin, GPIO_PIN_RESET)

void lcd_write_bus(uint8_t byte);
void lcd_write_command(uint8_t cmd);
void lcd_write_data8(uint8_t data);
void lcd_write_data16(uint16_t data);
void lcd_init();

#endif
