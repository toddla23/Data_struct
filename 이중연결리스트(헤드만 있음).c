#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct StackNode
{
    char data;
    struct StackNode* next;

}StackNode;

typedef struct
{
    StackNode* top;
}StackType;

void init(StackType* S)
{
    S->top = NULL;
}

void push(StackType* S, char e)
{
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->data = e;
    node->next = S->top;
    S->top = node;
}

char pop(StackType* S)
{
    StackNode* p = S->top;
    S->top = p->next;

    char e = p->data;
    free(p);
    return e;
}

char peek(StackType* S)
{
    StackNode* p = S->top;

    return p->data;
}

void print(StackType* S)
{
    StackNode* p = S->top;
    for(; p != NULL; p = p->next)
    {
        
    }
}

int main(void)
{

    StackType S;
    init(&S);

    push(&S, 'A');  print(&S);
    push(&S, 'B');  print(&S);
    push(&S, 'C');  print(&S);

    return 0;
} // 마저 구현 해야함