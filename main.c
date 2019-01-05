/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F1508
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/i2c.h"
#include "Varient.h"
#include "rtEnc.h"
#include "timer0Handler.h"
#include "rpmHole.h"
#include "i2cMotor.h"
#include "i2cTherm.h"
#include "i2cLCD.h"
#include "displayLCD.h"

/*
                         Main application
 */
void main(void){
    // initialize the device
    SYSTEM_Initialize();
    
    //ホール素子検出の初期化
    Hole_Initialize(); 
    
    //Timer 0 WDT初期化 回転数計算
    tmr0Handler_Initialize();
    
    //ロータリーエンコーダーの初期化
    RE_Initialize();
    
    //PWM デューティー比の初期設定
    SetPWMMorter();
    SetPWMHeater();
    
    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:
    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    //Enable the Peripheral Interrupts      
    INTERRUPT_PeripheralInterruptEnable();
 
    //モーターを初期状態に
    Motor_Initialize();
    zeroMotorParam();
    
    //温度の初期値を読みこむ
    if(!getTemp())iHeaterTemp=127;
    
    //LCD初期化
    I2CLCD_Initialize();
    
    //LCD表示初期化
    displayLCD_Initialize();
    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    while (1){
        uint8_t temp;
        //モータードライバのFAULTピンがネガティブの場合、理由をとってくる。
        if(!FAIL_PORT){
            GetFaultState();
        }
        //モーターがFAULTの場合はモーターを初期化する。
        //それ以外の場合はPWM値にしたがってモータードライバのスピードを設定する。
        if(sMotor.byte){            
            zeroMotorParam();            
        }else{           
            SetMotorSpeed();       
        }
        //温度をとってくる
        temp = getTemp();
        
        //PWM デューティー比の設定
        SetPWMMorter();
        SetPWMHeater();
        
        //LCD表示
        displayLCD();
        
        __delay_ms(200);
        
    }
}
/**
 End of File
*/