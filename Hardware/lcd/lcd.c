#include "lcd.h"

/**
 * 向总线写一个字节
 */
void lcd_write_bus(uint8_t byte)
{
    LCD_CS_Clr();
    HAL_SPI_Transmit(&hspi1, &byte, 1, HAL_MAX_DELAY);
    LCD_CS_Set();
}

/**
 * 写命令
 */
void lcd_write_command(uint8_t cmd) 
{
    LCD_DC_Clr();
    lcd_write_bus(cmd);    
    LCD_DC_Set();
}

/**
 * 写数据
 */
void lcd_write_data8(uint8_t data)
{
    lcd_write_bus(data);
}

/**
 * 写数据
 */
void lcd_write_data16(uint16_t data)
{
    lcd_write_bus(data>>8);
    lcd_write_bus(data);
}

/**
 * LCD屏幕初始化
 */
void lcd_init()
{
    // 复位
    LCD_BLK_Set();  // 打开背光
    LCD_RES_Clr();
    HAL_Delay(100);
    LCD_RES_Set();
    HAL_Delay(100);

    lcd_write_command(SLEEP_OUT);
    HAL_Delay(120);

    lcd_write_command(MADCTL);
    lcd_write_data8(0x00); // 设置显示方向

    lcd_write_command(COLMOD);
    lcd_write_data8(0x05);

    lcd_write_command(0xB2);
    lcd_write_data8(0x0C);
    lcd_write_data8(0x0C);
    lcd_write_data8(0x00);
    lcd_write_data8(0x33);
    lcd_write_data8(0x33);

    lcd_write_command(0xB7);
    lcd_write_data8(0x35);

    lcd_write_command(0xBB);
    lcd_write_data8(0x32); // Vcom=1.35V

    lcd_write_command(0xC2);
    lcd_write_data8(0x01);

    lcd_write_command(0xC3);
    lcd_write_data8(0x15); // GVDD=4.8V  颜色深度

    lcd_write_command(0xC4);
    lcd_write_data8(0x20); // VDV, 0x20:0v

    lcd_write_command(0xC6);
    lcd_write_data8(0x0F); // 0x0F:60Hz

    lcd_write_command(0xD0);
    lcd_write_data8(0xA4);
    lcd_write_data8(0xA1);

    lcd_write_command(0xE0);
    lcd_write_data8(0xD0);
    lcd_write_data8(0x08);
    lcd_write_data8(0x0E);
    lcd_write_data8(0x09);
    lcd_write_data8(0x09);
    lcd_write_data8(0x05);
    lcd_write_data8(0x31);
    lcd_write_data8(0x33);
    lcd_write_data8(0x48);
    lcd_write_data8(0x17);
    lcd_write_data8(0x14);
    lcd_write_data8(0x15);
    lcd_write_data8(0x31);
    lcd_write_data8(0x34);

    lcd_write_command(0xE1);
    lcd_write_data8(0xD0);
    lcd_write_data8(0x08);
    lcd_write_data8(0x0E);
    lcd_write_data8(0x09);
    lcd_write_data8(0x09);
    lcd_write_data8(0x15);
    lcd_write_data8(0x31);
    lcd_write_data8(0x33);
    lcd_write_data8(0x48);
    lcd_write_data8(0x17);
    lcd_write_data8(0x14);
    lcd_write_data8(0x15);
    lcd_write_data8(0x31);
    lcd_write_data8(0x34);
    lcd_write_command(INVON);

    lcd_write_command(DISPON);
}
