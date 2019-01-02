#include "Varient.h"
#include "i2cGeneric.h"
#include "i2cMorter.h"

#define drv8830addr_w 0xC0
#define drv8830addr_r 0xC1

void InitializeMoterParam(void){
    DRV8830Reg1 reg1;
    reg1.IN1 = 0;
    reg1.IN2 = 0;// Standby
    reg1.VSET = (iPWMMorterMin&0x3F);

    i2cRegisterWrite1Byte(drv8830addr_w,0,reg1.DRV8830Reg1Byte);
    
    DRV8830Reg2 reg2;
    reg2.CLEAR = 1;
    i2cRegisterWrite1Byte(drv8830addr_w,1,reg2.DRV8830Reg2Byte);

}

void SetMoterSpeed(void){
    
    if(iPWMMorter == 0){
        InitializeMoterParam();
    }else{
        if(!sMorter){
            DRV8830Reg1 reg1;
            reg1.IN1 = 1;
            reg1.IN2 = 0;// Forward
            reg1.VSET = (iPWMMorter&0x3F); //

            i2cRegisterWrite1Byte(drv8830addr_w,0,reg1.DRV8830Reg1Byte);           
        }
    }   
}

void GetFaultState(void){
    
    DRV8830Reg2 reg2;
    bool rtn;

    rtn = i2cRegisterRead1Byte(drv8830addr_w,1,&reg2.DRV8830Reg2Byte);
    if(rtn && reg2.DRV8830Reg2Byte){
        if(reg2.FAULT){
            sMorter = reg2.DRV8830Reg2Byte;
        }
    }
}