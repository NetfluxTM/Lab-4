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
#include <Arduino.h>

/*
 *  Define a set of states that can be used in the state machine using a 
 */
typedef enum state_t {
  motor_on,
  motor_off
} state_t;

// Initialize states
volatile state_t state = motor_on;

int main(){
Serial.begin(9600);

sei();
initTimer1();
initPWM();
initSwitchPB3();
InitializeADC();

/* Implement a state machine in the while loop which achieves
 * the assignment requirements.
 */
  while(1){
    switch(state){
      case motor_on:
      break;

      case motor_off:
      break;
    }
  }
}

/* ISR for Switch Press
 * Debounce and toggle motors on/off
 */
ISR(PCINT0_vect){
  if(state == motor_off)
  {
    delayUs(2000);
    state = motor_on;
  }
  else if(state == motor_on)
  {
    delayUs(2000);
    state = motor_off;
  }
}

/* ISR for ADC Conversion Complete
 * Means we can now read from the ADC Data Registers
 */
ISR(ADC_vect){
  if(state == motor_on)
  {
  changeDutyCycle(true);
  }
  else if(state == motor_off)
  {
    changeDutyCycle(false);
  }
}