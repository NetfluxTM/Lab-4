// Description:     Uses a timer 0 (or 1) to debounce states
//                  (state machine with debounce states will be written in main)
//----------------------------------------------------------------------//

#include "Timer.h"

/* Initialize timer 1, you should not turn the timer on here. Use CTC mode  .*/
void initTimer1(){
  
  // setting timer1 to CTC mode
  TCCR1A &= ~(1 << WGM10);
  TCCR1A &= ~(1 << WGM11);
  TCCR1B |= (1 << WGM12);
  TCCR1B &= ~(1 << WGM13);

  // setting the clock prescaler to 8
  TCCR1B &= ~((1 << CS12) | (1 << CS10));
  TCCR1B |= (1 << CS11);

  // setting OCR1A to 2 
  // gives us a 1us timer
  OCR1AH = 0x00;
  OCR1AL = 0x02;
}

/* This delays the program an amount specified by unsigned int delay.
 * if delay = 100, that's 100us
 */
void delayUs(unsigned int delay){ 
  unsigned int count = 0;

  // setting counter to 0
  TIFR1 |= (1 << OCF1A);
  TCNT1 = 0;

  while (count < delay){
      if ((TIFR1 & (1 << OCF1A))){ //increment count for each flag raised. flag represents 1us.
          count++;
          TIFR1 |= (1 << OCF1A); // reset timer to start counting again
      }
  }
}