#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1
#define SIZE 10

typedef struct
{
    char elem[SIZE];
    int top;
}StackType;


void initStack(StackType* S)
{
    S->top = -1;
}

int isStackEmpty(StackType* S)
{
    return S->top == -1;
}


int isStackFull(StackType* S)
{
    return S->top == SIZE - 1;
}


void push(StackType* S, char vName)
{
    if(isStackFull(S))
    {
        printf("Overflow\n");
        return;
    }

    S->top++;
    S->elem[S->top] = vName;
}


char pop(StackType* S)
{
    if(isStackEmpty(S))
    {
        printf("Empty\n");
        return 0;
    }

    char vName = S->elem[S->top];
    S->top--;
    return vName;
}

char peek(StackType* S)
{
    if(isStackEmpty(S))
    {
        printf("Empty\n");
        return 0;
    }

    return S->elem[S->top];
}

typedef struct
{
    char elem[SIZE];
    int front, rear;

}QueueType;


void initQueue(QueueType* Q)
{
    Q->front = Q->rear = 0;
}


int isQueueEmpty(QueueType* Q)
{
    return Q->rear == Q->front;
}


 
int isQueueFull(QueueType* Q)
{
    return (Q->rear + 1) % SIZE == Q->front;
}


void enqueue(QueueType* Q, char vName)
{
    if (isQueueFull(Q))
    {
        printf("FULL\n");
        return;
    }

    Q->rear = (Q->rear + 1) % SIZE;
    Q->elem[Q->rear] = vName;
}


char dequeue(QueueType* Q)
{
    if (isQueueEmpty(Q))
    {   
        printf("EMPTY\n");
        return 0;
    }

    Q->front = (Q->front + 1) % SIZE;

    return Q->elem[Q->front];
}

typedef struct IncidentEdge
{

    char aName;
    struct IncidentEdge* next;

}IncidentEdge;


typedef struct Vertex
{

    char vName;
    int isVisit;
    IncidentEdge* iHead;
    struct Vertex* next;

}Vertex;


typedef struct
{
    Vertex* vHead;
}GraphType;


void init(GraphType* G)
{
    G->vHead = NULL;
}


void makeVertex(GraphType* G, char vName)
{
    Vertex* v = (Vertex*)malloc(sizeof(Vertex));
    v->vName = vName;
    v->isVisit = FALSE;
    v->iHead = NULL;
    v->next = NULL;

    Vertex* p = G->vHead;

    if(p == NULL)
        G->vHead = v;
    else
    {
        while(p->next != NULL)
            p = p->next;
        p->next = v;    
    }
}


void makeIncidentEdge(Vertex* v, char aName)
{
    IncidentEdge* p = (IncidentEdge*)malloc(sizeof(IncidentEdge));
    p->aName = aName;
    p->next = NULL;
    IncidentEdge* q = v->iHead;

    if(q == NULL)
        v->iHead = p;
    else
    {
        while(q->next != NULL)
            q = q->next;
        q->next = p;    
    }
}


Vertex* findVertex(GraphType* G, char vName)
{
    Vertex* v = G->vHead;

    while(v->vName != vName)
        v = v->next;

    return v;    
}


void insertEdge(GraphType* G, char v1, char v2)
{
    Vertex* v = findVertex(G, v1);
    makeIncidentEdge(v, v2);

    v = findVertex(G, v2);
    makeIncidentEdge(v, v1);

}


void print(GraphType* G)
{
    Vertex* p = G->vHead;
    IncidentEdge* q;

    for(; p != NULL; p = p->next)
    {
        printf("[%c] : ", p->vName);
        for(q = p->iHead; q != NULL; q = q->next)
            printf("[%c] ", q->aName);
        printf("\n");    
    }

    printf("\n");
}


int main()
{
    GraphType G;
    init(&G);
   
    makeVertex(&G, 'a'); makeVertex(&G, 'b'); makeVertex(&G, 'c');
    makeVertex(&G, 'd'); makeVertex(&G, 'e'); makeVertex(&G, 'f');
    makeVertex(&G, 'g'); makeVertex(&G, 'h');

    insertEdge(&G, 'a', 'b'); insertEdge(&G, 'a', 'c');
    insertEdge(&G, 'b', 'd'); insertEdge(&G, 'b', 'e');
    insertEdge(&G, 'c', 'e'); insertEdge(&G, 'e', 'f');
    insertEdge(&G, 'f', 'g'); insertEdge(&G, 'g', 'h');
   
    print(&G);
    
    return 0;

}