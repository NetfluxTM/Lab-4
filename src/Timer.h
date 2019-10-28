// Description:     Uses a timer (0 or 1) to debounce states
//----------------------------------------------------------------------//

#ifndef TIMER_H
#define TIMER_H

#include <avr/io.h>

void initTimer0();
void delayMs(unsigned int delay);
// Or should we use delayUs?

#endif