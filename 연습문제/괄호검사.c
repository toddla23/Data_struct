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

int check(StackType* S, char c)
{
    char ch = pop(S);
    if((ch == '[' && c == ']') || (ch == '{' && c == '}') || (ch == '(' && c == ')'))
        return 1;
    return 0;
}

int evaluate(char* c)
{
    StackType S;
    init(&S);

    int N = strlen(c);

    for(int i = 0; i < N; i++)
    {
        if(c[i] == '[' || c[i] == '{' || c[i] == '(')
            push(&S, c[i]);
        else if(c[i] == ']' || c[i] == '}' || c[i] == ')')
            if(check(&S, c[i]) != 1)
                return 0;

        print(&S);
    }
    return 1;
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