// TESTS.C
#include "..\..\MODULES\ring_buffer8.h"
#include "..\..\MODULES\serial.h"
#include "module1.h"
#include "communicator.h"


void testeventdata(void)
{
 static unsigned char tedata = MODULE1_EVENT_BUTTONPRESS;
 
 ringbuffer8b_enqueue(&module1_event_data, tedata);
 tedata ^= 1;
 
}

void testserialdata(void)
{
   static unsigned char tsdata = 0;
   
   ringbuffer8b_enqueue(&rx_data_rb, tsdata++);
}
