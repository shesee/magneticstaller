#include <xc.h>
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/pwm1.h"
#include "mcc_generated_files/pwm2.h"
#include "mcc_generated_files/pwm4.h"
#include "mcc_generated_files/device_config.h"
#include "rtEnc.h"
#include "Varient.h"

//! 状態変化割り込みの呼び出し数モータ－
static uint8_t cntRE1Intr = 0;

//! 状態変化割り込みの呼び出し数ヒーター
static uint8_t cntRE2Intr = 0;

//!ロータリエンコーダーの参照表
static const uint8_t rePattern[] ={0,1,-1,0,-1,0,0,1,1,0,0,-1,0,-1,1,0};

//!ロータリーエンコーダー1のインデックス値
static uint8_t reIndex1=0;

//!ロータリーエンコーダー2のインデックス値
static uint8_t reIndex2=0;

//ロータリエンコーダー1インタラプト回数を計測する
void cbRE1(void){   
    cntRE1Intr++;
};

//ロータリエンコーダーインタラプト回数を計測する
void cbRE2(void){
    cntRE2Intr++;
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

// @brief ロータリエンコーダー1のデコード
int8_t readRE1(void){
    if(cntRE1Intr){//取りこぼしても仕方ない
        __delay_ms(10);//チャタリングの防止
        reIndex1 = ((0x3&reIndex1)<<2) | (RE1_B_GetValue()<<1) | RE1_A_GetValue();
        cntRE1Intr = 0;
        return rePattern[reIndex1];
    }else{
        return 0;
    }
};
// @brief ロータリーエンコーダー2のデコード
int8_t readRE2(void){
    if(cntRE2Intr){//取りこぼしても仕方ない
        __delay_ms(10);//チャタリングの防止
        reIndex2 = ((0x3&reIndex2)<<2) | (RE2_B_GetValue()<<1) | RE2_B_GetValue();
        cntRE2Intr = 0;
        return rePattern[reIndex2];
    }else{
        return 0;
    }
};

//
void calcRE1(void){
    iPWMMotor += readRE1();
    if(iPWMMotor > PWMMotorMax)iPWMMotor = PWMMotorMax;
    if(iPWMMotor < PWMMotorMin)iPWMMotor=PWMMotorMin;       
}

void calcRE2(void){
    iPWMHeater += readRE2();
    if(iPWMHeater > PWMHeaterMax)iPWMHeater = PWMHeaterMax;
    if(iPWMHeater < PWMHeaterMin)iPWMHeater = PWMHeaterMin;
    
}



void SetPWMMorter(void){
    //ロータリーエンコーダーのデコード
    calcRE1();
    //ロータリーエンコーダーのLEDの制御
    if(iPWMMotor == PWMMotorMin){
        RE1LED_SetHigh();
        PWM2_LoadDutyValue(0);//Set ON LED Duty to 0
    }else{
        RE1LED_SetLow();
        PWM2_LoadDutyValue((uint16_t)iPWMMotor);//Set ON LED Duty to value
    };
};

void SetPWMHeater(void){
    //ロータリーエンコーダーのデコード
    calcRE2();
    //ロータリーエンコーダーのLEDの制御
    if(iPWMHeater == PWMHeaterMin){
        RE2LED_SetHigh();
        PWM4_LoadDutyValue(0);//Set ON LED Duty to 0
    }else{
        RE2LED_SetLow();
        PWM4_LoadDutyValue((uint16_t)(iPWMHeater));//Set ON LED Duty to value
    };
    
    PWM1_LoadDutyValue(iPWMHeater);
};