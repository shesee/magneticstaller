/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F1508
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB 	          :  MPLAB X 4.15	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA2 procedures
#define RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define RA2_GetValue()              PORTAbits.RA2
#define RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define RA2_SetPullup()             do { WPUAbits.WPUA2 = 1; } while(0)
#define RA2_ResetPullup()           do { WPUAbits.WPUA2 = 0; } while(0)
#define RA2_SetAnalogMode()         do { ANSELAbits.ANSA2 = 1; } while(0)
#define RA2_SetDigitalMode()        do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set RE1_A aliases
#define RE1_A_TRIS                 TRISAbits.TRISA4
#define RE1_A_LAT                  LATAbits.LATA4
#define RE1_A_PORT                 PORTAbits.RA4
#define RE1_A_WPU                  WPUAbits.WPUA4
#define RE1_A_ANS                  ANSELAbits.ANSA4
#define RE1_A_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define RE1_A_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define RE1_A_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define RE1_A_GetValue()           PORTAbits.RA4
#define RE1_A_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define RE1_A_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define RE1_A_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define RE1_A_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define RE1_A_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define RE1_A_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set RE1_B aliases
#define RE1_B_TRIS                 TRISAbits.TRISA5
#define RE1_B_LAT                  LATAbits.LATA5
#define RE1_B_PORT                 PORTAbits.RA5
#define RE1_B_WPU                  WPUAbits.WPUA5
#define RE1_B_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define RE1_B_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define RE1_B_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define RE1_B_GetValue()           PORTAbits.RA5
#define RE1_B_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define RE1_B_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define RE1_B_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define RE1_B_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)

// get/set SDA aliases
#define SDA_TRIS                 TRISBbits.TRISB4
#define SDA_LAT                  LATBbits.LATB4
#define SDA_PORT                 PORTBbits.RB4
#define SDA_WPU                  WPUBbits.WPUB4
#define SDA_ANS                  ANSELBbits.ANSB4
#define SDA_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define SDA_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define SDA_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define SDA_GetValue()           PORTBbits.RB4
#define SDA_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define SDA_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define SDA_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define SDA_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define SDA_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define SDA_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set RE2_A aliases
#define RE2_A_TRIS                 TRISBbits.TRISB5
#define RE2_A_LAT                  LATBbits.LATB5
#define RE2_A_PORT                 PORTBbits.RB5
#define RE2_A_WPU                  WPUBbits.WPUB5
#define RE2_A_ANS                  ANSELBbits.ANSB5
#define RE2_A_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define RE2_A_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define RE2_A_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RE2_A_GetValue()           PORTBbits.RB5
#define RE2_A_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define RE2_A_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define RE2_A_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define RE2_A_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define RE2_A_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define RE2_A_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set SCL aliases
#define SCL_TRIS                 TRISBbits.TRISB6
#define SCL_LAT                  LATBbits.LATB6
#define SCL_PORT                 PORTBbits.RB6
#define SCL_WPU                  WPUBbits.WPUB6
#define SCL_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define SCL_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define SCL_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define SCL_GetValue()           PORTBbits.RB6
#define SCL_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define SCL_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define SCL_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define SCL_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)

// get/set RE2_B aliases
#define RE2_B_TRIS                 TRISBbits.TRISB7
#define RE2_B_LAT                  LATBbits.LATB7
#define RE2_B_PORT                 PORTBbits.RB7
#define RE2_B_WPU                  WPUBbits.WPUB7
#define RE2_B_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define RE2_B_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define RE2_B_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define RE2_B_GetValue()           PORTBbits.RB7
#define RE2_B_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define RE2_B_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define RE2_B_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define RE2_B_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)

// get/set RE1LED aliases
#define RE1LED_TRIS                 TRISCbits.TRISC0
#define RE1LED_LAT                  LATCbits.LATC0
#define RE1LED_PORT                 PORTCbits.RC0
#define RE1LED_ANS                  ANSELCbits.ANSC0
#define RE1LED_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RE1LED_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RE1LED_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RE1LED_GetValue()           PORTCbits.RC0
#define RE1LED_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RE1LED_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define RE1LED_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define RE1LED_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set RC1 procedures
#define RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()              PORTCbits.RC1
#define RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RC1_SetAnalogMode()         do { ANSELCbits.ANSC1 = 1; } while(0)
#define RC1_SetDigitalMode()        do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set RE2LED aliases
#define RE2LED_TRIS                 TRISCbits.TRISC2
#define RE2LED_LAT                  LATCbits.LATC2
#define RE2LED_PORT                 PORTCbits.RC2
#define RE2LED_ANS                  ANSELCbits.ANSC2
#define RE2LED_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define RE2LED_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define RE2LED_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define RE2LED_GetValue()           PORTCbits.RC2
#define RE2LED_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define RE2LED_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define RE2LED_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define RE2LED_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set FAIL aliases
#define FAIL_TRIS                 TRISCbits.TRISC4
#define FAIL_LAT                  LATCbits.LATC4
#define FAIL_PORT                 PORTCbits.RC4
#define FAIL_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define FAIL_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define FAIL_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define FAIL_GetValue()           PORTCbits.RC4
#define FAIL_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define FAIL_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)

// get/set RC5 procedures
#define RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()              PORTCbits.RC5
#define RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAF4 pin functionality
 * @Example
    IOCAF4_ISR();
 */
void IOCAF4_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF4 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF4 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF4_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAF4_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF4 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF4_SetInterruptHandler() method.
    This handler is called every time the IOCAF4 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF4_SetInterruptHandler(IOCAF4_InterruptHandler);

*/
extern void (*IOCAF4_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF4 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF4_SetInterruptHandler() method.
    This handler is called every time the IOCAF4 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF4_SetInterruptHandler(IOCAF4_DefaultInterruptHandler);

*/
void IOCAF4_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAF5 pin functionality
 * @Example
    IOCAF5_ISR();
 */
void IOCAF5_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF5 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF5 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF5_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAF5_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF5 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF5_SetInterruptHandler() method.
    This handler is called every time the IOCAF5 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF5_SetInterruptHandler(IOCAF5_InterruptHandler);

*/
extern void (*IOCAF5_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF5 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF5_SetInterruptHandler() method.
    This handler is called every time the IOCAF5 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF5_SetInterruptHandler(IOCAF5_DefaultInterruptHandler);

*/
void IOCAF5_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF5 pin functionality
 * @Example
    IOCBF5_ISR();
 */
void IOCBF5_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF5 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF5 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF5_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF5_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF5 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF5_SetInterruptHandler() method.
    This handler is called every time the IOCBF5 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF5_SetInterruptHandler(IOCBF5_InterruptHandler);

*/
extern void (*IOCBF5_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF5 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF5_SetInterruptHandler() method.
    This handler is called every time the IOCBF5 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF5_SetInterruptHandler(IOCBF5_DefaultInterruptHandler);

*/
void IOCBF5_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF7 pin functionality
 * @Example
    IOCBF7_ISR();
 */
void IOCBF7_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF7 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF7 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF7_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF7_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF7 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF7_SetInterruptHandler() method.
    This handler is called every time the IOCBF7 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF7_SetInterruptHandler(IOCBF7_InterruptHandler);

*/
extern void (*IOCBF7_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF7 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF7_SetInterruptHandler() method.
    This handler is called every time the IOCBF7 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF7_SetInterruptHandler(IOCBF7_DefaultInterruptHandler);

*/
void IOCBF7_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/