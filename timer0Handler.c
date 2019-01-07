
#include <xc.h>
#include "mcc_generated_files/tmr0.h"
#include "timer0Handler.h"
#include "i2cMotor.h"
#include "Varient.h"

const uint8_t rpm_multipuler = 25; // 38ms callback to 1ms
static uint8_t countbyTimer = 0;

// @brief タイマーは38mm周期なので適当に25階毎にRPSを計算しRPMに返還する
void TMR0_CustumInterruptHandler(void){
    CLRWDT();
    countbyTimer ++;
    iMotorRotateCnt++;
    if(countbyTimer >= rpm_multipuler){
        
        iMotorRotate = iMotorRotateCnt * 60;
        iMotorRotateCnt = 0;
        countbyTimer = 0;

    }
}

void tmr0Handler_Initialize(void){
    
    TMR0_SetInterruptHandler(TMR0_CustumInterruptHandler);
}

