/* 
 * File:   i2ctherm.h
 * Author: blood
 *
 * Created on January 1, 2019, 12:46 AM
 */

#ifndef I2CTHERM_H
#define	I2CTHERM_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#ifdef	__cplusplus
extern "C" {
#endif

extern int8_t getTemp(void);//ヒーター温度の取得


#ifdef	__cplusplus
}
#endif

#endif	/* I2CTHERM_H */

