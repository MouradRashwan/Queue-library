#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

#include "Queue.h"

#define QUEUE_LENGTH                5
#define QUEUE_STATIC_ALLOCATION     0

typedef struct Object
{
    int32_t i32Val1;
    int32_t i32Val2;
} Object_t;

int main(void)
{
    printf("Queue Starting ...\n");

    int32_t ii;
    Queue_t tQueue;
    Object_t tObject;

#if(QUEUE_STATIC_ALLOCATION == 0)
    if(Queue_allocateDynamic(&tQueue, QUEUE_LENGTH, sizeof(Object_t)) == false)
    {
        printf("<<ERROR>> Heap Memory is Full");
        return 0;
    }
#else
    static Object_t atObject[QUEUE_LENGTH];
    Queue_allocateStatic(&tQueue, atObject, QUEUE_LENGTH, sizeof(Object_t));
#endif

    for(ii=0; ii<QUEUE_LENGTH; ii++)
    {
        tObject.i32Val1 = ii + 1;
        tObject.i32Val2 = (ii + 1) * 10;
        Queue_enqueue(&tQueue, &tObject);
    }

    Queue_dequeue(&tQueue, &tObject);
    tObject.i32Val1 = 6;
    tObject.i32Val2 = 60;
    Queue_enqueue(&tQueue, &tObject);

    Queue_getHead(&tQueue, &tObject);
    printf("(%u|%u) ", tObject.i32Val1, tObject.i32Val2);
    while(Queue_getNext(&tQueue, &tObject))
    {
        printf("(%u|%u) ", tObject.i32Val1, tObject.i32Val2);
    }
    printf("\n\n");

    Queue_getTail(&tQueue, &tObject);
    printf("(%u|%u) ", tObject.i32Val1, tObject.i32Val2);
    while(Queue_getNext(&tQueue, &tObject))
    {
        printf("(%u|%u) ", tObject.i32Val1, tObject.i32Val2);
    }
    printf("\n\n");

#if(QUEUE_STATIC_ALLOCATION == 0)
    Queue_deallocateDynamic(&tQueue);
#endif

    return 0;
}
