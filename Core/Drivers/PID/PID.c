#include <math.h>
#include <stdlib.h>
#include "PID.h"

uint8_t Global_PID_P = 7;
uint8_t Global_PID_I = 5;
uint8_t Global_PID_D = 0;
double PID_Error[3]={};

double PID_Increase(double PID_target, double PID_Now){
    uint8_t PID_P;
    uint8_t PID_I = Global_PID_I;
    uint8_t PID_D = Global_PID_D;
    double increase;

    if(fabs(PID_target - PID_Now) > 3){
        PID_P = 15;
    }
    else{
        PID_P = Global_PID_P;
    }

    PID_Error[2] = PID_Error[1];
    PID_Error[1] = PID_Error[0];
    PID_Error[0] = PID_target - PID_Now;

    increase = PID_P * (PID_Error[0] - PID_Error[1])
                + PID_I * PID_Error[0]
                + PID_D * (PID_Error[0] - 2*PID_Error[1] + PID_Error[2]);
    return increase;
}
