/* 
 * File:   i2cMorter.h
 * Author: blood
 *
 * Created on 2019/01/01, 21:48
 */

#ifndef I2CMORTER_H
#define	I2CMORTER_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#ifdef	__cplusplus
extern "C" {
#endif
     
//DRV8830 レジスタ01 回転方向　回転数制御
typedef union {
    uint8_t byte;
    struct {
        unsigned IN1     :1;// 0:0 Standby/coast 0:1 Reverse 
        unsigned IN2     :1;// 1:0 Forward       1:1 Brake
        unsigned VSET    :6;//PWM Value 6～63まで
    };
} DRV8830Reg1;
//DRV8830 レジスタ02
typedef union {
    uint8_t byte;

    struct {
        unsigned FAULT   :1;//FALT bit
        unsigned OCP     :1;//過電流
        unsigned UVLO    :1;//低電圧
        unsigned OTS     :1;//過熱
        unsigned ILIMIT  :1;//電流制限
        unsigned RESERVE :2;
        unsigned CLEAR   :1;//FAULT bit クリア
    };
} DRV8830Reg2;

extern volatile DRV8830Reg2 sMotor;//モーターの状態

//モーターライブラリの初期化
//sMotorの初期化
extern void Motor_Initialize(void);

//モーターの初期化
//モーター回転数を最低に設定し、INビットをスタンバイに設定する
extern void zeroMotorParam(void);

//モータースピードの設定
//PWM値をモータースピードに反映し、INビットを順方向に設定する
extern void SetMotorSpeed(void);

//フォルト状態の取得
//レジスタ02を取得してsMotorに反映する
extern void GetFaultState(void);

#ifdef	__cplusplus
}
#endif

#endif	/* I2CMORTER_H */

