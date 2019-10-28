// Description:     Uses a timer 0 (or 1) to debounce states
//                  (state machine with debounce states will be written in main?)
//----------------------------------------------------------------------//

#include "Timer.h"

/* Initialize timer 0, you should not turn the timer on here.
* You will need to use CTC mode */
void initTimer0(){
    TCCR0A &= ~(1 << WGM00); // setting to CTC mode
    TCCR0A |= (1 << WGM01);
    TCCR0B &= ~(1 << WGM02);

    //Sets prescaler to 64
    TCCR0B |= (1 << CS01) | (1 << CS00);

    // setting max value to 250
    OCR0A = 250; //effectively 1ms
}                           

/* This delays the program an amount specified by unsigned int delay.
* Use timer 0. Keep in mind that you need to choose your prescalar wisely
* such that your timer is precise to 1 millisecond and can be used for
* 100-200 milliseconds
*/
void delayMs(unsigned int delay){
    unsigned int delayCnt = 0;

    TCNT0 = 0; // starts timer at 0
    TIFR0 |= (1 << OCF0A); // sets compare flag to start timer

    while (delayCnt < delay) {
        if (TIFR0 & (1 << OCF0A)) { // increment only while the flag is set (timer reached maxval = OCR0A)
            delayCnt++;
            TIFR0 |= (1 << OCF0A); // restart timer. will go to 0 before reaching the if statement above
        }
    }
}
