/* 
 * File:   displayLCD.h
 * Author: blood
 *
 * Created on January 4, 2019, 7:55 PM
 */

#ifndef DISPLAYLCD_H
#define	DISPLAYLCD_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#ifdef	__cplusplus
extern "C" {
#endif

//モータードライバの障害別の列挙型
enum{
    OCP,//過電流
    UVLO,//低電圧
    OTS,//過熱
    ILIMIT//電流制限
};   
    
//LCDへのモーター回転数 PWM値　ヒーター温度 PWM値の表示
extern void displayLCD(void);

//LCDへのデバッグ出力　1行目に先頭から出力される
// @param str 出力する文字列
// @param cnt 文字列の長さ
extern void debugWrite(const char* str,uint8_t cnt);

//LCDへの数値のデバッグ出力　1行目に先頭から出力される
// @param val 出力する8bitの値　キャストしてね
extern void debugWriteVal(uint8_t val);

//LED表示の初期化　バッファの初期化
extern void displayLCD_Initialize(void);
#ifdef	__cplusplus
}
#endif

#endif	/* DISPLAYLCD_H */

