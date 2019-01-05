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


// @brief ロータリエンコーダーの割り込みの初期化
// @brief 二つのロータリーエンコーダーのA相 B相を4つの状態変化割り込みに設定する。
extern void RE_Initialize(void);
// @brief モーターPWMの反映
// @brief 割り込みによって増減したPWM値をローターリーエンコーダーのLEDに反映する
extern void SetPWMMorter(void);
// @brief ヒーターPWMの反映
// @brief 割り込みによって増減したPWM値をヒーターのPWMデューティー比に設定する
extern void SetPWMHeater(void);

#ifdef	__cplusplus
}
#endif

#endif	/* RTENC_H */

