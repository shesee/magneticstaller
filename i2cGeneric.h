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

#ifdef	__cplusplus
extern "C" {
#endif
    
//レジスタ型のI2Cデバイスに1バイト書き込む
// @param slaveaddr I2Cスレーブアドレス 7bit 型は16bitだけど
// @param regaddr   I2Cデバイスのレジスタのアドレスデーター　1byte目のデータ
// @param data      I2Cデバイスのレジスタに書き込む内容 2byte目のデータ
extern void i2cRegisterWrite1Byte(uint16_t slaveaddr, uint8_t regaddr ,uint8_t data);
//レジスタ型のデバイスから読みこむ
// @param slaveaddr I2Cスレーブアドレス 7bit 型は16bitだけど
// @param regaddr   I2Cデバイスのレジスタのアドレスデーター　こちらから送信する1byte
// @param pData     こちらの読み込み要求に対してスレーブが送ってくるデーター 1byteとは限らない。
extern bool i2cRegisterRead1Byte(uint16_t slaveaddr, uint8_t regaddr, uint8_t* pData);

#ifdef	__cplusplus
}
#endif

#endif	/* I2CGENERIC_H */

