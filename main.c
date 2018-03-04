/*
 * File:   main.c
 * Author: ernie
 * PIC24FJ256GB106
 * Created on March 3, 2018, 3:19 PM
 */
// #define FOSC    (7370000ULL)
#define FOSC    (8000000ULL)




#include <p24FJ256GB106.h>

#include <stdio.h>
#include <stdlib.h>

#include <xc.h>
#define FCY     (FOSC/1)
#include <libpic30.h>
// CONFIG3
#pragma config WPFP = WPFP511           // Write Protection Flash Page Segment Boundary (Highest Page (same as page 170))
#pragma config WPDIS = WPDIS            // Segment Write Protection Disable bit (Segmented code protection disabled)
#pragma config WPCFG = WPCFGDIS         // Configuration Word Code Page Protection Select bit (Last page(at the top of program memory) and Flash configuration words are not protected)
#pragma config WPEND = WPENDMEM         // Segment Write Protection End Page Select bit (Write Protect from WPFP to the last page of memory)

// CONFIG2
#pragma config POSCMOD = HS             // Primary Oscillator Select (HS oscillator mode selected)
#pragma config DISUVREG = OFF           // Internal USB 3.3V Regulator Disable bit (Regulator is disabled)
#pragma config IOL1WAY = ON             // IOLOCK One-Way Set Enable bit (Write RP Registers Once)
#pragma config OSCIOFNC = OFF           // Primary Oscillator Output Function (OSCO functions as CLKO (FOSC/2))
#pragma config FCKSM = CSDCMD           // Clock Switching and Monitor (Both Clock Switching and Fail-safe Clock Monitor are disabled)
#pragma config FNOSC = FRC              // Oscillator Select (Fast RC Oscillator (FRC))
#pragma config PLL_96MHZ = ON           // 96MHz PLL Disable (Enabled)
#pragma config PLLDIV = NODIV           // USB 96 MHz PLL Prescaler Select bits (Oscillator input used directly (4MHz input))
#pragma config IESO = ON                // Internal External Switch Over Mode (IESO mode (Two-speed start-up) enabled)

// CONFIG1
#pragma config WDTPS = PS32768          // Watchdog Timer Postscaler (1:32,768)
#pragma config FWPSA = PR128            // WDT Prescaler (Prescaler ratio of 1:128)
#pragma config WINDIS = OFF             // Watchdog Timer Window (Standard Watchdog Timer enabled,(Windowed-mode is disabled))
#pragma config FWDTEN = ON              // Watchdog Timer Enable (Watchdog Timer is enabled)
#pragma config ICS = PGx1               // Comm Channel Select (Emulator functions are shared with PGEC1/PGED1)
#pragma config GWRP = OFF               // General Code Segment Write Protect (Writes to program memory are allowed)
#pragma config GCP = OFF                // General Code Segment Code Protect (Code protection is disabled)
#pragma config JTAGEN = ON              // JTAG Port Enable (JTAG port is enabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

/*
 * 
 */

//void DelayTimer1Init(void) { // Set up timer 1 for microsecond delay function
//    T1CON = 0x0000; // Timer off, 16-bit, 1:1 prescale, gating off
//}
//void UsDelay(unsigned int udelay) {
//    TMR1 = 0;
//    PR1 = udelay * 15; // Number of ticks per microsecond
//    IFS0bits.T1IF = 0; // Reset interrupt flag
//    T1CONbits.TON = 1;
//    while (!IFS0bits.T1IF); // Wait here for timeout
//    T1CONbits.TON = 0;
//}
int main(int argc, char** argv) {
    AD1PCFG = 0xFFFF; // Turn off analogue functions on all pins
//    TRISB.TRISB = 0x0000;
//    TRISC.TRISC = 0x0000;
//    TRISD.TRISD = 0x0000;
//    TRISE.TRISE = 0x0000;
//    TRISF.TRISF = 0x0000;
//    TRISG.TRISG = 0x0000;
//    
    TRISBbits.TRISB8 = 0; // output
    TRISDbits.TRISD1 = 0; // output
//    LATBbits.LATB9 = 0;
    
    // LD1 21 RB8/CN26/RP8/AN8

    //Loop forever and do nothing
    // RD1 is mosi
    LATDbits.LATD1 = 1;

    while(1)
    {
//        LATBbits.LATB9 = 0;
        LATDbits.LATD1 = 0;
        __delay_ms(1);
        LATDbits.LATD1 = 1;
        __delay_ms(1);


    }


    return (EXIT_SUCCESS);
}
