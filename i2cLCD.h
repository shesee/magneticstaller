/* 
 * File:   i2cLCD.h
 * Author: blood
 *
 * Created on January 1, 2019, 12:45 AM
 */

#ifndef I2CLCD_H
#define	I2CLCD_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#ifdef	__cplusplus
extern "C" {
#endif
// @brief LCDコントロ－ルバイトビットフィールド
// @brief 他のI2Cデバイスのレジスタアドレスに該当する
typedef union {
    uint8_t byte;
    
    struct {
        unsigned RESERVE :6;
        unsigned RS      :1;//1 data ,0 command
        unsigned CO      :1;//1 継続コマンド 0　最後のコマンド
    };   
}I2CLCDControl;

// @brief テキスト出力先RAMアドレス指定制御コマンド
// @brief 出力先アドレスは1行目が0x00 2行目が0x40
typedef union {
    uint8_t byte;
    
    struct {
        unsigned DDRAMAddr:7;//DDRAM指定バイトアドレス
        unsigned DDRAMBit :1;//DDRAM指定コマンド 1
    };
}DDRSetCmd;

// @brief LCDの初期化
// @brief 規定のI2C LCD初期化手順を行う
extern void I2CLCD_Initialize(void);

// @brief LCD1ラインのラインの描画
// @param string 16文字までののuint8_t 配列
// @param cnt    文字列の長さ
// @param line   1 or 2 表示する行 0を使わないこと
extern void writeLine(uint8_t* string,uint8_t cnt,uint8_t line);

// @brief LCD1ラインのラインの描画 連続書き子機モード
// @param string 16文字までののuint8_t 配列
// @param cnt    文字列の長さ
// @param line   1 or 2 表示する行 0を使わないこと
extern void writeLine2(uint8_t* string,uint8_t cnt,uint8_t line);
#ifdef	__cplusplus
}
#endif

#endif	/* I2CLCD_H */

