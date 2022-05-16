#include <stdio.h>
#include <stdlib.h>

#define N 100

typedef struct
{
    int stack[N];
    int top;
}StackType;

typedef struct 
{
    int heap[N];
    int heapSize;
}HeapType;

void initStack(StackType* S)
{
    S->top = -1;
}

void init(HeapType* H)
{
    H->heapSize = 0;
}

int isEmpty(StackType* S)
{
    return S->top == -1;
}

int isFull(StackType* S)
{
    return S->top == N - 1;
}

void push(StackType* S, int e)
{
    if(isFull(S))
        printf("Full\n");
    else
    {
        S->top++;
 
        S->stack[S->top] = e;
    }
}

int pop(StackType* S)
{
    if(isEmpty(S))
    {
        printf("Empty\n");
        return -1;
    }
    int elem = S->stack[S->top];
    S->top--;
    return elem;
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

void binaryExpansion(StackType* S, int i)
{
    while(i >= 2)
    {
        push(S, i%2);
        i %= 2;
    }
    push(S, 1);
}

void findLastNdoe(HeapType*H)
{
    StackType S;
    initStack(&S);

    int value, p = 1;
    binaryExpansion(&S, H->heapSize);

    pop(&S);

    while(!isEmpty(&S))
    {
        int bit = pop(&S);
        printf("%d", bit); //optional

        if(bit == 0)
        {
            p = p*2;
            value = H->heap[p];
        }
        else
        {
            p = p * 2 + 1;
            value = H->heap[p];
        }
    }
    printf("\nLast Node : %d\n", value);
}

void printHeap(HeapType* H)
{
    for(int i = 1; i < H->heapSize; i++)
        printf("(%d) ", H->heap[i]);
    printf("\n");
}

void heapSortV1(HeapType* H)
{
    int n = H->heapSize;
    int A[n];

    for(int i = n-1; i >= 0; i--)
        A[i] = removeItem(H);

    
    for(int i = 0; i < n; i++)
        printf("(%d) ", A[i]);
    printf("\n");

}

void heapSortV2(HeapType* H)
{
    int n = H->heapSize;

    for(int i = 1; i <= n; i++)
    {
        int key = removeItem(H);
        H->heap[H->heapSize + 1] =key; 
    }

    for(int i = 1; i <= n; i++)
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

    findLastNdoe(&H);

    return 0;
}
