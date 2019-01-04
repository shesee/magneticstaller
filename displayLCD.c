#include "Varient.h"
#include "i2cLCD.h"
#include "displayLCD.h"
                        //123456789ABCDEF
static uint8_t line1[] = "MTR    RPM/    ";
static uint8_t line2[] = "HTR    C  /    ";

void putd(uint8_t val,uint8_t* buff){
    int i = 3 ;

    do {
        i-- ;
        buff[i] = (char)((val%10) + 0x30) ;
        val = val / 10 ;
    } while(val != 0) ;
}


void displayLCD(void){
    putd(iMotorRotate,line1+3);
    putd(iPWMMotor,line1+12);
    putd(iHeaterTemp,line2+3);
    putd(iPWMHeater,line2+12);    
    
    writeLine(line1,16,1);
    writeLine(line2,16,2);
}



