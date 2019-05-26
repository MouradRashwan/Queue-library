#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

typedef struct Queue
{
    int32_t i32Head;
    int32_t i32Tail;
    int32_t i32QueueLen;
    int32_t i32ActualLen;
    int32_t i32ElementSize;
    int32_t i32Next;
    bool bHeadingToTail;
    void *pvArray;
} Queue_t;

void Queue_allocateStatic(Queue_t *ptQueue, void *pvQueueArray, int32_t i32QueueLen, int32_t i32ElementSize);

bool Queue_allocateDynamic(Queue_t *ptQueue, int32_t i32QueueLen, int32_t i32ElementSize);

bool Queue_reallocateDynamic(Queue_t *ptQueue, int32_t i32NewQueueLen);

void Queue_deallocateDynamic(Queue_t *ptQueue);

bool Queue_isEmpty(Queue_t *ptQueue);

bool Queue_isFull(Queue_t *ptQueue);

int32_t Queue_getActualLen(Queue_t *ptQueue);

int32_t Queue_getQueueLen(Queue_t *ptQueue);

bool Queue_getHead(Queue_t *ptQueue, void *pvElement);

bool Queue_getTail(Queue_t *ptQueue, void *pvElement);

bool Queue_getNext(Queue_t *ptQueue, void *pvElement);

bool Queue_dequeue(Queue_t *ptQueue, void *pvElement);

bool Queue_enqueue(Queue_t *ptQueue, void *pvElement);

#endif // QUEUE_H_INCLUDED
