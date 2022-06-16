//
// Created by zuo-c on 2022/5/19.
//

#include "cmsis_os.h"
#include "nst1001.h"
#include "tim.h"

/**
  * @brief  NST1001解析温度
  * @param  nst1001_cnt 脉冲计数
  * @retval temperature
  */
double NST1001_Get_Temperature(uint16_t nst1001_cnt){
    double temp = nst1001_cnt * 0.0625 - 50.0625;
    if (temp<30){
        temp = temp + (temp-30)*0.005;
    }
    else if (temp <= 100){
        temp = temp;
    }
    else{
        temp = temp + (100-temp)*0.012;
    }
    return temp;
}

/**
  * @brief  NST1001温度测量
  * @param  None
  * @retval temperature
  */
double NST1001_Start_Measurement(){
    uint16_t cnt;
    //拉高电源，开启定时器
    HAL_TIM_Base_Start(&htim1);
    HAL_GPIO_WritePin(NST1001_PWR_GPIO_Port,NST1001_PWR_Pin,GPIO_PIN_SET);
    //采集70ms
    osDelay(70);
    //读取定时器计数值后清零
    cnt = __HAL_TIM_GetCounter(&htim1);
    __HAL_TIM_SET_COUNTER(&htim1,0);
    //停止定时器，关闭电源
    HAL_TIM_Base_Stop(&htim1);
    HAL_GPIO_WritePin(NST1001_PWR_GPIO_Port,NST1001_PWR_Pin,GPIO_PIN_RESET);
    //输出结果
    return NST1001_Get_Temperature(cnt);
}