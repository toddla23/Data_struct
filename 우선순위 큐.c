#include <stdio.h>
#include <stdlib.h>

#define N 100

typedef struct 
{
    int heap[N];
    int heapSize;
}HeapType;

void init(HeapType* H)
{
    H->heapSize = 0;
}

void upHeap(HeapType* H)
{
    int i = H->heapSize;
    int key = H->heap[i];
    while((i != 1) && (key > H->heap[i/2]))
    {
        H->heap[i] = H->heap[i/2];
        i /= 2;
    }
    H->heap[i] = key;
}

void insertItem(HeapType* H, int key)
{
    H->heapSize++;
    H->heap[H->heapSize] = key;
    upHeap(H);
}

void downHeap(HeapType* H)
{
    int item = H->heap[1];
    int parent = 1, child = 2;

    while(child <= H->heapSize)
    {
        if((child < H->heapSize) && (H->heap[child + 1] > H->heap[child]))
            child++;
        
        if(item >= H->heap[child])
            break;

        H->heap[parent] = H->heap[child];
        parent = child;
        child *= 2;
    }

    H->heap[parent] = item;



}

int removeItem(HeapType* H)
{
    int item = H->heap[1];
    H->heap[1] = H->heap[H->heapSize];
    H->heapSize--;

    downHeap(H);
    return item;
}

void printHeap(HeapType* H)
{
    for(int i = 1; i < H->heapSize; i++)
        printf("(%d) ", H->heap[i]);
    printf("\n");
}

int main(void)
{
    HeapType H;
    init(&H);

    insertItem(&H, 9); insertItem(&H, 7); insertItem(&H, 6);
    insertItem(&H, 5); insertItem(&H, 4); insertItem(&H, 3);
    insertItem(&H, 2); insertItem(&H, 2); insertItem(&H, 1);
    insertItem(&H, 3); printHeap(&H); getchar();

    //insertItem(&H, 8); printHeap(&H);
    removeItem(&H); printHeap(&H);

    return 0;
}