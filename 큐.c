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

char peek(QueueType* Q)
{
        if(isEmpty(Q))
    {
        printf("Empty \n");
        return 0;
    }

    return Q->data[(Q->front + 1) % SIZE];
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

    return 0;
}

// 원형 큐 일때
//front는 제일 먼저 들어온 애 바로 전 위치 (Q -> front + 1) %size
//rear는 제일 마지막으로 들어온 애 위치 (Q -> rear+1) %size

// isEmpty는 front랑 rear랑 같으면 (선형큐랑같음)
// isFull을 구분하기 위해 항상 한칸비워놓음 
// enqueue를 할때 rear 한칸 앞이 front면 가득찬거임

// 어우어려워