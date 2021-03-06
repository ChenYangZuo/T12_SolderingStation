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
extern uint8_t Global_Beep_Enable;
extern uint8_t Global_Beep;
extern uint8_t Global_OLED_SW;
extern uint8_t Global_OLED_Input;
extern uint8_t Global_WriteEEPROM;
extern uint16_t Global_Dormancy_Time;
extern uint8_t Global_Dormancy_Temp;
extern uint8_t Global_Dormancy;
extern uint16_t Global_DormancyCNT;
extern MENU_T *Global_menu;
extern uint8_t Global_PID_P;
extern uint8_t Global_PID_I;
extern uint8_t Global_PID_D;

void HAL_GPIO_EXTI_Falling_Callback(uint16_t GPIO_Pin) {
    if(GPIO_Pin == EC11_A_Pin){
        // Reverse Rotation
        if (HAL_GPIO_ReadPin(EC11_B_GPIO_Port, EC11_B_Pin) == GPIO_PIN_SET) {
            switch (Global_OLED_SW) {
                case PAGE_HOME:{
                    Global_DormancyCNT = 0;
                    Target_Temp-=5;
                    Target_vol = (Target_Temp - 29.555) / 53.287;
                    Global_WriteEEPROM = 1;
                    break;
                }
                case PAGE_SETTINGS:{
                    Global_DormancyCNT = 0;
                    Global_menu = Global_menu->last;
                    break;
                }
                case PAGE_DORMANCY:{
                    Global_OLED_SW = 1;
                    Global_Dormancy = 0;
                    Global_DormancyCNT = 0;
                    break;
                }
                case PAGE_SETTINGS_3:
                case PAGE_SETTINGS_2:
                case PAGE_SETTINGS_1:{
                    Global_DormancyCNT = 0;
                    if(Global_OLED_Input){
                        if(Global_menu->id==1 && Global_menu->level==1){
                            Global_PID_P--;
                        }
                        else if(Global_menu->id==2 && Global_menu->level==1){
                            Global_PID_I--;
                        }
                        else if(Global_menu->id==3 && Global_menu->level==1){
                            Global_PID_D--;
                        }
                        else if(Global_menu->id==1 && Global_menu->level==2){
                            Global_Beep_Enable = !Global_Beep_Enable;
                        }
                        else if(Global_menu->id==1 && Global_menu->level==3){
                            Global_Dormancy_Time -= 10;
                        }
                        else if(Global_menu->id==2 && Global_menu->level==3){
                            Global_Dormancy_Temp -= 10;
                        }
                    }
                    else if(Global_menu->last){
                        Global_menu = Global_menu->last;
                    }
                    break;
                }
                default:{
                    break;
                }
            }
            Global_Beep = 1;
        }
        // Forward Rotation
        else {
            switch (Global_OLED_SW) {
                case PAGE_HOME:{
                    Global_DormancyCNT = 0;
                    Target_Temp+=5;
                    Target_vol = (Target_Temp - 29.555) / 53.287;
                    Global_WriteEEPROM = 1;
                    break;
                }
                case PAGE_SETTINGS:{
                    Global_DormancyCNT = 0;
                    Global_menu = Global_menu->next;
                    break;
                }
                case PAGE_DORMANCY:{
                    Global_OLED_SW = 1;
                    Global_Dormancy = 0;
                    Global_DormancyCNT = 0;
                    break;
                }
                case PAGE_SETTINGS_3:
                case PAGE_SETTINGS_2:
                case PAGE_SETTINGS_1:{
                    Global_DormancyCNT = 0;
                    if(Global_OLED_Input){
                        if(Global_menu->id==1 && Global_menu->level==1){
                            Global_PID_P++;
                        }
                        else if(Global_menu->id==2 && Global_menu->level==1){
                            Global_PID_I++;
                        }
                        else if(Global_menu->id==3 && Global_menu->level==1){
                            Global_PID_D++;
                        }
                        else if(Global_menu->id==1 && Global_menu->level==2){
                            Global_Beep_Enable = !Global_Beep_Enable;
                        }
                        else if(Global_menu->id==1 && Global_menu->level==3){
                            Global_Dormancy_Time += 10;
                        }
                        else if(Global_menu->id==2 && Global_menu->level==3){
                            Global_Dormancy_Temp += 10;
                        }
                    }
                    else if(Global_menu->next){
                        Global_menu = Global_menu->next;
                    }
                    break;
                }
                default:{
                    break;
                }
            }
            Global_Beep = 1;
        }
    }
}

void HAL_GPIO_EXTI_Rising_Callback(uint16_t GPIO_Pin){
    if(GPIO_Pin == EC11_KEY_Pin){
        switch (Global_OLED_SW) {
            case PAGE_HOME:{
                Global_OLED_SW = 2;
                break;
            }
            case PAGE_SETTINGS:{
                Global_menu = Global_menu->sub_menus;
                Global_OLED_SW = Global_menu->level + 3;
                break;
            }
            case PAGE_SETTINGS_3:
            case PAGE_SETTINGS_2:
            case PAGE_SETTINGS_1:{
                if(Global_menu->func){
                    Global_menu->func();
                }
                else{
                    Global_OLED_Input = !Global_OLED_Input;
                }

            }
            default:{
                break;
            }
        }

        LOGGING_I(LOG_LEVEL, "EC11 PUSH");
        Global_Beep = 1;
    }
}
