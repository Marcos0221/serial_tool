#include "lcd.h"

/**
 * 向总线写一个字节
 */
void lcd_write_bus(uint8_t data)
{
    HAL_SPI_Transmit(&hspi1, &data, 1, HAL_MAX_DELAY);
}
