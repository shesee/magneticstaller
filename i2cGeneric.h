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
    

extern void i2cRegisterWrite1Byte(uint16_t slaveaddr, uint8_t regaddr ,uint8_t data);//レジスタ型のデバイスに書き込む
extern bool i2cRegisterRead1Byte(uint16_t slaveaddr, uint8_t regaddr, uint8_t* pData);//レジスタ型のデバイスから読みこむ

#ifdef	__cplusplus
}
#endif

#endif	/* I2CGENERIC_H */

