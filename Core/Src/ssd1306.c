/*
 * ssd1306.c
 *
 *
 *
 */


#include "ssd1306.h"
#include "fonts.h"  // your Font7x10

#define SSD1306_BUFFER_SIZE (SSD1306_WIDTH * SSD1306_HEIGHT / 8)
static uint8_t SSD1306_Buffer[SSD1306_BUFFER_SIZE];

SSD1306_t ssd1306;

extern I2C_HandleTypeDef hi2c1;

static void ssd1306_WriteCommand(uint8_t cmd)
{
    uint8_t data[2] = {0x00, cmd};
    HAL_I2C_Master_Transmit(&hi2c1, SSD1306_I2C_ADDR, data, 2, 10);
}

void ssd1306_Init(void)
{
    HAL_Delay(100);
    ssd1306_WriteCommand(0xAE); // Display off
    ssd1306_WriteCommand(0x20); // Set Memory Addressing Mode
    ssd1306_WriteCommand(0x10); // Page addressing mode
    ssd1306_WriteCommand(0xB0); // Set page start address
    ssd1306_WriteCommand(0xC8); // COM scan direction
    ssd1306_WriteCommand(0x00); // low column
    ssd1306_WriteCommand(0x10); // high column
    ssd1306_WriteCommand(0x40); // start line
    ssd1306_WriteCommand(0x81); // contrast
    ssd1306_WriteCommand(0xFF);
    ssd1306_WriteCommand(0xA1); // segment remap
    ssd1306_WriteCommand(0xA6); // normal display
    ssd1306_WriteCommand(0xA8); // multiplex
    ssd1306_WriteCommand(0x3F);
    ssd1306_WriteCommand(0xA4); // display all on resume
    ssd1306_WriteCommand(0xD3); // display offset
    ssd1306_WriteCommand(0x00);
    ssd1306_WriteCommand(0xD5); // display clock
    ssd1306_WriteCommand(0xF0);
    ssd1306_WriteCommand(0xD9); // precharge
    ssd1306_WriteCommand(0x22);
    ssd1306_WriteCommand(0xDA); // COM pins
    ssd1306_WriteCommand(0x12);
    ssd1306_WriteCommand(0xDB); // vcomh
    ssd1306_WriteCommand(0x20);
    ssd1306_WriteCommand(0x8D); // charge pump
    ssd1306_WriteCommand(0x14);
    ssd1306_WriteCommand(0xAF); // display on

    ssd1306_Fill(Black);
    ssd1306_UpdateScreen();

    ssd1306.CurrentX = 0;
    ssd1306.CurrentY = 0;
}

void ssd1306_Fill(SSD1306_COLOR color)
{
    memset(SSD1306_Buffer, (color == white) ? 0xFF : 0x00, SSD1306_BUFFER_SIZE);
}

void ssd1306_UpdateScreen(void)
{
    for(uint8_t page = 0; page < SSD1306_HEIGHT / 8; page++)
    {
        ssd1306_WriteCommand(0xB0 + page);
        ssd1306_WriteCommand(0x00);
        ssd1306_WriteCommand(0x10);
        HAL_I2C_Mem_Write(&hi2c1, SSD1306_I2C_ADDR, 0x40, 1, &SSD1306_Buffer[SSD1306_WIDTH*page], SSD1306_WIDTH, 100);
    }
}

void ssd1306_DrawPixel(uint16_t x, uint16_t y, SSD1306_COLOR color)
{
    if(x >= SSD1306_WIDTH || y >= SSD1306_HEIGHT) return;

    if(color == white)
        SSD1306_Buffer[x + (y/8)*SSD1306_WIDTH] |= 1 << (y%8);
    else
        SSD1306_Buffer[x + (y/8)*SSD1306_WIDTH] &= ~(1 << (y%8));
}

void ssd1306_SetCursor(uint16_t x, uint16_t y)
{
    ssd1306.CurrentX = x;
    ssd1306.CurrentY = y;
}

char ssd1306_WriteChar(char ch, FontDef Font, SSD1306_COLOR color) {
    uint32_t i, j;
    uint16_t line;

    // Check if character is printable (ASCII 32–127)
    if (ch < 32 || ch > 127) {
        return 0;
    }

    // Check boundaries (prevent overflow)
    if (ssd1306.CurrentX + Font.Width >= SSD1306_WIDTH ||
        ssd1306.CurrentY + Font.Height >= SSD1306_HEIGHT) {
        return 0; // character won’t fit
    }

    // Go through font data
    for (i = 0; i < Font.Height; i++) {
        line = Font.data[(ch - 32) * Font.Height + i];
        for (j = 0; j < Font.Width; j++) {
            if (line & (1 << j)) {
                ssd1306_DrawPixel(ssd1306.CurrentX + j, (ssd1306.CurrentY + i), color);
            }
        }
    }

    // Move cursor for next character
    ssd1306.CurrentX += Font.Width;

    return ch;
}


char ssd1306_WriteString(char* str, FontDef Font, SSD1306_COLOR color) {
    while (*str) {
        if (*str == '\n') {
            // Manual newline
            ssd1306.CurrentX = 0;
            ssd1306.CurrentY += Font.Height;
        } else {
            // Wrap check: if character would go past width, wrap to new line
            if (ssd1306.CurrentX + Font.Width >= SSD1306_WIDTH) {
                ssd1306.CurrentX = 0;
                ssd1306.CurrentY += Font.Height;
            }

            // Stop drawing if beyond bottom of screen
            if (ssd1306.CurrentY + Font.Height >= SSD1306_HEIGHT) {
                return 0; // No space left
            }

            // Draw character
            if (ssd1306_WriteChar(*str, Font, color) != *str) {
                return 0; // error
            }
        }
        str++;
    }
    return 1;
}





