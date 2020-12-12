#include <assert.h>
#include <stdint.h>
#include "stack_using_queue.h"
#include "appconst.h"

Q queue_new(uint32_t size){
    Q q = {{0}, 0, 0, size, 0};
    return q;
}

int32_t queue_empty(Q *q, QueueResult *res){
    assert(q!=NULL);
    if(q->count == 0)
        res->status = QUEUE_EMPTY;
    return q->count == 0;
}

Q* queue_insert(Q *q, int32_t ele, QueueResult *res){
    if(q->count == q->size - 1){
        res->status = QUEUE_FULL;
        return q;
    }
    else{
        q->rear = (q->rear + 1) % q->size;
        q->data[q->rear] = ele;
        q->count++;
        res->data = ele;
        res->status = QUEUE_OK;
    }
    return q;
}

int32_t queue_remove(Q *q, QueueResult *res){
    assert(q!=NULL);
    int32_t value;
    if(q->count == 0){
        res->status = QUEUE_EMPTY;
        return QUEUE_EMPTY;
    }
    else{
        q->front = (q->front + 1) % q->size;
        value = q->data[q->front];
        res->data = q->data[q->front];
        q->count--;
        res->status = QUEUE_OK;
    }
    return value;
}

Q* stk_push(Q *q, int32_t ele, QueueResult *res){
    q = queue_insert(q, ele, res);
    return q;
}

Q* stk_pop(Q *q, QueueResult *res){
    int32_t i, val, n = q->count;
    for(i = 0; i < n-1; i++){
        val = queue_remove(q, res);
        q = queue_insert(q, val, res);
    }
    val = queue_remove(q, res);
    return q;
}

/*int32_t stack_lookup(Stack *stk, Queue *q, int32_t ele, QueueResult *qres){
    Stack s1 = stack_new(MAXSIZE);
    Stack *stk1 = &s1;
    while(stk->top != -1){
        if(stk->data[stk->top] == ele)
            result = 1;
        q = queue_insert(q, stk->data[stk->top], qres);
        stk->top--;
    }
    if(result != 1)
        result = 0;
    while(q->count){
        val = q->remove(q, qres);
        stk1->data[stk1->top] = val;
        stk1->top++;
    }
    while(stk1->top != -1){
        stk->top++;
        stk->data[stk->top] = stk1->data[stk1->top];
        stk1->top--;
    }
    return result;
}*/
