#include "Varient.h"
#include "i2cGeneric.h"
#include "i2cMotor.h"

#define drv8830addr_w 0xC0
#define drv8830addr_r 0xC1

void zeroMotorParam(void){
    DRV8830Reg1 reg1;
    reg1.IN1 = 0;
    reg1.IN2 = 0;// Standby
    reg1.VSET = (iPWMMotorMin&0x3F);

    i2cRegisterWrite1Byte(drv8830addr_w,0,reg1.byte);
    
    DRV8830Reg2 reg2;
    reg2.CLEAR = 1;
    i2cRegisterWrite1Byte(drv8830addr_w,1,reg2.byte);

}

void SetMotorSpeed(void){
    
    if(iPWMMotor == iPWMMotorMin){
        zeroMotorParam();
    }else{
        if(!sMotor){
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
            sMotor = reg2.byte;
        }
    }
}