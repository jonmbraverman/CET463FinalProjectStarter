// capture.c 
#include "msp430.h"
#include "ring_buffer16.h"

RingBuffer16b_TypeDef capture_data_rb;   

#pragma vector=TIMER1_A0_VECTOR
__interrupt void TIMER1_A1_CCR0_ISR(void)
{
static unsigned int lastTA1R = 0;
unsigned int duration;

  duration = TA1CCR0 - lastTA1R;
  lastTA1R = TA1CCR0;
  
  if((TA1CCTL0 & COV) == FALSE)
    ringbuffer16b_enqueue(&capture_data_rb, duration);
  else
    TA1CCTL0 &= ~COV;
}

  

void CAPTURE_TESTER(void)
{
  P2OUT = P2OUT + 1;
}






















