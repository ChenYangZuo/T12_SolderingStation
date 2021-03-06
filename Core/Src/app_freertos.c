/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : app_freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "logging.h"
#include "stdio.h"
#include "tim.h"
#include "adc.h"
#include "nst1001.h"
#include "OLED_u8g2.h"
#include "emoji.h"
#include "icon.h"
#include "ee24.h"
#include "PID.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define PAGE_HOME       1
#define PAGE_SETTINGS   2
#define PAGE_DORMANCY   3
#define PAGE_SETTINGS_1 4
#define PAGE_SETTINGS_2 5
#define PAGE_SETTINGS_3 6
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
int OLED_Return();
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
enum LOGGING_LEVEL LOG_LEVEL = LOGGING_LEVEL_FATAL;
uint8_t Global_Beep_Enable = 1;
uint8_t Global_Beep = 0;

uint8_t Global_WriteEEPROM = 0;

uint16_t Global_Dormancy_Time = 300;
uint8_t Global_Dormancy_Temp = 150;
uint16_t Global_DormancyCNT = 0;
uint8_t Global_Dormancy = 0;

uint8_t Global_OLED_SW = 1;
uint8_t Global_OLED_Pause = 0;
uint8_t Global_OLED_Input = 0;
uint8_t Global_OLED_Time = 0;

extern uint8_t Global_PID_P;
extern uint8_t Global_PID_I;
extern uint8_t Global_PID_D;

double Target_vol;
double Room_Temp = 0;
uint16_t Target_Temp = 0;
uint16_t Heater_Temp = 0;

int16_t PWM_DC = 0;

MENU_T menu_lists[] = {
        {.id=0, .level=0, .text_info="Temperature", .last=&menu_lists[2], .next=&menu_lists[1], .sub_menus=&menu_lists[3], .func=NULL},
        {.id=1, .level=0, .text_info="Interact"   , .last=&menu_lists[0], .next=&menu_lists[2], .sub_menus=&menu_lists[7], .func=NULL},
        {.id=2, .level=0, .text_info="Dormancy"   , .last=&menu_lists[1], .next=&menu_lists[0], .sub_menus=&menu_lists[9], .func=NULL},

        {.id=0, .level=1, .text_info="Return",.last=NULL          , .next=&menu_lists[4], .sub_menus=&menu_lists[0], .func=OLED_Return},
        {.id=1, .level=1, .text_info="P"     ,.last=&menu_lists[3], .next=&menu_lists[5], .sub_menus=&menu_lists[3], .func=NULL},
        {.id=2, .level=1, .text_info="I"     ,.last=&menu_lists[4], .next=&menu_lists[6], .sub_menus=&menu_lists[3], .func=NULL},
        {.id=3, .level=1, .text_info="D"     ,.last=&menu_lists[5], .next=NULL          , .sub_menus=&menu_lists[3], .func=NULL},

        {.id=0, .level=2, .text_info="Return",.last=NULL          , .next=&menu_lists[8], .sub_menus=&menu_lists[0], .func=OLED_Return},
        {.id=1, .level=2, .text_info="Beep"  ,.last=&menu_lists[7], .next=NULL          , .sub_menus=&menu_lists[7], .func=NULL},

        {.id=0, .level=3, .text_info="Return",.last=NULL          , .next=&menu_lists[10], .sub_menus=&menu_lists[0] , .func=OLED_Return},
        {.id=1, .level=3, .text_info="Time" ,.last=&menu_lists[9], .next=&menu_lists[11], .sub_menus=&menu_lists[9] , .func=NULL},
        {.id=2, .level=3, .text_info="Temp" ,.last=&menu_lists[10], .next=NULL          , .sub_menus=&menu_lists[9] , .func=NULL},
};

MENU_T *Global_menu = &menu_lists[0];

/* USER CODE END Variables */
osThreadId OLEDTaskHandle;
osThreadId BeepTaskHandle;
osThreadId TempTaskHandle;
osThreadId EEPROMTaskHandle;
osThreadId PIDTaskHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartOLEDTask(void const *argument);

void StartBeepTask(void const *argument);

void StartTempTask(void const *argument);

void StartEEPROMTask(void const *argument);

void StartPIDTask(void const *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
    /* USER CODE BEGIN Init */

    /* USER CODE END Init */

    /* USER CODE BEGIN RTOS_MUTEX */
    /* add mutexes, ... */
    /* USER CODE END RTOS_MUTEX */

    /* USER CODE BEGIN RTOS_SEMAPHORES */
    /* add semaphores, ... */
    /* USER CODE END RTOS_SEMAPHORES */

    /* USER CODE BEGIN RTOS_TIMERS */
    /* start timers, add new ones, ... */
    /* USER CODE END RTOS_TIMERS */

    /* USER CODE BEGIN RTOS_QUEUES */
    /* add queues, ... */
    /* USER CODE END RTOS_QUEUES */

    /* Create the thread(s) */
    /* definition and creation of OLEDTask */
    osThreadDef(OLEDTask, StartOLEDTask, osPriorityLow, 0, 512);
    OLEDTaskHandle = osThreadCreate(osThread(OLEDTask), NULL);

    /* definition and creation of BeepTask */
    osThreadDef(BeepTask, StartBeepTask, osPriorityNormal, 0, 256);
    BeepTaskHandle = osThreadCreate(osThread(BeepTask), NULL);

    /* definition and creation of TempTask */
    osThreadDef(TempTask, StartTempTask, osPriorityNormal, 0, 256);
    TempTaskHandle = osThreadCreate(osThread(TempTask), NULL);

    /* definition and creation of EEPROMTask */
    osThreadDef(EEPROMTask, StartEEPROMTask, osPriorityHigh, 0, 256);
    EEPROMTaskHandle = osThreadCreate(osThread(EEPROMTask), NULL);

    /* definition and creation of PIDTask */
    osThreadDef(PIDTask, StartPIDTask, osPriorityRealtime, 0, 256);
    PIDTaskHandle = osThreadCreate(osThread(PIDTask), NULL);

    /* USER CODE BEGIN RTOS_THREADS */
    /* add threads, ... */
    /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartOLEDTask */
/**
  * @brief  Function implementing the OLEDTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartOLEDTask */
void StartOLEDTask(void const *argument) {
    /* USER CODE BEGIN StartOLEDTask */
    u8g2_t u8g2;
    uint8_t direction = 1;
    uint8_t index = 0;
    uint8_t target_X;
    uint8_t current_X = 8;
    uint16_t delay_time = 0;
    char buff[18];

    HAL_GPIO_WritePin(OLED_RES_GPIO_Port, OLED_RES_Pin, GPIO_PIN_SET);
    u8g2Init(&u8g2);
    /* Infinite loop */
    for (;;) {
        // Clear OLED Buffer
        u8g2_ClearBuffer(&u8g2);
        // Select Which to Show:
        switch (Global_OLED_SW) {
            case PAGE_HOME:{
                // Show Target Temperature
                sprintf(buff, "SET:%03d ??C", Target_Temp);
                u8g2_SetFont(&u8g2, u8g2_font_ncenB08_tf);
                u8g2_DrawUTF8(&u8g2, 0, 16, buff);
                // Show Room Temperature
                sprintf(buff, "%02d ??C", (int) Room_Temp);
                u8g2_DrawUTF8(&u8g2, 100, 16, buff);
                // Show Current Temperature
                sprintf(buff, "%03d??C", Heater_Temp);
                u8g2_SetFont(&u8g2, u8g2_font_ncenB24_tf);
                u8g2_DrawUTF8(&u8g2, 18, 48, buff);
                // Show Slogan
//            sprintf(buff, "Create the Future");
//            u8g2_SetFont(&u8g2, u8g2_font_ncenB08_tf);
//            u8g2_DrawStr(&u8g2, 18, 64, buff);
                // Show Output Power
                u8g2_DrawFrame(&u8g2, 8, 56, 112, 8);
                u8g2_DrawBox(&u8g2, 8, 56, (int) (112 * PWM_DC / 1000.0), 8);
                // Send OLED Buffer
                u8g2_SendBuffer(&u8g2);
                // Show@10fps
                osDelay(100);
                break;
            }
            case PAGE_DORMANCY:{
                if(Global_OLED_Pause && HAL_GetTick() - delay_time < 8000){
                    osDelay(1);
                    continue;
                }
                // Draw Emoji
                u8g2_DrawXBM(&u8g2, 32, 19, 64, 26, emoji[index]);
                // Update index
                index = direction ? index + 1 : index - 1;
                // Update direction
                if (index == 9 || index == 0) {
                    direction = !direction;
                }
                // Update pause
                Global_OLED_Pause = (index == 0);
                // Send OLED Buffer
                u8g2_SendBuffer(&u8g2);
                // Delay for Show
                delay_time = HAL_GetTick();
                // Show@100fps
                osDelay(10);
                break;
            }
            case PAGE_SETTINGS:{
                // Draw Icon
                for(uint8_t i=0;i<3;i++){
                    u8g2_DrawXBM(&u8g2, 8+40*i, 10, 32, 32, icons[i]);
                }
                // Draw String
                sprintf(buff,"%s", Global_menu->text_info);
                u8g2_SetFont(&u8g2, u8g2_font_ncenB08_tf);
                u8g2_DrawUTF8(&u8g2, (128 - u8g2_GetStrWidth(&u8g2, buff)) / 2, 56, buff);
                // Draw Selection Box
                target_X = 8 + Global_menu->id * 40;
                if (current_X < target_X) {
                    current_X += 4;
                }
                if (current_X > target_X) {
                    current_X -= 4;
                }
                u8g2_DrawFrame(&u8g2, current_X, 10, 32, 32);
                // Flash
                u8g2_SendBuffer(&u8g2);
                osDelay(17);
                break;
            }
            case PAGE_SETTINGS_1:{
                MENU_T *menu;
                // Draw Menu items
                u8g2_SetFont(&u8g2, u8g2_font_ncenB08_tf);
                for (menu = &menu_lists[3]; menu; menu = menu->next){
                    sprintf(buff, "%s", menu->text_info);
                    u8g2_DrawUTF8(&u8g2, 16, 14*(1+menu->id), buff);
                    if(menu->id == Global_menu->id){
                        u8g2_DrawTriangle(&u8g2,3,14*(1+menu->id)-8,3,14*(1+menu->id),6,14*(1+menu->id)-4);
                    }
                }
                // Draw key value
                sprintf(buff, "%d", Global_PID_P);
                u8g2_DrawUTF8(&u8g2, 100, 14*2, buff);
                sprintf(buff, "%d", Global_PID_I);
                u8g2_DrawUTF8(&u8g2, 100, 14*3, buff);
                sprintf(buff, "%d", Global_PID_D);
                u8g2_DrawUTF8(&u8g2, 100, 14*4, buff);
                // Send OLED Buffer
                u8g2_SendBuffer(&u8g2);
                osDelay(17);
                break;
            }
            case PAGE_SETTINGS_2:{
                MENU_T *menu;
                // Draw Menu items
                u8g2_SetFont(&u8g2, u8g2_font_ncenB08_tf);
                for (menu = &menu_lists[7]; menu; menu = menu->next){
                    sprintf(buff, "%s", menu->text_info);
                    u8g2_DrawUTF8(&u8g2, 16, 14*(1+menu->id), buff);
                    if(menu->id == Global_menu->id){
                        u8g2_DrawTriangle(&u8g2,3,14*(1+menu->id)-8,3,14*(1+menu->id),6,14*(1+menu->id)-4);
                    }
                }
                // Draw key value
                u8g2_SetFont(&u8g2, u8g2_font_unifont_t_symbols);
                if(Global_Beep_Enable){
                    u8g2_DrawGlyph(&u8g2,100,28,0x2714);
                }
                else{
                    u8g2_DrawGlyph(&u8g2,100,30,0x2715);
                }
                // Send OLED Buffer
                u8g2_SendBuffer(&u8g2);
                osDelay(17);
                break;
            }
            case PAGE_SETTINGS_3:{
                MENU_T *menu;
                // Draw Menu items
                u8g2_SetFont(&u8g2, u8g2_font_ncenB08_tf);
                for (menu = &menu_lists[9]; menu; menu = menu->next){
                    sprintf(buff, "%s", menu->text_info);
                    u8g2_DrawUTF8(&u8g2, 16, 14*(1+menu->id), buff);
                    if(menu->id == Global_menu->id){
                        u8g2_DrawTriangle(&u8g2,3,14*(1+menu->id)-8,3,14*(1+menu->id),6,14*(1+menu->id)-4);
                    }
                }
                // Draw key value
                sprintf(buff, "%d", Global_Dormancy_Time);
                u8g2_DrawUTF8(&u8g2, 100, 14*2, buff);
                sprintf(buff, "%d", Global_Dormancy_Temp);
                u8g2_DrawUTF8(&u8g2, 100, 14*3, buff);
                // Send OLED Buffer
                u8g2_SendBuffer(&u8g2);
                osDelay(17);
                break;
            }
            default:{
                osDelay(1);
                break;
            }
        }
    }
    /* USER CODE END StartOLEDTask */
}

/* USER CODE BEGIN Header_StartBeepTask */
/**
* @brief Function implementing the BeepTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartBeepTask */
void StartBeepTask(void const *argument) {
    /* USER CODE BEGIN StartBeepTask */
    /* Infinite loop */
    for (;;) {
        if (Global_Beep_Enable && Global_Beep) {
            HAL_TIM_PWM_Start(&htim15, TIM_CHANNEL_1);
            osDelay(100);
            HAL_TIM_PWM_Stop(&htim15, TIM_CHANNEL_1);
            Global_Beep = 0;
        }
        osDelay(1);
    }
    /* USER CODE END StartBeepTask */
}

/* USER CODE BEGIN Header_StartTempTask */
/**
* @brief Function implementing the TempTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTempTask */
void StartTempTask(void const *argument) {
    /* USER CODE BEGIN StartTempTask */
    /* Infinite loop */
    for (;;) {
        /* Get Thermocouple Cold Junction Temperature*/
        Room_Temp = NST1001_Start_Measurement();
        LOGGING_I(LOG_LEVEL, "Room Temperature: %f", Room_Temp);
        /* Count to turn on Dormancy Mode*/
        if (Global_Dormancy == 0) {
            Global_OLED_Pause = 0;
            printf("Dormancy: %d \r\n",Global_DormancyCNT);
            if (Global_DormancyCNT > Global_Dormancy_Time*20) {
                Global_Dormancy = 1;
                Global_OLED_SW = 3;
            }
        }

        if(Global_OLED_SW == PAGE_SETTINGS){
            Global_OLED_Time++;
            if(Global_OLED_Time > 6){
                Global_OLED_SW = PAGE_HOME;
            }
        }

        osDelay(1000);
    }
    /* USER CODE END StartTempTask */
}

/* USER CODE BEGIN Header_StartEEPROMTask */
/**
* @brief Function implementing the EEPROMTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartEEPROMTask */
void StartEEPROMTask(void const *argument) {
    /* USER CODE BEGIN StartEEPROMTask */
    //Read Target Temperature From EEPROM
    uint8_t temp_h, temp_l;
    if (ee24_isConnected()) {
        ee24_read(0, &temp_h, 1, 200);
        ee24_read(1, &temp_l, 1, 200);
        Target_Temp = (temp_h << 8) | temp_l;
        // Prevent Reading Wrong Data
        if (Target_Temp > 500) {
            Target_Temp = 500;
        }
        // Convert Temperature to Voltage
        Target_vol = (Target_Temp - 29.555) / 53.287;
    }
    /* Infinite loop */
    for (;;) {
        if (Global_WriteEEPROM) {
            //Write Target Temperature To EEPROM
            temp_h = (Target_Temp >> 8) & 0xFF;
            temp_l = (Target_Temp & 0xFF);
            ee24_write(0, &temp_h, 1, 200);
            ee24_write(1, &temp_l, 1, 200);
            Global_WriteEEPROM = 0;
        }
        osDelay(10000);
    }
    /* USER CODE END StartEEPROMTask */
}

/* USER CODE BEGIN Header_StartPIDTask */
/**
* @brief Function implementing the PIDTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartPIDTask */
void StartPIDTask(void const *argument) {
    /* USER CODE BEGIN StartPIDTask */
    double ADC_Value[5];
    double ADC_vol;
    HAL_ADC_Start(&hadc1);
    /* Infinite loop */
    for (;;) {
        HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_2);
        osDelay(5);
        HAL_ADC_PollForConversion(&hadc1, 100);

        // Get Dormancy CNT
        if (HAL_GPIO_ReadPin(Handle_SW_GPIO_Port, Handle_SW_Pin) == GPIO_PIN_RESET) {
            Global_DormancyCNT++;
        }
        else {
            Global_DormancyCNT = 0;
            if(Global_Dormancy){
                Global_Dormancy = 0;
                Global_Beep = 1;
                Global_OLED_SW = 1;
            }
        }

        // Mean Filter
        ADC_Value[4] = ADC_Value[3];
        ADC_Value[3] = ADC_Value[2];
        ADC_Value[2] = ADC_Value[1];
        ADC_Value[1] = ADC_Value[0];
        ADC_Value[0] = HAL_ADC_GetValue(&hadc1) / 4095.0 * 2.5 / 250 * 1000;
        ADC_vol = (ADC_Value[4] + ADC_Value[3] + ADC_Value[2] + ADC_Value[1] + ADC_Value[0]) / 5.0;

        // Convert Voltage to Temperature
        Heater_Temp = (uint16_t) (ADC_vol * 53.287 + 29.555);
        LOGGING_I(LOG_LEVEL, "Raw Voltage: %f mV", ADC_vol);

        // PID Operation
        PWM_DC = PWM_DC + (int16_t) PID_Increase(Target_vol, ADC_vol);
        // Limiting Operation
        if (PWM_DC > 1000) PWM_DC = 1000;
        if (PWM_DC < 0) PWM_DC = 0;

//        printf("%f,%d\n", ADC_vol, PWM_DC);
        LOGGING_I(LOG_LEVEL, "PWM DC: %d", PWM_DC);

        // Set Duty Cycle
        __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, PWM_DC);
        HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);

        osDelay(50);
    }
    /* USER CODE END StartPIDTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
int OLED_Return(){
    Global_menu = Global_menu->sub_menus;
    Global_OLED_SW = PAGE_SETTINGS;
    return 0;
}
/* USER CODE END Application */

