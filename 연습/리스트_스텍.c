#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct ListNode
{
    char data;
    struct ListNode* next;
    
}ListNode;

typedef struct ListType
{
    ListNode* H;
}ListType;

void init(ListType* L)
{
    L->H = NULL;
}

void push(ListType* L, char e)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = e;
    node->next = L->H;
    L->H = node;
}

char pop(ListType* DL)
{
    ListNode* p = DL->H;
    DL->H = p->next;
    char e = p->data;

    free(p);

    return e;
}

char peek(ListType* DL)
{
    return DL->H->data;
}

void print(ListType* L)
{
    ListNode* p;
    for(p = L->H; p != NULL; p = p->next)
        printf("[%c] ->", p->data);
    printf("\b\b\b   \n");
}

int main(void)
{

    ListType DL;
    init(&DL);

    push(&DL, 'A'); print(&DL);
    push(&DL, 'B'); print(&DL);
    push(&DL, 'C'); print(&DL);
    push(&DL, 'D'); print(&DL);
    push(&DL, 'E'); print(&DL);
    push(&DL, 'F'); print(&DL);
    getchar();

    printf("%c \n", pop(&DL));    print(&DL);
    printf("%c \n", pop(&DL));    print(&DL);
    getchar();

    printf("%c \n", peek(&DL));    print(&DL);
    printf("%c \n", peek(&DL));    print(&DL);


    return 0;
}