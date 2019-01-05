/* 
 * File:   rmpHole.h
 * Author: blood
 *
 * Created on January 3, 2019, 1:40 PM
 */

#ifndef RMPHOLE_H
#define	RMPHOLE_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#ifdef	__cplusplus
extern "C" {
#endif

//外部割り込みを設定し
//ホールICのネガティブONの信号で割り込みを発生させiMotorRotateCntに反映する
extern void Hole_Initialize(void);


#ifdef	__cplusplus
}
#endif

#endif	/* RMPHOLE_H */

