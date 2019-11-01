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
typedef enum state_t {
  initialize,
  wait,
  update_pwm,
  debounce_pause,
  pause,
  debounce_resume
} state_t;

// Initialize states
volatile state_t state = initialize;

//volatile int delay = 100;
//volatile int release_flag = 0;

int main(){

/* Implement a state machine in the while loop which achieves
 * the assignment requirements.
 */
  while(1){
    switch(state){
      case initialize:
        sei();
        initTimer1();
        initPWM();
        initSwitchPB3();
        InitializeADC();
        state = wait;
      break;

      case wait:
      break;

      case update_pwm:
        state = wait;
        changeDutyCycle(); //read from ADC reg to update duty cycle
      break;

      case debounce_pause:
        PORTB &= ~(1 << PORTB1);
        delayUs(100);
        state = pause;
      break;

      case pause:
      break;

      case debounce_resume:
        PORTB |= (1 << PORTB1);
        delayUs(100);
        state = wait;
      break;
    }
  }
}

/* ISR for Switch Press
 * Debounce and toggle motors on/off
 */
ISR(PCINT0_vect){
  if((state == wait) | (state == update_pwm)) state = debounce_pause;
  else if(state == pause) state = debounce_resume;
}

/* ISR for ADC Conversion Complete
 * Means we can now read from the ADC Data Registers
 */
ISR(ADC_vect){
  if((state == wait) | (state == debounce_resume)) state = update_pwm;
}