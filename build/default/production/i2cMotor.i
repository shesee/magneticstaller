# 1 "i2cMotor.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "i2cMotor.c" 2
# 1 "./Varient.h" 1
# 11 "./Varient.h"
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\c99\\stdint.h" 1 3



# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\c99\\musl_xc8.h" 1 3
# 4 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\c99\\stdint.h" 2 3
# 22 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\c99\\stdint.h" 3
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 135 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned long uintptr_t;
# 150 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long intptr_t;
# 166 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\c99\\bits/alltypes.h" 3
typedef signed char int8_t;




typedef short int16_t;




typedef long int32_t;
# 189 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\c99\\bits/alltypes.h" 3
typedef int32_t intmax_t;







typedef unsigned char uint8_t;




typedef unsigned short uint16_t;




typedef unsigned long uint32_t;
# 225 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\c99\\bits/alltypes.h" 3
typedef uint32_t uintmax_t;
# 22 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\c99\\stdint.h" 2 3


typedef int8_t int_fast8_t;




typedef int8_t int_least8_t;
typedef int16_t int_least16_t;
typedef int32_t int_least32_t;




typedef uint8_t uint_fast8_t;




typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;
typedef uint32_t uint_least32_t;
# 131 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\c99\\stdint.h" 3
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\c99\\bits/stdint.h" 1 3
typedef int32_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint32_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
# 131 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\c99\\stdint.h" 2 3
# 11 "./Varient.h" 2

# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\c99\\stdbool.h" 1 3
# 12 "./Varient.h" 2

# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\c99\\stddef.h" 1 3
# 19 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\c99\\stddef.h" 3
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 22 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long int wchar_t;
# 127 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned size_t;
# 140 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long ptrdiff_t;
# 19 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\c99\\stddef.h" 2 3
# 13 "./Varient.h" 2
# 27 "./Varient.h"
extern volatile int16_t iPWMMotor;
extern volatile int16_t iPWMHeater;

extern volatile uint8_t sMotor;

extern volatile int8_t iHeaterTemp;
extern volatile uint8_t iMotorRotateCnt;
extern volatile uint16_t iMotorRotate;
# 1 "i2cMotor.c" 2

# 1 "./i2cGeneric.h" 1
# 20 "./i2cGeneric.h"
extern void i2cRegisterWrite1Byte(uint16_t slaveaddr, uint8_t regaddr ,uint8_t data);
extern _Bool i2cRegisterRead1Byte(uint16_t slaveaddr, uint8_t regaddr, uint8_t* pData);
# 2 "i2cMotor.c" 2

# 1 "./i2cMotor.h" 1
# 20 "./i2cMotor.h"
typedef union {
    uint8_t byte;
    struct {
        unsigned IN1 :1;
        unsigned IN2 :1;
        unsigned VSET :6;
    };
} DRV8830Reg1;

typedef union {
    uint8_t byte;

    struct {
        unsigned FAULT :1;
        unsigned OCP :1;
        unsigned UVLO :1;
        unsigned OTS :1;
        unsigned ILIMIT :1;
        unsigned RESERVE :2;
        unsigned CLEAR :1;
    };
} DRV8830Reg2;

extern void zeroMotorParam(void);
extern void SetMotorSpeed(void);
void GetFaultState(void);
# 3 "i2cMotor.c" 2





void zeroMotorParam(void){
    DRV8830Reg1 reg1;
    reg1.IN1 = 0;
    reg1.IN2 = 0;
    reg1.VSET = (6&0x3F);

    i2cRegisterWrite1Byte(0xC0,0,reg1.byte);

    DRV8830Reg2 reg2;
    reg2.CLEAR = 1;
    i2cRegisterWrite1Byte(0xC0,1,reg2.byte);

}

void SetMotorSpeed(void){

    if(iPWMMotor == 6){
        zeroMotorParam();
    }else{
        if(!sMotor){
            DRV8830Reg1 reg1;
            reg1.IN1 = 1;
            reg1.IN2 = 0;
            reg1.VSET = (iPWMMotor&0x3F);

            i2cRegisterWrite1Byte(0xC0,0,reg1.byte);
        }
    }
}

void GetFaultState(void){

    DRV8830Reg2 reg2;
    _Bool rtn;

    rtn = i2cRegisterRead1Byte(0xC0,1,&(reg2.byte));
    if(rtn && reg2.byte){
        if(reg2.FAULT){
            sMotor = reg2.byte;
        }
    }
}
