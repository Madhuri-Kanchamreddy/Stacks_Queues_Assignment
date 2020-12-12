#include <stdint.h>
#include "appconst.h"
#ifndef STACK_USING_QUEUE_H_INCLUDED
#define STACK_USING_QUEUE_H_INCLUDED

typedef struct _queue_ Q;

struct _queue_{
    int32_t data[MAXSIZE];
    int32_t front;
    int32_t rear;
    int32_t size;
    int32_t count;
};
typedef struct _queueresult_ QueueResult;

struct _queueresult_{
    int32_t data;
    uint32_t status;
};

Q queue_new(uint32_t size);
Q* queue_insert(Q *q, int32_t ele, QueueResult *res);
int32_t queue_remove(Q *q, QueueResult *res);
Q* stk_push(Q *q, int32_t ele, QueueResult *res);
Q* stk_pop(Q *q, QueueResult *res);
#endif // STACK_USING_QUEUE_H_INCLUDED
