// Description: 1. Uses a switch to turn motors on and off.
//              2. Switch uses an ISR and is set up for debouncing.
//----------------------------------------------------------------------//

#include "Switch.h"
#include <avr/io.h>

/*
 * Initializes pull-up resistor on PB3 and sets it into input mode
 */
void initSwitchPB3(){
    // Setting up Pin change ISRs for pin PB3
    PCICR |= (1 << PCIE0); // enable "general" PCINT for 7-0. 
    PCMSK0 |= (1 << PCINT3); // enable local PCINT for PCINT3

    DDRB &= ~(1 << DDB3); // Set data direction for read / input
    PORTB |= (1 << PORTB3); // setting internal pull-up resistor
   
}