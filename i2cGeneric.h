/* 
 * File:   i2cGeneric.h
 * Author: blood
 *
 * Created on 2019/01/02, 18:02
 */

#ifndef I2CGENERIC_H
#define	I2CGENERIC_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "mcc_generated_files/i2c.h"

#ifdef	__cplusplus
extern "C" {
#endif
    
// @bieif I2Cデバイスにブロック形で書き込む
// @param slaveaddr I2Cスレーブアドレス 7bit
// @param pData     デバイスに書き込むデータ
// @param count     データ長
// @param status    結果
extern void i2cWrite(uint16_t slaveaddr, uint8_t* pData, uint8_t count, I2C_MESSAGE_STATUS* status);

// brief I2Cデバイスからブロック形で読みこむ
// @param slaveaddr I2Cスレーブアドレス 7bit
// @param pwData    デバイスに書き込むデータ
// @param wcount    書き込むデータ長
// @param pData     I2Dデバイスから受信したデータ
// @param count     受信するデータ長 際限なくデータを送ってくるデバイスがあるのでNACKで強制的に受信を終了する。
// @param status    結果
extern void i2cRead(uint16_t slaveaddr, uint8_t* pwData, uint8_t wcount, uint8_t* pData, uint8_t icount, I2C_MESSAGE_STATUS* status);

// @brief レジスタ型のI2Cデバイスに1バイト書き込む
// @param slaveaddr I2Cスレーブアドレス 7bit 型は16bitだけど
// @param regaddr   I2Cデバイスのレジスタのアドレスデーター　1byte目のデータ
// @param data      I2Cデバイスのレジスタに書き込む内容 2byte目のデータ
// @return          成功したか否か
extern bool i2cRegisterWrite1Byte(uint16_t slaveaddr, uint8_t regaddr ,uint8_t data);

// @brief レジスタ型のデバイスから読みこむ
// @param slaveaddr I2Cスレーブアドレス 7bit 型は16bitだけど
// @param regaddr   I2Cデバイスのレジスタのアドレスデーター　こちらから送信する1byte
// @param pData     こちらの読み込み要求に対してスレーブが送ってくるデーター 1byteとは限らない。
// @return          成功したか否か
extern bool i2cRegisterRead1Byte(uint16_t slaveaddr, uint8_t regaddr, uint8_t* pData);

#ifdef	__cplusplus
}
#endif

#endif	/* I2CGENERIC_H */

