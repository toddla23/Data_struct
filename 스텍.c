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

void evaluate(char postfix[])
{
    StackType S;
    init(&S);
    
    int op1, op2, value;
    char c;
    int n = strlen(postfix);    // 대문자 A = 65 소문자 a = 97
    
    if(postfix[0] < 97)
        postfix[0] += 32;

    push(&S, 1);
    push(&S, postfix[0]);

    for(int i = 1; i < n; i++)
    {
        c = postfix[i];
        
        if(c < 97)
            c += 32;



    }
    return pop(&S);
}

int prec(char op)
{
    switch(op)
    {
        case '(': case ')':
            return 0;
        case '+': case '-':
            return 1;
        case '*': case '/':
            return 2;
    }
}

void convert(char exp[])
{
    StackType S;
    init(&S);
    
    char c, t;
    int n = strlen(exp);
    
    for(int i = 0; i < n; i++)
    {
        c = exp[i];
        switch(c)
        {
            case '+': case '-': case '*': case '/':
                while(!isEmpty(&S) && prec(c) <= prec(peek(&S)))
                    printf("%c", pop(&S));
                push(&S, c);
                break;
            case '(':
                push(&S, c);
                break;
            case ')':
                t = pop(&S);
                while(t != '(')
                {
                    printf("%c", t);
                    t = pop(&S);
                }
                break;
            default:
                printf("%c", c);
                break;
        }
    }
    while(!isEmpty(&S))
        printf("%c", pop(&S));
    printf("\n");    
}



int main(void)
{
    char exp[SIZE];
    scanf("%s", exp);


    return 0;
}