// Description: 1. Uses 2 PWMS on timer 3 and timer 4.
//              2. Has a changeDutyCycle function.
//----------------------------------------------------------------------//

#ifndef PWM_H
#define PWM_H

#include <avr/io.h>

// Initialize Timer 3 for PWM
void initPWMTimer3();

// Initialize Timer 4 for PWM
void initPWMTimer4();


/* What parameters need to be passed in?
 * What needs to be returned from the function, if anything?
 * Recieves the digital signal from the ADC, controls the duty cycle of both PWM signals
 * 
 * change OCR3A and OCR4A, assuming we're using those pins
 */
void changeDutyCycle();


#endif