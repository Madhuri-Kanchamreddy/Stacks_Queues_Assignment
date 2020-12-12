#include <stdint.h>
#include <string.h>
#include <assert.h>
#include "stack.h"
#include "appconst.h"

Stack stack_new(uint32_t size){
    Stack s1 = {size, -1, {0}};
    return s1;
}

uint8_t stack_full(const Stack *stk){
    assert(stk != NULL);
    return ((stk->top + 1) == stk->size);
}

uint8_t stack_empty(const Stack *stk){
    assert(stk != NULL);
    return stk->top == -1;
}

Stack* stack_push(Stack *stk, int32_t ele, StackResult *res){
    assert(stk != NULL);
    if (stk->top + 1 < stk->size) {
        stk->data[++stk->top] = ele;
        res->data = ele;
        res->status = STACK_OK;
    } else {
        res->data = ele;
        res->status = STACK_FULL;
    }
    return stk;
}

Stack* stack_pop(Stack *stk, StackResult *res){
    if(stk->top == -1)
        res->status = STACK_EMPTY;
    else{
        res->data = stk->data[stk->top];
        --stk->top;
        res->status = STACK_OK;
    }
    return stk;
}

Stack* balance_symbols(Stack *stk, char sym[]){
    int32_t i, length, ch;
    StackResult sr = {0, STACK_EMPTY};
    StackResult *res = &sr;
    length = strlen(sym);
    stk->size = length;
    for(i = 0; i < length; i++){
        if((sym[i] == '{') || (sym[i] == '[') || (sym[i] == '(')){
            ch = sym[i];
            stk = stack_push(stk, ch, res);
        }
        else if((sym[i] == '}') || (sym[i] == ']') || (sym[i] == ')'))
            stk = stack_pop(stk, res);
        else
            return stk;
    }
    return stk;
}

Stack* postfix_evaluation(Stack *stk, char exp[]){
    int32_t i, length, ch, ele1, ele2;
    StackResult sr = {0, STACK_EMPTY};
    StackResult *res = &sr;
    length = strlen(exp);
    stk->size = length;
    for(i = 0; i<length; i++){
        if(exp[i] >= '0' && exp[i] <= '9'){
            ch = exp[i] - '0';
            stk = stack_push(stk, ch, res);
        }
        else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'){
            stk = stack_pop(stk, res);
            ele1 = res->data;
            stk = stack_pop(stk, res);
            ele2 = res->data;
            if(exp[i] == '+')
                ele1 = ele1 + ele2;
            else if(exp[i] == '-')
                ele1 = ele1 - ele2;
            else if(exp[i] == '*')
                ele1 = ele1 * ele2;
            else if(exp[i] == '/')
                ele1 = ele1 / ele2;
            stk = stack_push(stk, ele1, res);
        }
        else
            return stk;
    }
    return stk;
}
