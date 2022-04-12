#include <stdio.h>
#include<stdlib.h>

#define SIZE 10

typedef struct StackType
{
    char data[SIZE];
    int top;
}StackType;

void init(StackType* S)
{
    S->top = -1;
}

int isEmpty(StackType* S)
{
    return S->top == -1;
}

int isFull(StackType* S)
{
    return S->top == SIZE - 1;
}

void push(StackType* S, char e)
{
    if(isFull(S))
    {
        printf("Overflow\n");
        return;
    }
    
    S->top++;
    S->data[S->top] = e;
}

char pop(StackType* S)
{
    if(isEmpty(S))
    {
        printf("Empty\n");
        return 0;
    }
    
    char temp = S->data[S->top];
    S->top--;
    return temp;
}

void enqueue(StackType* S1, char e)
{
    push(S1, e);
}

char dequeue(StackType* S1, StackType* S2)
{
    char e;

    while(S1->top != -1)
    {
        push(S2, pop(S1));
    }
    e = pop(S2);

    while(S2->top != -1)
    {
        push(S1, pop(S2));
    }

    return e;
}

int main()
{
	StackType S1, S2;
	init(&S1); init(&S2);
	
	enqueue(&S1, 'A');
	enqueue(&S1, 'B');
	enqueue(&S1, 'C');
	printf("[%c] ", dequeue(&S1, &S2));
	
	enqueue(&S1, 'D');
	enqueue(&S1, 'E'); 
	printf("[%c] ", dequeue(&S1, &S2));
	printf("[%c] ", dequeue(&S1, &S2));
	printf("[%c] ", dequeue(&S1, &S2));
	printf("[%c] ", dequeue(&S1, &S2));
	
}