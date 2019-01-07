#include <xc.h>
#include "mcc_generated_files/device_config.h"
#include "i2cGeneric.h"
#include "i2cLCD.h"


//!I2Cアドレス
const uint8_t AQM1602addr = 0x7C;

//!初期化のコマンド
const uint8_t cmd_Functionset        = 0x38;//8bit 1/6duty notDH
const uint8_t cmd_FunctionsetEx      = 0x39;//IS セット
const uint8_t cmd_ExInternalOSCFreq  = 0x14;//1/5bias 380kHz
const uint8_t cmd_ExContrastSet      = 0x73;//Contrast LSB 3
const uint8_t cmd_ExPowerControl     = 0x56;//ICON OFF VoltageBooster ON Contrast MSB 32
const uint8_t cmd_ExFollowerControl  = 0x6C;//FC ON AMPSET 8
const uint8_t cmd_ClearDisplay       = 0x01;
const uint8_t cmd_DisplayOn          = 0x0C;

//!ラインのアドレス 1行目 2行目
const uint8_t lineaddr[] = {0x00,0x40};


//I2C LCD へのコマンドバイトの送信
bool writeCommand(uint8_t cmd){
    I2CLCDControl con;
    con.byte = 0;
    
    return i2cRegisterWrite1Byte(AQM1602addr,con.byte,cmd);
    
}

void I2CLCD_Initialize(void){
    uint8_t timeout = 0;
    const uint8_t timeoutMax = 10;
    
    __delay_ms(100);
    
    writeCommand(cmd_Functionset);
    __delay_us(30);
    
    do{
        if(writeCommand(cmd_FunctionsetEx))timeout =timeoutMax;
        __delay_us(30);
        writeCommand(cmd_ExInternalOSCFreq);
        __delay_us(30);
        writeCommand(cmd_ExContrastSet);    
        __delay_us(30);    
        writeCommand(cmd_ExPowerControl);
        __delay_us(30);   
        writeCommand(cmd_ExFollowerControl);
        __delay_ms(200);
        writeCommand(cmd_Functionset);
       __delay_us(30);
    }while(timeout<timeoutMax);

    writeCommand(cmd_ClearDisplay);
    __delay_us(30);
    writeCommand(cmd_DisplayOn);
    __delay_ms(2);    
}

void writeLine(uint8_t* string,uint8_t cnt,uint8_t line){
    
    DDRSetCmd cmd_ddr;
    cmd_ddr.DDRAMBit = 1;
    cmd_ddr.DDRAMAddr = lineaddr[line-1];
    
    I2CLCDControl con;
    con.byte = 0;
    con.RS = 1;
    
    writeCommand(cmd_ddr.byte);
    
    for(int i=0;i < cnt;i++){
        i2cRegisterWrite1Byte(AQM1602addr, con.byte, string[i]);
        __delay_us(30);
    }
}

void writeLine2(uint8_t* string,uint8_t cnt,uint8_t line){
    
    DDRSetCmd cmd_ddr;
    cmd_ddr.DDRAMBit = 1;
    cmd_ddr.DDRAMAddr = lineaddr[line-1];
    
    I2CLCDControl con;
    con.byte = 0;
    con.RS = 1;
    
    uint8_t buff[16*2];
    
    I2C_MESSAGE_STATUS status;
    
    writeCommand(cmd_ddr.byte);
    con.CO = 1;
    for(int i=0;i < cnt;i++){
        if(cnt == i+1){
            con.CO = 0;
        }
        buff[i] = con.byte;
        buff[i+1] = *(string+1);
    }
    i2cWrite(AQM1602addr, buff, cnt*2, &status);
     __delay_us(30);
}
