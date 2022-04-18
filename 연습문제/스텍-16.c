#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct 
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

void push(StackType* S, char c)
{
    if(isFull(S))
         printf("Over Flow!! \n");
    else
    {
        S->top++;
        S->data[S->top] = c;
    }
    
}

char pop(StackType* S)
{
    if(isEmpty(S))
    {
        printf("Under Flow!! \n");
        return -1;
    }

    char e = S->data[S->top];
    S->top--;
    return e;
}

char peek(StackType* S)
{
    if(isEmpty(S))
    {
        printf("Under Flow!! \n");
        return -1;
    }

    return S->data[S->top];
}

void print(StackType* S)
{
    for(int i = 0; i <= S->top; i++)
        printf("%c", S->data[i]);
    printf("\n");
}

int evaluate(char* c)
{
    StackType S;
    init(&S);

    int N = strlen(c);
    int mid = N/2;
    printf("%d" , N);
    for(int i = 0; i < N; i++)
    {
        if(65 <= c[i] && c[i] <= 90)
            push(&S, c[i]);
        else if(97 <= c[i] && c[i] <= 122)
        {
            c[i] -= 32;
            push(&S, c[i]);
        }
        print(&S);

    }
    

    return(isEmpty(&S));
}



int main(void)
{
    char exp[SIZE];
    scanf("%s", exp);
    
    char *p = exp;

    if(evaluate(p))
        printf("success!!");
    else    
        printf("fail...");


    return 0;
}