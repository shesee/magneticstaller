#include "Varient.h"
#include "i2cLCD.h"
#include "i2cMotor.h"
#include "displayLCD.h"
//モーター障害時の表示文字列
const char* mtss[] =       {" OverVoltage ",
                            " LowVoltage  ",
                            " OverHeat    ",
                            " LimitPower  "
                            };
                        //0123456789ABCDEF
const char* line1temp =  "MTR    RPM/     ";
const char* line2temp =  "HTR    C  /     ";

static char line1[16];//ライン1のバッファ
static char line2[16];//ライン2のバッファ


void displayLCD_Initialize(void){
    for(int i=0;i<16;i++){
        line1[i] = line1temp[i];
        line2[i] = line2temp[i];        
    }   
};

//10進数をラインバッファに出力する
// @param val 出力する8bitの数値
// @param buff 出力先のバッファ 3個の文字列を上書きする
void putd(uint8_t val,char* buff){
    int i = 3;
    while(i != 0){
        i--;
        buff[i] = (char)((val%10) + 0x30) ;
        val = val / 10 ;
    };
};
//文字列をラインバッファに出力する
// @param str 出力する文字列
// @param cnt 文字列の長さ
// @param buff 出力先のバッファ　バッファオーバーフローにならないように
void putc(const char* str,uint8_t cnt ,char* buff){
    
    for(int i = 0;i < cnt;i++){
        buff[i] = str[i];
    };
};

void displayLCD(void){
    if(!sMotor.byte){
        putd(iMotorRotate,line1+3);
        putd(iPWMMotor,line1+13);
    }else{
        if(sMotor.OCP){
            putc(mtss[OCP],12,line1+3);
        }else if(sMotor.UVLO){
            putc(mtss[UVLO],12,line1+3);
        }else if(sMotor.OTS){
            putc(mtss[OTS],12,line1+3);
        }else if(sMotor.UVLO){
            putc(mtss[ILIMIT],12,line1+3);
        }       
    }
    putd(iHeaterTemp,line2+3);
    putd(iPWMHeater,line2+13);    
    
    writeLine((uint8_t*)line1,16,1);
    writeLine((uint8_t*)line2,16,2);
};

void debugWrite(const char* str,uint8_t cnt){
    putc(str,cnt,line1);
    writeLine((uint8_t*)line1,16,1);
};

void debugWriteVal(uint8_t val){
    putd(val,line1);
    writeLine((uint8_t*)line1,16,1);
};



