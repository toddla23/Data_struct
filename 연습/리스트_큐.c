#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct ListNode
{
    char data;
    struct ListNode* next;
}ListNode;

typedef struct
{
    ListNode* H;
}ListType;

void init(ListType* L)
{
    L->H = NULL;
}

void enqueue(ListType* L, char e)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = e;

    node->next = L->H;
    L->H = node;
}

char dequeue(ListType* L)
{
    ListNode* p = L->H;
    ListNode* q;
    while(p->next != NULL)
    {
        q = p;
        p = p->next;
    }

    char e = p->data;
    q->next = NULL;
    free(p);
    
    return e;
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

    enqueue(&DL, 'A'); print(&DL);
    enqueue(&DL, 'B'); print(&DL);
    enqueue(&DL, 'C'); print(&DL);
    enqueue(&DL, 'D'); print(&DL);
    enqueue(&DL, 'E'); print(&DL);
    enqueue(&DL, 'F'); print(&DL);
    getchar();

    printf("%c \n", dequeue(&DL));    print(&DL);
    printf("%c \n", dequeue(&DL));    print(&DL);
    getchar();






    return 0;
}