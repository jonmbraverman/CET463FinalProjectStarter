// // drive.h
#ifndef DRIVE_H
#define DRIVE_H

#include "..\..\MODULES\ring_buffer8.h"

// PUBLIC FUNCTION PROTOTYPES
void driveEventHandler( unsigned char );
bool driveCommandValid(unsigned char input);

// PUBLIC GLOBAL/STATIC DATA
extern RingBuffer8b_TypeDef drive_cmd_data;


// PUBLIC DEFINITIONS
#define DRIVE_MODE_NORMAL 0







#endif