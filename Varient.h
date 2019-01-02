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
    
#define iPWMMorterMax  63 //ロータリーエンコーダー値 MAX モーター
#define iPWMMorterMin  6  //ロータリーエンコーダー値 MIN モーター

#define iPWMHeaterMax  63 //ロータリーエンコーダー値 MAX ヒーター　
#define iPWMHeaterMin  0  //ロータリーエンコーダー値 MIN ヒーター

#define SLAVE_I2C_GENERIC_RETRY_MAX     10//I2C送受信リトライ回数
    
extern volatile int16_t iPWMMorter; //モーターのPWM値 8bit
extern volatile int16_t iPWMHeater; //ヒーターのPWM値 6bit 0-64

extern volatile uint8_t sMorter;//モーターの状態

extern volatile uint8_t iHeaterTemp; //ヒーター温度
extern volatile uint8_t iMorterRotateCnt; //ホール素子カウント
extern volatile uint8_t iMorterRotate; //ローター回転数

//extern uint8_t strLCDbuff[16]; //LCD表示内容


#ifdef	__cplusplus
}
#endif

#endif	/* STATICVARIENT_H */

