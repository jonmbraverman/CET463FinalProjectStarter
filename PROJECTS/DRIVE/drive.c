// // drive.c 
#include "msp430.h"
#include "..\..\MODULES\ring_buffer8.h"
#include "drive.h"

RingBuffer8b_TypeDef drive_cmd_data;


unsigned int driveSupportFunction(unsigned int);

void driveStateMachine( unsigned char module1param )
{ 
  static unsigned int data1;
  static unsigned char state = 0;
  unsigned int inputdata = 0;  // Assume this data actually comes from a ring buffer
  static unsigned char inputcommand;
  bool new_command = FALSE;
  
  


  switch(state)
  {
  case 0:         // WAIT For COMMAND
    if(ringbuffer8b_isempty(&drive_cmd_data) == FALSE)
    {
      inputcommand = ringbuffer8b_dequeue(&drive_cmd_data);
      new_command = TRUE;
    }

    if(new_command == TRUE)                 // If a new command has been received
    {
      if(driveCommandValid(inputcommand))   // AND it is valid
        state = 1;                          // GO TO state 1 to process it 
        
    }    
    break;
  case 1:
    switch(inputcommand)
    {
      case 0:                               // command to drive forward received
                                            // GO TO state x to wait for number of feed in ring buffer
        break;

      default:
       state = 0;                           // invalid command received
    }
    break;
  }
      
    

  
  
  
}


bool driveCommandValid(unsigned char input)
{
  return TRUE;
}