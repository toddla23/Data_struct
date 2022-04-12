#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct 
{
    int data[N];
    int size;
}ListType;

void init( ListType* L)
{
    L->size = 0;
}

int isEmpty(ListType* L)
{
    return L->size == 0;
}

int isFull(ListType* L)
{
    return L->size == N;
}

void insertLast(ListType* L, int elem)
{
    if(isFull(L))
    {
        printf("Full!!\n");
        return;
    }
    L->data[L->size] = elem;
    L->size++;
}

void insert(ListType* L, int pos, int elem)
{
    if(isFull(L))
    {
        printf("Full!!\n");
        return;
    }
    
    for(int i = L->size-1; i >= pos; i--)
        L->data[i+1] = L->data[i];

    L->data[pos] = elem;
    L->size++;
}

int deleteLast(ListType* L)
{
    if(isEmpty(L))
    {
        printf("Empty!!!!\n");
        return -1;
    }

    int elem = L->data[L->size - 1];
    L->size--;

    return elem;
}

int delete(ListType* L, int pos)
{
    if(isEmpty(L))
    {
        printf("Empty!!!!\n");
        return -1;
    }

    int elem = L->data[pos];

    for(int i = pos; i <L->size - 1; i ++)
        L->data[i] = L->data[i + 1];
    
    L->size--;

    return elem;
}

void print(ListType* L)
{
    for(int i = 0; i < L->size; i++)
        printf("%d ->", L->data[i]);

    printf("\b\b\b   \n");
}

int main(void)
{
    ListType L;
    init(&L);

    insertLast(&L, 10); print(&L);
    insertLast(&L, 20); print(&L);
    insertLast(&L, 30); print(&L);
    getchar();

    insert(&L, 1, 40); print(&L);
    insert(&L, 0, 50); print(&L);
    insert(&L, 3, 60); print(&L);
    getchar();

    printf("[%d] is deleted. \n", deleteLast(&L)); print(&L);
    printf("[%d] is deleted. \n", delete(&L, 1)); print(&L);


    return 0;
}