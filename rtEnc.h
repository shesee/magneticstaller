/* 
 * File:   rtenc.h
 * Author: blood
 *
 * Created on January 1, 2019, 12:42 AM
 */

#ifndef RTENC_H
#define	RTENC_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#ifdef	__cplusplus
extern "C" {
#endif


// ロータリエンコーダーの割り込みの初期化
extern void RE_Initialize(void);
//モーターPWMの反映
extern void SetPWMMorter(void);//LEDのみ
//ヒーターPWMの反映
extern void SetPWMHeater(void);

#ifdef	__cplusplus
}
#endif

#endif	/* RTENC_H */

