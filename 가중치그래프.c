#include <stdio.h>
#include <stdlib.h>

typedef struct Edge{
    char v1, v2;
    int weight;
    struct Edge *next;
}Edge;


typedef struct IncidentEdge
{
    char aName;
    Edge *e;
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
    Vertex *vHead;
    Edge *eHead;
    int eCount, vCount;
}GraphType;

void init(GraphType* G)
{
    G->vHead = NULL;
    G->eHead = NULL;
    G->vCount = G->eCount = 0;
}


void makeVertex(GraphType* G, char vName)
{
    Vertex* v = (Vertex*)malloc(sizeof(Vertex));
    v->vName = vName;
    v->iHead = NULL;
    v->next = NULL;
    G->vCount++;

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


void makeIncidentEdge(Vertex* v, char aName, Edge* e)
{
    IncidentEdge* p = (IncidentEdge*)malloc(sizeof(IncidentEdge));
    p->aName = aName;
    p->e = e;
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

void insertEdge(GraphType* G, char v1, char v2, int w)
{
    Edge* e = (Edge *)malloc(sizeof(Edge));
    e->weight = w;
    e->v1 = v1;
    e->v2 = v2;
    e->next = NULL;
    G->eCount++;
   
    Edge* q = G->eHead;
    if(q == NULL)
        G->eHead = e;
    else
    {
        while(q->next != NULL)
            q = q->next;
        q->next = e;    
    }

    Vertex* v = findVertex(G, v1);
    makeIncidentEdge(v, v2, e);

    v = findVertex(G, v2);
    makeIncidentEdge(v, v1, e);
}

void print(GraphType* G)
{
    Vertex* p = G->vHead;
    IncidentEdge* q;

    for(; p != NULL; p = p->next)
    {
        printf("[%c] : ", p->vName);
        for(q = p->iHead; q != NULL; q = q->next)
            printf("[%c, %d] ", q->aName, q->e->weight);
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
    makeVertex(&G, 'g');
   
    insertEdge(&G, 'a', 'b', 29); insertEdge(&G, 'a', 'f', 10);
    insertEdge(&G, 'b', 'c', 16); insertEdge(&G, 'b', 'g', 15);
    insertEdge(&G, 'c', 'd', 12); insertEdge(&G, 'd', 'g', 18);
    insertEdge(&G, 'd', 'e', 22); insertEdge(&G, 'e', 'f', 27);
    insertEdge(&G, 'e', 'g', 25); print(&G);
}