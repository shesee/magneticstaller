#include <xc.h>
#include "mcc_generated_files/device_config.h"
#include "i2cGeneric.h"
#include "i2cLCD.h"


//!I2Cアドレス
static const uint8_t AQM1602addr = 0x7C;

//!初期化のコマンド
static const uint8_t cmd_Functionset        = 0x38;//8bit 1/6duty notDH
static const uint8_t cmd_FunctionsetEx      = 0x39;//IS セット
static const uint8_t cmd_ExInternalOSCFreq  = 0x14;//1/5bias 380kHz
static const uint8_t cmd_ExContrastSet      = 0x73;//Contrast LSB 3
static const uint8_t cmd_ExPowerControl     = 0x56;//ICON OFF VoltageBooster ON Contrast MSB 32
static const uint8_t cmd_ExFollowerControl  = 0x6C;//FC ON AMPSET 8
static const uint8_t cmd_ClearDisplay       = 0x01;
static const uint8_t cmd_DisplayOn          = 0x0C;

//!ラインのアドレス 1行目 2行目
static const uint8_t lineaddr[] = {0x00,0x40};


// @breif I2C LCD へのコマンドバイトの送信
// @param コマンドバイト
// @return 実行の成否 
bool writeCommand(uint8_t cmd){
    I2CLCDControl con;
    con.byte = 0;
    
    return i2cRegisterWrite1Byte(AQM1602addr,con.byte,cmd);
    
}

bool I2CLCD_Initialize(void){     
    __delay_ms(100);
    bool bComplete = true;
    
    bComplete = writeCommand(cmd_Functionset);
    __delay_us(30); 
    if(bComplete){bComplete = writeCommand(cmd_FunctionsetEx); }else{ return bComplete;};
    __delay_us(30);
    if(bComplete){bComplete = writeCommand(cmd_ExInternalOSCFreq); }else{ return bComplete;};
    __delay_us(30);
    if(bComplete){bComplete = writeCommand(cmd_ExContrastSet); }else{ return bComplete;};    
    __delay_us(30);    
    if(bComplete){bComplete = writeCommand(cmd_ExPowerControl); }else{ return bComplete;};
    __delay_us(30);   
    if(bComplete){bComplete = writeCommand(cmd_ExFollowerControl); }else{ return bComplete;};
    __delay_ms(200);
    if(bComplete){bComplete = writeCommand(cmd_Functionset); }else{ return bComplete;};
   __delay_us(30);
    if(bComplete){bComplete = writeCommand(cmd_ClearDisplay); }else{ return bComplete;};
    __delay_us(30);
    if(bComplete){bComplete = writeCommand(cmd_DisplayOn); }else{ return bComplete;};
    __delay_ms(2);
    
    return bComplete;
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
        buff[i*2] = con.byte;
        buff[i*2+1] = *(string+1);
    }
    i2cWrite(AQM1602addr, buff, cnt*2, &status);
     __delay_us(30);
}
