/* Description: 1. Uses 2 PWMS on timer 3 and timer 4.
 *              2. Has a changeDutyCycle function.
 * 
 * call the initTimer3 and initTimer4 function from Timer.h?
 * or make those functions in this file?
 * ----------------------------------------------------------------------
 */

#include "PWM.h"
#include <avr/io.h>
#include <Arduino.h>


/*  Initialize Timer3 for PWM
 *  Fast PWM 10-bit mode, non-inverting
 */
void initPWMTimer3(){
    // what pin is this going to come from?
    //pin 2 - OC3B
    //DDRE |= (1 << DDE4);
    //pin 3 - OC3C
    //DDRE |= (1 << DDE5);
    //pin 5 - OC3A
    DDRE |= (1 << DDE3);

    // Configuring the output compare module:
    // From Table 17-2
    // set mode 7 (Fast PWM, 10-bit)
    // TOP = 0x03FF
    TCCR3A |= (1 << WGM31) | (1 << WGM30);
    TCCR3B |= (1 << WGM32);
    // From Table 17-4
    // set non-inverting mode
    TCCR3A |= (1 << COM3A1); //could be added to line 28 for cleaner/faster code, but left separate for readability
    // From Table 17-6
    // set prescaler to 1
    TCCR3B |= (1 << CS30); //left separate for readability
}

/*  Initialize Timer4 for PWM
 *  Fast PWM 10-bit mode, non-inverting
 */
void initPWMTimer4(){
    // what pin is this going to come from?
    //pin 6 - OC4A
    DDRH |= (1 << DDH3);
    //pin 7 - OC4B
    //DDRH |= (1 << DDH4);
    //pin 8 - OC4C
    //DDRH |= (1 << DDH5);

    // Configuring the output compare module:
    // From Table 17-2
    // set mode 7 (Fast PWM, 10-bit)
    // TOP = 0x03FF
    TCCR4A |= (1 << WGM41) | (1 << WGM40);
    TCCR4B |= (1 << WGM42);
    // From Table 17-4
    // set non-inverting mode
    TCCR4A |= (1 << COM4A1); //could be added to line 28 for cleaner/faster code, but left separate for readability

    // From Table 17-6
    // set prescaler to 1
    TCCR4B |= (1 << CS40); // left separate for readability
}

void initPWM(){
    initPWMTimer3();
    initPWMTimer4();

    // Set a pin to output for the L293D Enable pins
    // (they can share one pin from the arduino)
    // pin 8 (PH5)
    DDRH |= (1 << DDH5);
    PORTH |= (1 << PORTH5);
}


/*  Set the duty cycle with OCRnx
 *
 * What parameters need to be passed in?
 * What needs to be returned from the function, if anything?
 * Recieves the digital signal from the ADC, controls the duty cycle of both PWM signals
 * 
 * change OCR3A and OCR4A, assuming we're using those pins
 */
void changeDutyCycle(bool motor) {
    if(motor == false)
    {
        OCR3A = 0;
        OCR4A = 0;
    }
    else
    {
    unsigned int adcVal = ADCL;
    adcVal += ((unsigned int) ADCH << 8);

    //Serial.println(adcVal);


    if(adcVal <= 480) {
        OCR3A = 1023;
        OCR4A = adcVal*2;
    }
    else { // adcVal > 480
        OCR3A = ((adcVal*-2) + 2046);
        OCR4A = 1023;
    }
    }
}