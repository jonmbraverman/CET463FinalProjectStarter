// // module1.c 
#include "msp430.h"
#include "..\..\MODULES\ring_buffer8.h"
#include "module1.h"

RingBuffer8b_TypeDef module1_output_data;

unsigned int module1SupportFunction(unsigned int);

void module1EventHandler( unsigned char module1param )
{ 
  static unsigned int data1;
  
  unsigned int inputdata = 0;  // Assume this data actually comes from a ring buffer
  
  data1 = module1SupportFunction(inputdata);
  
}


unsigned int module1SupportFunction(unsigned int input)
{
  return input * 2;
}