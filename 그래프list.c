#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct IncidentEdge
{
    char aName;
    struct IncidentEdge* next;
}IncidentEdge;


typedef struct Vertex
{
    char vName;
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

    makeVertex(&G, 'a'); makeVertex(&G, 'b');
    makeVertex(&G, 'c'); makeVertex(&G, 'd'); makeVertex(&G, 'e');

    insertEdge(&G, 'a', 'b'); insertEdge(&G, 'a', 'c');
    insertEdge(&G, 'a', 'e'); insertEdge(&G, 'b', 'c');
    insertEdge(&G, 'c', 'd');
    insertEdge(&G, 'c', 'e');
    insertEdge(&G, 'd', 'e');

    print(&G);

    return 0;
}