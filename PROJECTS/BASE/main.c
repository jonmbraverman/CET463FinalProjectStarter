/*******************************************************************************
;
;
;       P2      7 6 5 4 3 2 1 0
;               | | | | | | | | 
;               | | | | | | | *-CAPTURE (T1-0A) ****
;               | | | | | | *---GPIO  
;               | | | | | *-----CAPTURE (T1-1B)
;               | | | | *-------GPIO 
;               | | | *---------CAPTURE (T1-2A)
;               | | *-----------GPIO
;               | *-------------XTAL IN
;               *---------------XTAL OUT
;
;
;      P1       7 6 5 4 3 2 1 0
;               | | | | | | | | 
;               | | | | | | | *-GPIO (LED)
;               | | | | | | *---UARTA0 (RX) 
;               | | | | | *-----UARTA0 (TX) 
;               | | | | *-------GPIO (PB) 
;               | | | *---------GPIO
;               | | *-----------GPIO 
;               | *-------------GPIO 
;               *---------------GPIO
****************************************************************************** */
#include <msp430g2553.h>
#include "..\..\MODULES\hal.h"
#include "..\..\MODULES\communicator.h"


void main( void )
{
    // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  BCSCTL1 = CALBC1_8MHZ;                       // Set DCO to 8MHz
  DCOCTL =  CALDCO_8MHZ; 

  configGPIO_UI();
  configGPIO_CAPTURE_TESTER();
  configTIMERA0_10msTick();
  //configTIMERA1_PWM();
  configTIMERA1_CAPTURE();
  configUSCI_A0();
  _BIS_SR(GIE);                 // Enable interrupt
  
  
  while(1)
  {
   
    MessageReceiver();
    
    
  }
}







