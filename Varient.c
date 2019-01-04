#include "Varient.h"

volatile int16_t iPWMMotor = iPWMMotorMin; //モーターのPWM値 8bit
volatile int16_t iPWMHeater = iPWMHeaterMin; //ヒーターのPWM値 6bit 0-64

volatile int8_t  iHeaterTemp = 0;; //ヒーター温度
volatile uint8_t iMotorRotateCnt = 0; //ホール素子カウント
volatile uint16_t iMotorRotate = 0; //ローター回転数RPM

volatile uint8_t sMotor = 0;
