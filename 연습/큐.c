#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define size 10

typedef struct
{
    int data[size];
    int front, rear;
}queueType;

void init(queueType* Q)
{
    Q->front = Q->rear = -1;
}

int isEmpty(queueType* Q)
{
    return Q->front == Q->rear;
}

int isFull(queueType* Q)
{
    return Q->rear == (Q->front + 1) % 20;
}

void enqueue(queueType* Q, int c)
{   
    Q->rear = (Q->rear + 1) % size;
    Q->data[Q->rear] = c;
}

int dequeue(queueType* Q)
{
    Q->front = (Q->front + 1) % size;
    return Q->data[Q->front];
}

void print(queueType* Q)
{
    for(int i = Q->front; i < Q->rear; i++)
    {
        printf("[%d] ", Q->data[i+1]);
    }
    printf("\n");
}

int getCount(queueType* Q)
{
    if(Q->front > Q->rear)
        return size - Q->front + Q->rear;
    else
        return Q->rear - Q->front;
}

int fibo(queueType* Q, int n)
{
    for(int i = 1; i < n; i++)
    {
        int q1 = dequeue(Q);
        enqueue(Q, q1+Q->data[Q->front]);
        print(Q);
    }
    return Q->data[Q->rear];
}

int main(void)
{
    queueType Q;
    init(&Q);

    srand(time(NULL));

    /*for(int i = 0; i < 7; i++)
        enqueue(&Q, rand() % 26 + 65);

    print(&Q); getchar();

    for(int i = 0; i < 3; i++)
        printf("[%d] ", dequeue(&Q));
    printf("\n\n");

    print(&Q); getchar();

    printf("\n");

    for(int i = 0; i < 5; i++)
        enqueue(&Q, rand() % 26 + 65);
    print(&Q); getchar();

    for(int i = 0; i < 3; i++)
        printf("[%d] ", dequeue(&Q));
    printf("\n\n");
    print(&Q); getchar();*/

    queueType Q1;
    init(&Q1);

    enqueue(&Q1, 0);
    enqueue(&Q1, 1);

    printf("%d",fibo(&Q1, 5));


    

    return 0;
}