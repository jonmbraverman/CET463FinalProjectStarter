#ifndef RING_BUFFER8_H
#define RING_BUFFER8_H

#define RINGBUFFERSIZE 16
//
//
/* other */


typedef struct
{
  unsigned char head;
  unsigned char tail;
  unsigned char array[RINGBUFFERSIZE];

} RingBuffer8b_TypeDef;




typedef enum {FALSE = 0, TRUE = 1} bool;

bool ringbuffer8b_isfull(RingBuffer8b_TypeDef *rb);
bool ringbuffer8b_isempty(RingBuffer8b_TypeDef *rb);
unsigned char ringbuffer8b_dequeue(RingBuffer8b_TypeDef *rb);
bool ringbuffer8b_enqueue(RingBuffer8b_TypeDef *rb, unsigned char bytedata);
void ringbuffer8b_flush1(RingBuffer8b_TypeDef *rb);



#endif