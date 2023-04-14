#include <msp430g2553.h>
#include "..\..\MODULES\hal.h"
#include "..\..\MODULES\communicator.h"
#include "module1.h"

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
    module1EventHandler(MODULE1_MODE_NORMAL);
    
  }
}







