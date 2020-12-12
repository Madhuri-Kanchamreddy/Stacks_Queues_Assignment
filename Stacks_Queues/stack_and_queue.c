#include "stack_and_queue.h"
#include <assert.h>
#include <stdint.h>

Queue new_queue(int32_t size){
    Queue q = {{0}, 0, 0, 0, size};
    return q;
}

S new_stack(int32_t size){
    S s1 = {{0}, size, -1};
    return s1;
}
S* push(S *stk, int32_t ele){
    assert(stk != NULL);
    if (stk->top + 1 < stk->size) {
        stk->arr[++stk->top] = ele;
    }
    return stk;
}

Queue* enqueue(Queue *q, int32_t ele){
    if(q->count == q->size - 1){
        return q;
    }
    else{
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = ele;
        q->count++;
    }
    return q;
}

int32_t dequeue(Queue *q){
    assert(q!=NULL);
    int32_t value;
    if(q->count == 0){
        return QUEUE_EMPTY;
    }
    else{
        q->front = (q->front + 1) % q->size;
        value = q->arr[q->front];
        q->count--;
    }
    return value;
}

int32_t stack_lookup(S *stk, Queue *q, int32_t ele){
    int32_t result, val;
    S s1 = new_stack(MAXSIZE);
    S *stk1 = &s1;
    while(stk->top != -1){
        if(stk->arr[stk->top] == ele)
            result = 1;
        q = enqueue(q, stk->arr[stk->top]);
        stk->top--;
    }
    if(result != 1)
        result = 0;
    while(q->count){
        val = dequeue(q);
        stk1->arr[stk1->top] = val;
        stk1->top++;
    }
    while(stk1->top != -1){
        stk->top++;
        stk->arr[stk->top] = stk1->arr[stk1->top];
        stk1->top--;
    }
    return result;
}
