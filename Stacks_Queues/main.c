#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "stacks.c"
#include "appconst.h"
#include "stack_using_queue.h"
#include "stack_using_queue.c"
#include "stack_and_queue.h"
#include "stack_and_queue.c"
#include <assert.h>

void create_stack(){
    Stack s1 = stack_new(MAXSIZE);
    Stack *stk = &s1;
    assert(stk!=NULL);
}
void test_check_symbols(){
    Stack s1 = stack_new(MAXSIZE);
    Stack *stk = &s1;
    char symbols[] = "{[]{}(})";
    stk = balance_symbols(stk, symbols);
    assert(stk->top == -1);
}

void test_postfix(){
    Stack s1 = stack_new(MAXSIZE);
    Stack *stk = &s1;
    char exp[] = "6523+8*+3+*";
    stk = postfix_evaluation(stk, exp);
    printf("%d\n", stk->data[stk->top]);
}

void test_stack_using_queue(){
    Q q1 = queue_new(10);
    Q *q = &q1;
    QueueResult res1 = {0, QUEUE_EMPTY};
    QueueResult *res = &res1;
    assert((queue_empty(q, res)) == 1);
    q = stk_push(q, 10, res);
    q = stk_push(q, 20, res);
    q = stk_push(q, 30, res);
    q = stk_push(q, 40, res);
    q = stk_push(q, 50, res);
    assert(q->count == 5);
    q = stk_pop(q, res);
    assert(q->count == 4);
}

void test_stack_lookup(){
    S s1 = new_stack(MAXSIZE);
    S *stk = &s1;
    Queue q1 = new_queue(MAXSIZE);
    Queue *q = &q1;
    stk = push(stk, 10);
    stk = push(stk, 20);
    stk = push(stk, 30);
    stk = push(stk, 40);
    assert(stack_lookup(stk, q, 40) == 1);
}

int main()
{
    create_stack();
    test_check_symbols();
    test_postfix();
    test_stack_using_queue();
    test_stack_lookup();
    return 0;
}
