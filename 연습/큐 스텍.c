#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

typedef struct 
{
    char data[SIZE];
    int front, rear;
}QueueType;

void init(QueueType * Q)
{
    Q->front = Q-> rear = 0;

}

int isEmpty(QueueType* Q)
{
    return Q->front == Q->rear;
}

int isFull(QueueType* Q)
{
    return Q->front == (Q-> rear + 1) % SIZE;
}

void enqueue(QueueType* Q, char e)
{
    if(isFull(Q))
    {
        printf("Full\n");
        return;
    }

    Q -> rear = (Q->rear + 1) % SIZE;
    Q->data[Q->rear] = e;
    
}

char dequeue(QueueType* Q)
{
        if(isEmpty(Q))
    {
        printf("Empty \n");
        return 0;
    }

    Q->front = (Q->front + 1) %SIZE;
    return Q->data[Q->front];
}

int getCount(QueueType* Q)
{
    if(Q->front > Q->rear)
        return SIZE - Q->front + Q->rear;
    else
        return Q->rear - Q->front;
}

void push(QueueType *Q, char e)
{
    enqueue(Q, e);
}

char pop(QueueType* Q)
{
    QueueType Q1;
    init(&Q1);

    while(getCount(Q) != 1)
        enqueue(&Q1, dequeue(Q));
    
    char e = dequeue(Q);

    while(!isEmpty(&Q1))
        enqueue(Q, dequeue(&Q1));
    
    return e;
}


void print(QueueType* Q)
{
    printf("Front Pos : %d, Rear Pos : %d\n",Q->front,Q->rear);

    int i = Q->front;
    while(i != Q->rear)
    {
        i = (i + 1) % SIZE;
        printf("[%c] ", Q->data[i]);
    }

    printf("\n");
}

int main(void)
{
    QueueType Q;
    init(&Q);

    srand(time(NULL));

    for(int i = 0; i < 7; i++)
        enqueue(&Q, rand() % 26 + 65);

    print(&Q); getchar();

    for(int i = 0; i < 3; i++)
        printf("[%c] ", dequeue(&Q));
    printf("\n\n");
    print(&Q); getchar();

    printf("\n");

    for(int i = 0; i < 5; i++)
        enqueue(&Q, rand() % 26 + 65);
    print(&Q); getchar();

    for(int i = 0; i < 3; i++)
        printf("[%c] ", dequeue(&Q));
    printf("\n\n");
    print(&Q); getchar();

    printf("Queue -> Stack\n");

    push(&Q, rand() % 26 + 65);
    print(&Q); getchar();
    push(&Q, rand() % 26 + 65);
    print(&Q); getchar();

    printf("[%c] \n", pop(&Q));
    print(&Q); getchar();
    printf("[%c] \n", pop(&Q));
    print(&Q); getchar();
    printf("[%c] \n", pop(&Q));
    print(&Q); getchar();




    return 0;
}