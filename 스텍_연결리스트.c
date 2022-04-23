#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct DListNode
{
    char data;
    struct DListNode* prev, * next;

}DListNode;

typedef struct
{
    DListNode* H;
}DlistType;

void init(DlistType* DL)
{
    DL->H = NULL;
}

void insertFirst(DlistType* DL, char e)
{
    DListNode* node = (DListNode*)malloc(sizeof(DListNode));
    DListNode* p = DL->H;
    
    node->data = e;
    node->prev = NULL;
    node->next = p;
    DL->H = node;

    if(p != NULL)
        p->prev = node;
}

void insert(DlistType* DL, int pos, char e)
{

    DListNode* node = (DListNode*)malloc(sizeof(DListNode));
    DListNode *p = DL->H;

    if(pos == 1)
        insertFirst(DL, e);
    else
    {
        for(int i = 1; i < pos; i++)
            p = p->next;

        node->data = e;
        node->prev = p->prev;
        node->next = p;
        node->prev->next = node;
        p->prev = node;
    }
}



void print(DlistType* DL)
{
    for(DListNode* p = DL->H; p != NULL; p = p->next)
        printf("%c <=> ", p->data);
    printf("\b\b\b\b    \n");
}

int main(void)
{
    DlistType DL;
    init(&DL);

    insertFirst(&DL, 'A'); print(&DL);
    insertFirst(&DL, 'B'); print(&DL);
    insertFirst(&DL, 'C'); print(&DL);
    getchar();

    insert(&DL, 2, )

    return 0;
}