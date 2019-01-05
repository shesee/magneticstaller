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

#define SLAVE_I2C_GENERIC_RETRY_MAX     10//I2C送受信リトライ回数
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



#ifdef	__cplusplus
}
#endif

#endif	/* STATICVARIENT_H */

