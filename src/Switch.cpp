// Description: 1. Uses a switch to turn motors on and off.
//              2. Switch uses an ISR and is set up for debouncing.
//----------------------------------------------------------------------//

#include "Switch.h"
#include <avr/io.h>

/*
 * Initializes pull-up resistor on PB3 and sets it into input mode
 */
void initSwitchPD0(){
    DDRD &= ~(1 << DDD0); // Set data direction for read / input
    PORTD |= (1 << PORTD0); // setting internal pull-up resistor

    // Setting INT0 Interrupt
    EIMSK &= ~(1 << INT0);
    EICRA |= (1 << ISC00) | (1 << ISC01);
    EIMSK |= (1 << INT0);




    // Setting up Pin change ISRs for pin PD0
    //PCICR |= (1 << PCIE0); // enable "general" PCINT for 7-0. 
    //PCMSK0 |= (1 << PCINT3); // enable local PCINT for PCINT3
}