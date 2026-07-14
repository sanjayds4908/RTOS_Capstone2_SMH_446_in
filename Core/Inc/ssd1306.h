/*
 * ssd1306.h
 *
 *

 */

#ifndef INC_SSD1306_H_
#define INC_SSD1306_H_


#include "stm32f4xx_hal.h" // Change to your STM32 series
#include <string.h>
#include <stdint.h>

#define SSD1306_I2C_ADDR 0x78 // Change if needed
#define SSD1306_WIDTH 128
#define SSD1306_HEIGHT 64

typedef enum {
    Black = 0,
    white = 1,

} SSD1306_COLOR;

typedef struct {
    uint8_t Width;
    uint8_t Height;
    const uint16_t *data;
} FontDef;

typedef struct {
    uint16_t CurrentX;
    uint16_t CurrentY;
} SSD1306_t;

extern I2C_HandleTypeDef hi2c1; // change if different I2C

// Function prototypes
void ssd1306_Init(void);
void ssd1306_Fill(SSD1306_COLOR color);
void ssd1306_UpdateScreen(void);
void ssd1306_DrawPixel(uint16_t x, uint16_t y, SSD1306_COLOR color);
void ssd1306_SetCursor(uint16_t x, uint16_t y);
char ssd1306_WriteChar(char ch, FontDef Font, SSD1306_COLOR color);
char ssd1306_WriteString(char* str, FontDef Font, SSD1306_COLOR color);



#endif /* INC_SSD1306_H_ */
