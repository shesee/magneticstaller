#include <xc.h>
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/pwm1.h"
#include "mcc_generated_files/pwm2.h"
#include "mcc_generated_files/pwm4.h"
#include "rtEnc.h"
#include "Varient.h"

const uint8_t rePattern[] ={0,1,-1,0,-1,0,0,1,1,0,0,-1,0,-1,1,0};//ロータリエンコーダーの参照表
static uint8_t reIndex1=0;//ロータリーエンコーダー1のインデックス値
static uint8_t reIndex2=0;//ロータリーエンコーダー2のインデックス値

//ロータリエンコーダー1のデコード
int8_t readRE1(void){
    reIndex1 = ((0x3&reIndex1)<<2) | (RE1_B_GetValue()<<1) | RE1_A_GetValue();
    return rePattern[reIndex1];
};
//ロータリーエンコーダー2のデコード
int8_t readRE2(void){
    reIndex2 = ((0x3&reIndex2)<<2) | (RE2_B_GetValue()<<1) | RE2_A_GetValue();
    return rePattern[reIndex2];
};

//ロータリエンコーダー1をモーターPWMの値に変換
void cbRE1(void){   
    iPWMMotor += readRE1();
    if(iPWMMotor > iPWMMotorMax)iPWMMotor = iPWMMotorMax;
    if(iPWMMotor < iPWMMotorMin)iPWMMotor=iPWMMotorMin;    
};

//ロータリエンコーダー2をヒーターPWMの値に変換
void cbRE2(void){
    iPWMHeater += readRE2();
    if(iPWMHeater > iPWMHeaterMax)iPWMHeater = iPWMHeaterMax;
    if(iPWMHeater < iPWMHeaterMin)iPWMHeater = iPWMHeaterMin;
};

//カスタム割り込みハンドラー
void IOCAF4_CustumInterruptHandler(void){
    cbRE1();
};

void IOCAF5_CustumInterruptHandler(void){
    cbRE1();
};

void IOCBF5_CustumInterruptHandler(void){
    cbRE2();
};

void IOCBF7_CustumInterruptHandler(void){
    cbRE2();
};

//
void RE_Initialize(void){
    
    IOCAF4_SetInterruptHandler(IOCAF4_CustumInterruptHandler);
    IOCAF5_SetInterruptHandler(IOCAF5_CustumInterruptHandler);
    IOCBF5_SetInterruptHandler(IOCBF5_CustumInterruptHandler);
    IOCBF7_SetInterruptHandler(IOCBF7_CustumInterruptHandler);
};

void SetPWMMorter(void){
    //ロータリーエンコーダーのLEDの制御
    if(iPWMMotor == iPWMMotorMin){
        RE1LED_SetHigh();// ON OFF LED
        PWM2_LoadDutyValue(0);//Set ON LED Duty to 0
    }else{
        RE1LED_SetLow();//OFF OFF LED
        PWM2_LoadDutyValue((uint16_t)iPWMMotor);//Set ON LED Duty to value
    };
    //TODO
};

void SetPWMHeater(void){
    //ロータリーエンコーダーのLEDの制御
    if(iPWMHeater == 0){
        RE2LED_SetHigh();// ON OFF LED
        PWM4_LoadDutyValue(0);//Set ON LED Duty to 0
    }else{
        RE2LED_SetLow();//OFF OFF LED
        PWM4_LoadDutyValue((uint16_t)(iPWMHeater));//Set ON LED Duty to value
    };
    
    PWM1_LoadDutyValue(iPWMHeater);
};