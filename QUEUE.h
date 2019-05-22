#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

typedef struct Queue
{
    int32_t i32Head;
    int32_t i32Tail;
    int32_t i32QueueLen;
    int32_t i32CurrentLen;
    int32_t i32ElementSize;
    int32_t i32Next;
    bool bHeadingToTail;
    void *pvArray;
} Queue_t;

void QUEUE_allocateStatic(Queue_t *ptQueue, void *pvQueueArray, int32_t i32QueueLen, int32_t i32ElementSize);

bool QUEUE_allocateDynamic(Queue_t *ptQueue, int32_t i32QueueLen, int32_t i32ElementSize);

void QUEUE_deallocateDynamic(Queue_t *ptQueue);

bool QUEUE_isEmpty(Queue_t *ptQueue);

bool QUEUE_isFull(Queue_t *ptQueue);

int32_t QUEUE_getCurrentLength(Queue_t *ptQueue);

int32_t QUEUE_getQueueLength(Queue_t *ptQueue);

bool QUEUE_getHead(Queue_t *ptQueue, void *pvElement);

bool QUEUE_getTail(Queue_t *ptQueue, void *pvElement);

bool QUEUE_getNext(Queue_t *ptQueue, void *pvElement);

bool QUEUE_dequeue(Queue_t *ptQueue, void *pvElement);

bool QUEUE_enqueue(Queue_t *ptQueue, void *pvElement);

#endif // QUEUE_H_INCLUDED
