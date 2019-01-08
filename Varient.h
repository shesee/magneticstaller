/* 
 * File:   staticVarient.h
 * Author: blood
 *
 * Created on January 1, 2019, 12:28 PM
 */

#ifndef STATICVARIENT_H
#define	STATICVARIENT_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#ifdef	__cplusplus
extern "C" {
#endif
    
#define PWMMotorMax  63 //ロータリーエンコーダー値 MAX モーター
#define PWMMotorMin  6  //ロータリーエンコーダー値 MIN モーター

#define PWMHeaterMax  63 //ロータリーエンコーダー値 MAX ヒーター　
#define PWMHeaterMin  0  //ロータリーエンコーダー値 MIN ヒーター

//!モーターのPWM値 8bit    
extern volatile int16_t iPWMMotor;
//!ヒーターのPWM値 6bit 0-64
extern volatile int16_t iPWMHeater; 
//!ヒーター温度
extern volatile int8_t  iHeaterTemp;
//!ホール素子カウント
extern volatile uint8_t iMotorRotateCnt;
//!ローター回転数
extern volatile uint16_t iMotorRotate; 

//!モーターのPWM値 8bit  以前  
extern volatile int16_t iPrevPWMMotor;
//!ヒーターのPWM値 6bit 0-64  以前 
extern volatile int16_t iPrevPWMHeater; 
//!ヒーター温度  以前 
extern volatile int8_t  iPrevHeaterTemp;
//!ローター回転数  以前 
extern volatile uint16_t iPrevMotorRotate; 

#ifdef	__cplusplus
}
#endif

#endif	/* STATICVARIENT_H */

