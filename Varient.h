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
    
#define iPWMMotorMax  63 //ロータリーエンコーダー値 MAX モーター
#define iPWMMotorMin  6  //ロータリーエンコーダー値 MIN モーター

#define iPWMHeaterMax  63 //ロータリーエンコーダー値 MAX ヒーター　
#define iPWMHeaterMin  0  //ロータリーエンコーダー値 MIN ヒーター

#define SLAVE_I2C_GENERIC_RETRY_MAX     10//I2C送受信リトライ回数
    
extern volatile int16_t iPWMMotor; //モーターのPWM値 8bit
extern volatile int16_t iPWMHeater; //ヒーターのPWM値 6bit 0-64

extern volatile uint8_t sMotor;//モーターの状態

extern volatile int8_t  iHeaterTemp; //ヒーター温度
extern volatile uint8_t iMotorRotateCnt; //ホール素子カウント
extern volatile uint16_t iMotorRotate; //ローター回転数



#ifdef	__cplusplus
}
#endif

#endif	/* STATICVARIENT_H */

