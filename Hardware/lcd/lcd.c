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
