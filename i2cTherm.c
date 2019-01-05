#include "i2cTherm.h"
#include "i2cGeneric.h"
#include "Varient.h"

const uint16_t stts751addr = 0x72;
const uint8_t tempHighreg = 0x00;
const uint8_t tempLowreg  = 0x02;


int8_t getTemp(void){
    uint8_t temp = 0;
    
    if(i2cRegisterRead1Byte(stts751addr, tempHighreg, &temp)){
        iHeaterTemp = temp;
    }
    return (int8_t)temp;
            
}