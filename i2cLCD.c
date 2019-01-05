#include <xc.h>
#include "mcc_generated_files/device_config.h"
#include "i2cGeneric.h"
#include "i2cLCD.h"


//I2Cアドレス
const uint8_t AQM1602addr = 0x3E;

//初期化のコマンド
const uint8_t cmd_Functionset        = 0x38;
const uint8_t cmd_FunctionsetEx      = 0x39;
const uint8_t cmd_ExInternalOSCFreq  = 0x14;
const uint8_t cmd_ExContrastSet        = 0x72;
const uint8_t cmd_ExPowerControl       = 0x5E;
const uint8_t cmd_ExFollowerControl    = 0x6B;
const uint8_t cmd_ClearDisplay       = 0x01;
const uint8_t cmd_DisplayOn          = 0x0C;

const uint8_t lineaddr[] = {0x00,0x40};//ラインのアドレス 1行目 2行目


//I2C LCD へのコマンドバイトの送信
void writeCommand(uint8_t cmd){
    I2CLCDControl con;
    con.byte = 0;
    
    i2cRegisterWrite1Byte(AQM1602addr,con.byte,cmd);
    
}

void I2CLCD_Initialize(void){
    __delay_ms(100);
    
    writeCommand(cmd_Functionset);
    __delay_us(30);
    writeCommand(cmd_FunctionsetEx);
    __delay_us(30);
    writeCommand(cmd_ExInternalOSCFreq);
    __delay_us(30);
    writeCommand(cmd_ExContrastSet);    
    __delay_us(30);    
    writeCommand(cmd_ExPowerControl);
    __delay_us(30);   
    writeCommand(cmd_ExFollowerControl);
    __delay_ms(100);    
    writeCommand(cmd_Functionset);
    __delay_us(30);
    writeCommand(cmd_ClearDisplay);
    __delay_us(30);
    writeCommand(cmd_DisplayOn);
    __delay_us(30);    
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
        i2cRegisterWrite1Byte(AQM1602addr,con.byte,string[i]);
        __delay_us(30);
    }
}

