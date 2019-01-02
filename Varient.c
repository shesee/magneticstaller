#include "Varient.h"

volatile int16_t iPWMMorter = 0; //モーターのPWM値 8bit
volatile int16_t iPWMHeater = 0; //ヒーターのPWM値 6bit 0-64

volatile uint8_t iHeaterTemp = 0;; //ヒーター温度
volatile uint8_t iMorterRotateCnt = 0; //ホール素子カウント
volatile uint8_t iMorterRotate = 0; //ローター回転数RPM

//volatile uint8_t strLCDbuff[16]; //LCD表示内容
volatile uint8_t sMorter = 0;
