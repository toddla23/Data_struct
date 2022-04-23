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

void insertFirst(ListType* L, char e)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = e;
    node->next = L->H;
    L->H = node;
}

void insertLast(ListType* L, char e)
{
    ListNode* p = L->H;
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->next = NULL;

    node->data = e;
    if(p == NULL)
    {
        L->H = node;
    }
    else
    {
        while(p->next != NULL)
            p = p->next;
        p->next = node;
    }
}

void insert(ListType* L, int pos, char e)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    ListNode* p = L->H;

    if(pos == 1)
        insertFirst(L, e);
    else
    {    
        for(int i = 1; i < pos - 1; i++)
            p = p->next;
        
        node->next = p->next;
        p->next = node;
        node->data = e;
    }
}

char deleteFirst(ListType* L)
{
    ListNode* node = L->H;
    char e = node->data;
    L->H = node->next;
    free(node);

    return e;
}

char deleteLast(ListType* L)
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

char delete(ListType* L, int pos)
{
    ListNode* p = L->H;
    ListNode* q;

    if(pos == 1)
        return deleteFirst(L);
    else
    {
    for(int i = 1; i < pos - 1; i++)
        {
            q = p;
            p = p->next;
        }

        char e = p->data;
        q->next = p->next;
        free(p);

        return e;
    }
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
    ListType L;
    init(&L);

    insertLast(&L, 'E'); print(&L);
    insertFirst(&L, 'A'); print(&L);
    insertFirst(&L, 'B'); print(&L);
    getchar();
    
    insertLast(&L, 'D'); print(&L);
    insertFirst(&L, 'C'); print(&L);
    getchar();

    insert(&L, 1, 'F'); print(&L);
    insert(&L, 3, 'G'); print(&L);
    insert(&L, 5, 'H'); print(&L);
    getchar();

    printf("%c\n", deleteFirst(&L));    print(&L);
    printf("%c\n", deleteLast(&L));    print(&L);
    getchar();

    printf("%c\n", delete(&L,3));    print(&L);
    printf("%c\n", delete(&L,1));    print(&L);
    getchar();


    return 0;
}