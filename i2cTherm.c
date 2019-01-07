#include "i2cTherm.h"
#include "i2cGeneric.h"
#include "Varient.h"

//! I2C温度計のアドレス GNDに落としたときの値
static const uint16_t stts751addr = 0x72;
//温度のHigh部のレジスタアドレス 8bit で温度の整数部
static const uint8_t tempHighreg = 0x00;
//温度のLow部のレジスタアドレス 小数部　補数になっている
static const uint8_t tempLowreg  = 0x02;


int8_t getTemp(void){
    uint8_t temp = 0;
    
    if(i2cRegisterRead1Byte(stts751addr, tempHighreg, &temp)){
        iHeaterTemp = temp;
    }
    return (int8_t)temp;
            
}