#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define size 10

typedef struct
{
    char data[size];
    int front, rear;
}dequeType;

void init(dequeType* D)
{
    D->front = 0;
    D->rear = 0;
}

int isFull(dequeType* D)
{
    return D->rear == D->front + 1;
}

int isEmpty(dequeType* D)
{
    return D->front == D->rear;
}

void addFront(dequeType* D, char e)
{
    D->front = (size + D->front - 1) % size;
    D->data[D->front] = e;
}

void addRear(dequeType* D, char e)
{
    D->rear = (D->rear + 1) % size;
    D->data[D->rear] = e;
}

char deleteFront(dequeType* D)
{
    D->front = (D->front + 1) % size;
    char e  = D->data[D->front];

    return e;
}

char deleteRear(dequeType* D)
{
    char e  = D->data[D->rear];
    D->rear = (size + D->rear - 1) % size;
    return e;
}

void print(dequeType* D)
{
    printf("Front pos : %d, Rear pos : %d \n", D->front, D->rear);
    int i = D->front;
    while(i != D->rear)
    {
        i = (i + 1) % size;
        printf("[%c] ", D->data[i]);
    }
    printf("\n");
}

int main(void)
{
    dequeType D;
    init(&D);

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
        printf("[%c] ", deleteRear(&D));
    printf("\n\n");
    print(&D); getchar();

    return 0;
}