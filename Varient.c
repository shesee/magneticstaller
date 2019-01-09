#include "Varient.h"

volatile int16_t iPWMMotor = PWMMotorMin; 
volatile int16_t iPWMHeater = PWMHeaterMin;

volatile int8_t  iHeaterTemp = 0;;
volatile uint8_t iMotorRotateCnt = 0; 
volatile uint16_t iMotorRotate = 0;


volatile int16_t iPrevPWMMotor = 0;

volatile int16_t iPrevPWMHeater = 0; 

volatile int8_t  iPrevHeaterTemp = 0;

volatile uint16_t iPrevMotorRotate = 0;

volatile int8_t  PrevFAIL_PORT = 0;
