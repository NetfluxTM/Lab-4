/* Author:         
 * Net ID:         
 * Date:           
 * Assignment:     Lab 4
 *
 * Description: This file contains a programmatic overall description of the
 * program. It should never contain assignments to special function registers
 * for the exception key one-line code such as checking the state of the pin.
 */

/* Procedure:
 * Include relevant header files
 * Define states for state machine
 * Initialize states
 * 
 * Inside Main:
 * Initialize everything else: pins, timers, sei()
 * Implement state machine
 * 
 * (outside main)
 * Implement ISRs
 * 
 */


//#include <Arduino.h> // not allowed except for debugging
#include <avr/interrupt.h> // for ISR's
#include <avr/io.h>
#include "ADC.h"
#include "PWM.h"
#include "Switch.h"
#include "Timer.h"

/*
 *  Define a set of states that can be used in the state machine using a 
 */

int main(){


  while(1){

  }

  return 0;
}
