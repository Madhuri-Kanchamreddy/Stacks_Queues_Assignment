#include "appconst.h"
#include <stdint.h>
#ifndef STACK_AND_QUEUE_H_INCLUDED
#define STACK_AND_QUEUE_H_INCLUDED

typedef struct _stacks_ S;

struct _stacks_{
    int32_t arr[MAXSIZE];
    int32_t size;
    int32_t top;
};

typedef struct _queues_ Queue;

struct _queues_{
    int32_t arr[MAXSIZE];
    int32_t front;
    int32_t rear;
    int32_t count;
    int32_t size;
};

Queue new_queue(int32_t size);
S new_stack(int32_t size);
S* push(S *stk, int32_t ele);
Queue* enqueue(Queue *q, int32_t ele);
int32_t dequeue(Queue *q);
int32_t stack_lookup(S *stk, Queue *q, int32_t ele);

#endif // STACK_AND_QUEUE_H_INCLUDED
