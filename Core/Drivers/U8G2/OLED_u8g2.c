//
// Created by zuo-c on 2022/5/23.
//

#include "OLED_u8g2.h"

#include "cmsis_os.h"
#include "stdio.h"
#include "spi.h"
#include "u8g2.h"
#include "u8x8.h"

/* USER CODE BEGIN ADAPTER */
uint8_t u8x8_byte_4wire_hw_spi(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr) {
    switch (msg) {
        case U8X8_MSG_BYTE_SEND: /*通过SPI发送arg_int个字节数据*/
            HAL_SPI_Transmit(&hspi1, (uint8_t *) arg_ptr, arg_int, 200);
            break;
        case U8X8_MSG_BYTE_INIT: /*初始化函数*/
            break;
        case U8X8_MSG_BYTE_SET_DC: /*设置DC引脚,表明发送的是数据还是命令*/
            HAL_GPIO_WritePin(OLED_DC_GPIO_Port, OLED_DC_Pin, arg_int);
            break;
        case U8X8_MSG_BYTE_START_TRANSFER:
            break;
        case U8X8_MSG_BYTE_END_TRANSFER:
            break;
        default:
            return 0;
    }
    return 1;
}

uint8_t u8x8_gpio_and_delay_spi(U8X8_UNUSED u8x8_t *u8x8,
                                  U8X8_UNUSED uint8_t msg, U8X8_UNUSED uint8_t arg_int,
                                  U8X8_UNUSED void *arg_ptr) {
    switch (msg) {
        case U8X8_MSG_GPIO_AND_DELAY_INIT: /*delay和GPIO的初始化，在main中已经初始化完成了*/
            break;
        case U8X8_MSG_DELAY_MILLI: /*延时函数*/
            osDelay(arg_int);
            break;
        case U8X8_MSG_GPIO_CS: /*片选信号*/
            break;
        case U8X8_MSG_GPIO_DC: /*设置DC引脚,表明发送的是数据还是命令*/
            HAL_GPIO_WritePin(OLED_DC_GPIO_Port, OLED_DC_Pin, arg_int);
            break;
        case U8X8_MSG_GPIO_RESET:
            break;
    }
    return 1;
}
/* USER CODE END ADAPTER */

void u8g2Init(u8g2_t *u8g2) {
    u8g2_Setup_sh1106_128x64_noname_f(u8g2, U8G2_R0, u8x8_byte_4wire_hw_spi,
                                      u8x8_gpio_and_delay_spi);  // 初始化 u8g2 结构体
    u8g2_InitDisplay(u8g2);
    u8g2_SetPowerSave(u8g2, 0); //开启显示
}
