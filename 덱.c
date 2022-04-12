#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

typedef struct
{
    int front, rear;
    char data[SIZE];

}DequeType;

void init(DequeType* D)
{
    D->front = D->rear = 0;
}

int isFull(DequeType* D)
{
    return D->front == D->rear + 1;
}

int isEmpty(DequeType* D)
{
    return D->front == D->rear;
}

void addRear(DequeType* D, char e)
{
    if(isFull(D))
    {
        printf("FULL!!!\n");
        return;
    }

    D->rear = (D->rear + 1 )% SIZE;
    D->data[D->rear] = e;
}

void addFront(DequeType* D, char e)
{
        if(isFull(D))
    {
        printf("FULL!!!\n");
        return;
    }

    D->front = (D->front - 1 )% SIZE;
    D->data[D->front] = e;
}

char delteRear(DequeType* D)
{
        if(isEmpty(D))
    {
        pritnf("EMPTY!!\n");
        return;
    }
    int pos = D->rear;
    D->rear = (D->rear - 1 + SIZE) % SIZE;
    return D->data[pos];
}

char deleteFront(DequeType* D)
{
    if(isEmpty(D))
    {
        pritnf("EMPTY!!\n");
        return;
    }

    D->front = (D->front + 1) % SIZE;
    return D->data[D->front];
}

void print(DequeType* D)
{
    printf("Front pos : %d, Rear pos : %d \n", D->front, D->rear);
    int i = D->front;
    while(i != D->rear)
    {
        i = (i + 1) % SIZE;
        printf("[%c] ", D->data[i]);
    }
    printf("\n");
}

int main(void)
{
    DequeType D;
    init(&D);
    srand(time(NULL));

    for(int i = 0; i < 7; i++)
        addRear(&D, rand() % 26 + 65);
    print(&D); getchar();

    for(int i = 0; i < 3; i++)
        printf("[%c] ", deleteFront(&D));
    printf("\n\n");
    print(&D); getchar();


    for(int i = 0; i < 3; i++)
        addFront(&D, rand()%26 + 65);
    print(&D); getchar();

    
     for(int i = 0; i < 3; i++)
        printf("[%c] ", deleterear(&D));
    printf("\n\n");
    print(&D); getchar();

    return 0;
}