#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct DListNode
{
    char data;
    struct DListNode* prev, * next;

}DListNode;

void init(DListNode* H, DListNode* T)
{
    H->next = T;
    T->prev = H;
}

void insert(DListNode* H, int pos, char e)
{
    DListNode *p = H;
    
    for(int i = 1; i < pos; i++)
        p = p->next;

    DListNode* node = (DListNode*)malloc(sizeof(DListNode));
    node->data = e;
    node->prev = p;
    node->next = p->next;
    
    p->next->prev = node; //여기부분 어려움!!!! 야발
    p->next = node;

    
}

char delete(DListNode* H, int pos)
{
    DListNode* p = H;

    for(int i = 0; i < pos; i++)
        p = p->next;
    
    char e = p->data;
    p->prev->next = p->next;
    p->next->prev = p->prev;

    free(p);
    return e;
}

void print(DListNode* H, DListNode* T)
{
    for(DListNode* p = H->next; p != T; p = p->next)
        printf("%c <=> ", p->data);
    printf("\b\b\b\b    \n");
}

int main(void)
{
    DListNode* H = (DListNode*)malloc(sizeof(DListNode));
    DListNode* T = (DListNode*)malloc(sizeof(DListNode));

    init(H, T);

    insert(H, 1, 'A');  print(H, T);
    insert(H, 1, 'B');  print(H, T);
    insert(H, 2, 'C');  print(H, T);
    insert(H, 4, 'D');  print(H, T);
    insert(H, 3, 'E');  print(H, T);
    getchar();

    printf("Delete node number : ");
    int pos;
    scanf("%d", &pos);
    printf("%c is deleted. \n", delete(H, pos));
    print(H, T);
    return 0;
}