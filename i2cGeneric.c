#include "Varient.h"
#include "i2cGeneric.h"

//!I2C送受信リトライ回数
static const uint8_t i2cGenericRetryMax = 10;

void i2cWrite(uint16_t slaveaddr, uint8_t* pData, uint8_t count, I2C_MESSAGE_STATUS* status){

    *status = I2C_MESSAGE_PENDING;

    uint8_t timeOut = 0;

    while(*status != I2C_MESSAGE_FAIL){
        I2C_MasterWrite(        pData,
                                count,
                                slaveaddr,
                                status);

        while(*status == I2C_MESSAGE_PENDING);

        if (*status == I2C_MESSAGE_COMPLETE)break;

        if (timeOut == i2cGenericRetryMax)
            break;
        else
            timeOut++;
    }    
}


bool i2cRegisterWrite1Byte(uint16_t slaveaddr, uint8_t regaddr ,uint8_t data){
     
    uint8_t writeBuffer[2];
    I2C_MESSAGE_STATUS status;

    writeBuffer[0] = (regaddr);
    writeBuffer[1] = (data);
    
    i2cWrite(slaveaddr, writeBuffer, 2, &status);
    
    return (status == I2C_MESSAGE_COMPLETE);

}

void i2cRead(uint16_t slaveaddr, uint8_t* pwData, uint8_t wcount, uint8_t* prData, uint8_t rcount, I2C_MESSAGE_STATUS* status){
    
    *status = I2C_MESSAGE_PENDING;
    uint8_t timeOut = 0;

    while(*status != I2C_MESSAGE_FAIL){
        I2C_MasterWrite(        pwData,
                                wcount,
                                slaveaddr,
                                status);

        while(*status == I2C_MESSAGE_PENDING);

        if (*status == I2C_MESSAGE_COMPLETE)break;

        if (timeOut == i2cGenericRetryMax)
            break;
        else
            timeOut++;
    }

    if (*status == I2C_MESSAGE_COMPLETE){
        timeOut = 0;
        while(*status != I2C_MESSAGE_FAIL){

            I2C_MasterRead(         prData,
                                    rcount,
                                    slaveaddr,
                                    status);

            while(*status == I2C_MESSAGE_PENDING);

            if (*status == I2C_MESSAGE_COMPLETE)break;

            if (timeOut == i2cGenericRetryMax)
                break;
            else
                timeOut++;
        }
    }
}

bool i2cRegisterRead1Byte(uint16_t slaveaddr, uint8_t regaddr, uint8_t* pData){
    I2C_MESSAGE_STATUS status;
    uint8_t     writeBuffer[1];
    
    writeBuffer[0] = regaddr;
    
    i2cRead(slaveaddr, writeBuffer, 1, pData, 1, &status);

    return (status == I2C_MESSAGE_COMPLETE);
}