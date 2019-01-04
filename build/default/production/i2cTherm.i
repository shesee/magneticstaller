# 1 "i2cTherm.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "i2cTherm.c" 2
# 1 "./i2cTherm.h" 1
# 11 "./i2cTherm.h"
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
# 11 "./i2cTherm.h" 2

# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.00\\pic\\include\\c99\\stdbool.h" 1 3
# 12 "./i2cTherm.h" 2

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
# 13 "./i2cTherm.h" 2






extern int8_t getTemp(void);
# 1 "i2cTherm.c" 2

# 1 "./i2cGeneric.h" 1
# 20 "./i2cGeneric.h"
extern void i2cRegisterWrite1Byte(uint16_t slaveaddr, uint8_t regaddr ,uint8_t data);
extern _Bool i2cRegisterRead1Byte(uint16_t slaveaddr, uint8_t regaddr, uint8_t* pData);
# 2 "i2cTherm.c" 2

# 1 "./Varient.h" 1
# 27 "./Varient.h"
extern volatile int16_t iPWMMotor;
extern volatile int16_t iPWMHeater;

extern volatile uint8_t sMotor;

extern volatile int8_t iHeaterTemp;
extern volatile uint8_t iMotorRotateCnt;
extern volatile uint16_t iMotorRotate;
# 3 "i2cTherm.c" 2


const uint16_t stts751addr = 0x72;
const uint8_t tempHighreg = 0x00;
const uint8_t tempLowreg = 0x02;


int8_t getTemp(void){
    uint8_t temp = 0;

    if(i2cRegisterRead1Byte(stts751addr, tempHighreg, &temp)){
        iHeaterTemp = temp;
    }
    return (int8_t)temp;

}
