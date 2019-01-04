
#include "mcc_generated_files/tmr0.h"
#include "timer0Handler.h"
#include "i2cMotor.h"
#include "Varient.h"

const uint8_t rpm_multipuler = 25; // 38ms callback to 1ms
static uint8_t iMotorRotate1sCnt = 0;

void TMR0_CustumInterruptHandler(void){
    CLRWDT();
    iMotorRotate1sCnt ++;
    if(!(iMotorRotate1sCnt < rpm_multipuler)){

        iMotorRotate1sCnt = 0;
        iMotorRotate = iMotorRotateCnt * 60;
        iMotorRotateCnt = 0;

    }
}

void tmr0Handler_Initialize(void){
    
    TMR0_SetInterruptHandler(TMR0_CustumInterruptHandler);
}

