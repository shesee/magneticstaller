/* 
 * File:   timer0Handler.h
 * Author: blood
 *
 * Created on January 3, 2019, 1:54 PM
 */

#ifndef TIMER0HANDLER_H
#define	TIMER0HANDLER_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#ifdef	__cplusplus
extern "C" {
#endif

//タイマー0ハンドラを初期化して回転数を計算する。
extern void tmr0Handler_Initialize(void);


#ifdef	__cplusplus
}
#endif

#endif	/* TIMER0HANDLER_H */

