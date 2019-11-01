/* Description: 1. A function exists to initialize the ADC.
 *              2. Uses the A0 pin as an input.
 *
 * When setting pin A0 to input, do we need to update PORTF, for the pullup resistor?
 * ie) PORTA |= (1 << PORTA0);
 *----------------------------------------------------------------------//
 */

#include "ADC.h"
// not necessary?
//#include <avr/io.h>

/* Initializes pins A0 as input.
 * Recieves analog voltage from potentiometer, converts to digital signal.
 */
void InitializeADC() {
    //Set pin A0 on the Arduino board as an input for the potentiometer voltage
    DDRF &= ~(1 << DDF0);
 
    //Set the reference voltage to use the Vcc (+5V) on the Arduino board
    ADMUX |= (1 << REFS0);
    ADMUX &= ~(1 << REFS1);
 
    //Set bit 5 in ADMUX to zero so that the adc result will be right justified in the ADC register
    ADMUX &= ~(1 << ADLAR);
 
    //Set the channel to ADC0, which corresponds to pin A0 on the board
    ADMUX &= ~((1 << MUX4) | (1 << MUX3) | (1 << MUX2) | (1 << MUX1) | (1 << MUX0));
    ADCSRB &= ~(1 << MUX5);
 
    //Set the prescaler to 2
    ADCSRA &= ~((1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0));
 
// Set ADATE to enable ADC Auto-trigger
ADCSRA |= (1 << ADATE);

    //Set the ADC to free running mode
    ADCSRB &= ~((1 << ADTS2) | (1 << ADTS1) | (1 << ADTS0));

// Set ADIE to enable ADC Interrupt
ADCSRA |= (1 << ADIE);

    //Disable the digital input for pin A0 on the board
    DIDR0 |= (1 << ADC0D);
 
    //Enable the ADC
    ADCSRA |= (1 << ADEN);
 
    //Start the first conversion
    ADCSRA |= (1 << ADSC);
}

