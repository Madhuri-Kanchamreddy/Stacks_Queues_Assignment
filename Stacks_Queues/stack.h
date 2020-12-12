#include <stdint.h>
#include "appconst.h"
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef struct _stack_ Stack;

struct _stack_ {
    uint32_t size;
    int32_t top;
    int32_t data[MAXSIZE];
};

typedef struct _stackresult_ StackResult;

struct _stackresult_{
    int32_t data;
    uint8_t status;
};

Stack stack_new(uint32_t size);
uint8_t stack_full(const Stack *stk);
uint8_t stack_empty(const Stack *stk);
Stack* stack_push(Stack *stk, int32_t ele, StackResult *res);
Stack* stack_pop(Stack *stk, StackResult *res);
Stack* balance_symbols(Stack *stk, char sym[]);
#endif // STACK_H_INCLUDED
