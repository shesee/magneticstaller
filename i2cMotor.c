#include "Varient.h"
#include "i2cGeneric.h"
#include "i2cMotor.h"

//!DRV8830 書き込み時のI2Cアドレス
const uint8_t drv8830addr_w = 0xC0;
//!DRV8830 読み込み時のI2Cアドレス
const uint8_t drv8830addr_r = 0xC1;
//!モーターの状態
volatile DRV8830Reg2 sMotor;

void Motor_Initialize(void){
    
    sMotor.byte = 0;

};


void zeroMotorParam(void){
    
    DRV8830Reg1 reg1;
    reg1.IN1 = 0;
    reg1.IN2 = 0;// Standby
    reg1.VSET = (PWMMotorMin&0x3F);

    i2cRegisterWrite1Byte(drv8830addr_w,0,reg1.byte);
    
    DRV8830Reg2 reg2;
    reg2.CLEAR = 1;
    i2cRegisterWrite1Byte(drv8830addr_w,1,reg2.byte);
    
}

void SetMotorSpeed(void){
    
    if(iPWMMotor == PWMMotorMin){
        zeroMotorParam();
    }else{
        if(!sMotor.byte){
            DRV8830Reg1 reg1;
            reg1.IN1 = 1;
            reg1.IN2 = 0;// Forward
            reg1.VSET = (iPWMMotor&0x3F); //

            i2cRegisterWrite1Byte(drv8830addr_w,0,reg1.byte);           
        }
    }   
}

void GetFaultState(void){
    
    DRV8830Reg2 reg2;
    bool rtn;

    rtn = i2cRegisterRead1Byte(drv8830addr_w,1,&(reg2.byte));
    if(rtn && reg2.byte){
        if(reg2.FAULT){
            sMotor.byte = reg2.byte;
        }
    }
}