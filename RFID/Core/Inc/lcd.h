/*
 * lcd.h
 *
 *  Created on: Nov 28, 2022
 *      Author: hoang
 */

/******************************************************************************************************************
@File:  	CLCD 8BIT (Character LCD 8Bit Mode)
@Author:  Khue Nguyen
@Website: khuenguyencreator.com
@Youtube: https://www.youtube.com/channel/UCt8cFnPOaHrQXWmVkk-lfvg
Huong dan su dung:
- Su dung thu vien HAL
- Khoi tao bien LCD: CLCD_8BIT_Name LCD1;
- Khoi tao LCD do:
CLCD_8BIT_Init(&LCD1, 16, 2, CS_GPIO_Port, CS_Pin, EN_GPIO_Port, EN_Pin,
									D0_GPIO_Port, D0_Pin, D1_GPIO_Port, D1_Pin,
									D2_GPIO_Port, D2_Pin, D3_GPIO_Port, D3_Pin,
									D4_GPIO_Port, D4_Pin, D5_GPIO_Port, D5_Pin,
									D6_GPIO_Port, D6_Pin, D7_GPIO_Port, D7_Pin);
- Su dung cac ham truyen dia chi cua LCD do:
CLCD_8BIT_SetCursor(&LCD1, 0, 0);
CLCD_8BIT_WriteString(&LCD1,"Hello anh em");
******************************************************************************************************************/
#ifndef __CLCD_H
#define __CLCD_H

#include "stm32f1xx_hal.h" // Chuyen doi chip dang su dung

// constant
#define CLCD_COMMAND 						0x00
#define CLCD_DATA 							0x01

// commands
#define LCD_CLEARDISPLAY 				0x01
#define LCD_RETURNHOME 					0x02

#define LCD_ENTRYMODESET 				0x04
#define LCD_DISPLAYCONTROL 			0x08
#define LCD_CURSORSHIFT 				0x10
#define LCD_FUNCTIONSET 				0x20
#define LCD_SETCGRAMADDR 				0x40
#define LCD_SETDDRAMADDR	 			0x80

// flags for display entry mode
#define LCD_ENTRYRIGHT 					0x00
#define LCD_ENTRYLEFT 					0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

// flags for display on/off control
#define LCD_DISPLAYON 					0x04
#define LCD_DISPLAYOFF 					0x00
#define LCD_CURSORON 						0x02
#define LCD_CURSOROFF 					0x00
#define LCD_BLINKON 						0x01
#define LCD_BLINKOFF 						0x00

// flags for display/cursor shift
#define LCD_DISPLAYMOVE 				0x08
#define LCD_CURSORMOVE 					0x00
#define LCD_MOVERIGHT 					0x04
#define LCD_MOVELEFT 						0x00

// flags for function set
#define LCD_8BITMODE 						0x10
#define LCD_4BITMODE 						0x00
#define LCD_2LINE 							0x08
#define LCD_1LINE 							0x00
#define LCD_5x10DOTS 						0x04
#define LCD_5x8DOTS 						0x00
typedef struct
{
	uint8_t MODE;
	uint8_t COLUMS;
	uint8_t ROWS;
	GPIO_TypeDef* RS_PORT;
	uint16_t RS_PIN;
	GPIO_TypeDef* EN_PORT;
	uint16_t EN_PIN;
	GPIO_TypeDef* D0_PORT;
	uint16_t D0_PIN;
	GPIO_TypeDef* D1_PORT;
	uint16_t D1_PIN;
	GPIO_TypeDef* D2_PORT;
	uint16_t D2_PIN;
	GPIO_TypeDef* D3_PORT;
	uint16_t D3_PIN;
	GPIO_TypeDef* D4_PORT;
	uint16_t D4_PIN;
	GPIO_TypeDef* D5_PORT;
	uint16_t D5_PIN;
	GPIO_TypeDef* D6_PORT;
	uint16_t D6_PIN;
	GPIO_TypeDef* D7_PORT;
	uint16_t D7_PIN;
	uint8_t ENTRYMODE;
	uint8_t DISPLAYCTRL;
	uint8_t CURSORSHIFT;
	uint8_t FUNCTIONSET;
}CLCD_Name;

//commands
#define lcd_cleardisplay 	0x01
#define lcd_displaycontrol	0x08
#define lcd_functionset		0x28
#define lcd_entrymode 		0x04

//display
#define lcd_line1 			0x80
#define lcd_line2 			0xC0

// flags for display on/off control
#define lcd_display_on		0x04
#define lcd_display_off		0x00
#define lcd_cursor_on		0x02
#define lcd_cursor_off		0x00
#define lcd_blinkOn 		0x01
#define lcd_blinkOff 		0x00

//flags for backlight control
#define lcd_backlight_on 	0x08
#define lcd_backlight_off	0x00


#define En					0b00000100
#define Rw					0b00000010
#define Rs					0b00000001

typedef struct
{
	uint8_t LCD_Columns;
	uint8_t LCD_Rows;
	uint8_t SLAVE_ADDRESS;
	uint8_t LCD_Backlight_Value;
	uint8_t LCD_Display_Option;
	I2C_HandleTypeDef *hi2c;
}LCD_I2C_HandleTypeDef;

void CLCD_8BIT_Init(CLCD_Name* LCD, uint8_t Colum, uint8_t Row,
									GPIO_TypeDef* RS_PORT, uint16_t RS_PIN, GPIO_TypeDef* EN_PORT, uint16_t EN_PIN,
									GPIO_TypeDef* D0_PORT, uint16_t D0_PIN, GPIO_TypeDef* D1_PORT, uint16_t D1_PIN,
									GPIO_TypeDef* D2_PORT, uint16_t D2_PIN, GPIO_TypeDef* D3_PORT, uint16_t D3_PIN,
									GPIO_TypeDef* D4_PORT, uint16_t D4_PIN, GPIO_TypeDef* D5_PORT, uint16_t D5_PIN,
									GPIO_TypeDef* D6_PORT, uint16_t D6_PIN, GPIO_TypeDef* D7_PORT, uint16_t D7_PIN);
void CLCD_4BIT_Init(CLCD_Name* LCD, uint8_t Colum, uint8_t Row,
									GPIO_TypeDef* RS_PORT, uint16_t RS_PIN, GPIO_TypeDef* EN_PORT, uint16_t EN_PIN,
									GPIO_TypeDef* D4_PORT, uint16_t D4_PIN, GPIO_TypeDef* D5_PORT, uint16_t D5_PIN,
									GPIO_TypeDef* D6_PORT, uint16_t D6_PIN, GPIO_TypeDef* D7_PORT, uint16_t D7_PIN);
void CLCD_SetCursor(LCD_I2C_HandleTypeDef *p_LCD, uint8_t p_col, uint8_t p_row);
void CLCD_WriteChar(LCD_I2C_HandleTypeDef *p_LCD, char data);
void CLCD_WriteString(LCD_I2C_HandleTypeDef *p_LCD, char *str);
void CLCD_Clear(LCD_I2C_HandleTypeDef *p_LCD);
void CLCD_ReturnHome(CLCD_Name* LCD);
void CLCD_CursorOn(CLCD_Name* LCD);
void CLCD_CursorOff(CLCD_Name* LCD);
void CLCD_BlinkOn(CLCD_Name* LCD);
void CLCD_BlinkOff(CLCD_Name* LCD);

void CLCD_I2C_Init(LCD_I2C_HandleTypeDef *p_LCD, I2C_HandleTypeDef *p_hi2c, uint8_t p_col, uint8_t p_row, uint8_t p_Slave_Address);
#endif
