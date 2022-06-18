//
// Created by zuo-c on 2022/5/26.
//

#include "EC11.h"
#include "stdio.h"
#include "tim.h"
#include "logging.h"
#include "ee24.h"

extern enum LOGGING_LEVEL LOG_LEVEL;
extern uint16_t Target_Temp;
extern double Target_vol;
extern uint8_t Global_Beep;
extern uint8_t Global_OLED_SW;
extern uint8_t Global_WriteEEPROM;
extern uint8_t Global_Dormancy;
extern uint16_t Global_DormancyCNT;
extern int8_t Global_Menu_Index;

void HAL_GPIO_EXTI_Falling_Callback(uint16_t GPIO_Pin) {
    switch (GPIO_Pin) {
        case EC11_A_Pin:
            // Reverse Rotation
            if (HAL_GPIO_ReadPin(EC11_B_GPIO_Port, EC11_B_Pin) == GPIO_PIN_SET) {
                if(Global_OLED_SW == PAGE_HOME){
                    Global_DormancyCNT = 0;
                    Target_Temp-=5;
                    Target_vol = (Target_Temp - 29.555) / 53.287;
                    Global_WriteEEPROM = 1;
                }
                else if(Global_OLED_SW == PAGE_SETTINGS){
                    Global_DormancyCNT = 0;
                    Global_Menu_Index--;
                    if(Global_Menu_Index < 0){
                        Global_Menu_Index += 3;
                    }
                }
                else if(Global_OLED_SW == PAGE_DORMANCY){
                    Global_OLED_SW = 1;
                    Global_Dormancy = 0;
                    Global_DormancyCNT = 0;
                }
                Global_Beep = 1;
            }
            // Forward Rotation
            else {
                if(Global_OLED_SW == 1){
                    Global_DormancyCNT = 0;
                    Target_Temp+=5;
                    Target_vol = (Target_Temp - 29.555) / 53.287;
                    Global_WriteEEPROM = 1;
                }
                else if(Global_OLED_SW == 2){
                    Global_DormancyCNT = 0;
                    Global_Menu_Index++;
                    if(Global_Menu_Index >= 3){
                        Global_Menu_Index -= 3;
                    }
                }
                else if(Global_OLED_SW == 3){
                    Global_OLED_SW = 1;
                    Global_Dormancy = 0;
                    Global_DormancyCNT = 0;
                }
                Global_Beep = 1;
            }
            printf("MenuIndex: %d\r\n",Global_Menu_Index);
            break;
        case Handle_SW_Pin:
            LOGGING_I(LOG_LEVEL, "HANDLE");
            /* Set Handle_SW to normal GPIO */
            GPIO_InitTypeDef GPIO_InitStruct = {0};
            GPIO_InitStruct.Pin = Handle_SW_Pin;
            GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
            GPIO_InitStruct.Pull = GPIO_NOPULL;
            HAL_GPIO_Init(Handle_SW_GPIO_Port, &GPIO_InitStruct);
            /* End Dormancy*/
            Global_Dormancy = 0;
            Global_Beep = 1;
            break;
        default:
            break;
    }
}

void HAL_GPIO_EXTI_Rising_Callback(uint16_t GPIO_Pin){
    if(GPIO_Pin == EC11_KEY_Pin){
        if(Global_OLED_SW == 1){
            Global_OLED_SW = 2;
        }
        else if(Global_OLED_SW == 2){
            Global_OLED_SW = 1;
        }

        LOGGING_I(LOG_LEVEL, "EC11 PUSH");
        Global_Beep = 1;
    }
}
