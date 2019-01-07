#include "Varient.h"
#include "i2cLCD.h"
#include "i2cMotor.h"
#include "displayLCD.h"

//!モーター障害時の表示文字列
static const char* mtss[] =       {" OverVoltage ",
                            " LowVoltage  ",
                            " OverHeat    ",
                            " LimitPower  "
                            };

                        //0123456789ABCDEF
//1ラインバッファ1のテンプレート
static const char* line1temp =  "MTR    RPM/     ";
//!ラインバッファ2のテンプレート
static const char* line2temp =  "HTR    C  /     ";

//!ライン1のバッファ
static char line1[LINE_LENGTH];
//ライン2のバッファ
static char line2[LINE_LENGTH];

// @brief ラインバッファにテンプレートをコピーする。
void displayLCD_Initialize(void){
    for(int i=0;i<LINE_LENGTH;i++){
        line1[i] = line1temp[i];
        line2[i] = line2temp[i];        
    }   
};

// @brief 10進数をラインバッファに出力する
// @param val 出力する8bitの数値
// @param buff 出力先のバッファ 3個の文字列を上書きする 0サプレス
void putd(uint8_t val,char* buff){
    int i = 3;
    while(i != 0){
        i--;
        buff[i] = (char)((val%10) + 0x30) ;
        val = val / 10 ;
    };
};

// @brief 文字列をラインバッファに出力する
// @param str 出力する文字列
// @param cnt 文字列の長さ
// @param buff 出力先のバッファ　バッファオーバーフローにならないように
void putc(const char* str,uint8_t cnt ,char* buff){
    
    for(int i = 0;i < cnt;i++){
        buff[i] = str[i];
    };
};

void displayLCD(void){
    // @brief モーターFAULT以外の場合は回転数とPWM出力を表示する
    if(!sMotor.byte){
        putd(iMotorRotate,line1+3);
        putd(iPWMMotor,line1+13);
    }else{
        //モーターFAULTの原因をLCDに出力する
        if(sMotor.OCP){
            putc(mtss[OCP],13,line1+3);
        }else if(sMotor.UVLO){
            putc(mtss[UVLO],13,line1+3);
        }else if(sMotor.OTS){
            putc(mtss[OTS],13,line1+3);
        }else if(sMotor.ILIMIT){
            putc(mtss[ILIMIT],13,line1+3);
        }       
    }
    // @briefヒーターの温度とPWM状態を出力する
    putd(iHeaterTemp,line2+3);
    putd(iPWMHeater,line2+13);    
    // @brief LCDにラインバッファを出力する
    writeLine((uint8_t*)line1,LINE_LENGTH,1);
    writeLine((uint8_t*)line2,LINE_LENGTH,2);
    
};

void debugWrite(const char* str,uint8_t cnt){
    putc(str,cnt,line1);
    writeLine((uint8_t*)line1,LINE_LENGTH,1);
};

void debugWriteVal(uint8_t val){
    putd(val,line1);
    writeLine((uint8_t*)line1,LINE_LENGTH,1);
};



