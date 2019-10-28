// Description: 1. Uses 2 PWMS on timer 3 and timer 4.
//              2. Has a changeDutyCycle function.
//----------------------------------------------------------------------//

#ifndef PWM_H
#define PWM_H

#include <avr/io.h>


/* What parameters need to be passed in?
 * What needs to be returned from the function, if anything?
 * Recieves the digital signal from the ADC, controls the duty cycle of both PWM signals
 * Uses timer 3 and timer 4
 */
void changeDutyCycle();


#endif