#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Edge
{
    char v1;
    char v2;
    int weight;
    struct Edge* next;    
}Edge;

typedef struct incidentEdge
{
    char name;
    int weight;
    struct incidentEdge* next;   
}incidentEdge;


typedef struct Vertex
{
    char name;
    incidentEdge* eHead;
    struct Vertex* next;
}Vertex;

typedef struct
{
    Vertex* GHead;
    Edge* eHead;
    int vCount, eCount;
}Graph;



void init(Graph* G)
{
    G->GHead = NULL;
    G->vCount = 0;
    G->eCount = 0;
}

void insertVertex(Graph* G, char v)
{
    Vertex * v1 = (Vertex*)malloc(sizeof(Vertex));
    v1->name = v;
    v1->next = NULL;
    v1->eHead = NULL;

    G->vCount++;

    Vertex * p = G->GHead;

    if(G->GHead == NULL)
        G->GHead = v1;
    else
    {
        while(p->next != NULL)
            p = p->next;
        p->next = v1;
    }

}

Vertex* findVertex(Graph* G, char e)
{
    Vertex* p = G->GHead;
    while(p != NULL)
    {
        if(p->name == e)
            return p;
        p = p->next;
    }
}

void makeIncidentEdge(Graph* G, Vertex* v1, char e, int weight)
{
    incidentEdge* E = (incidentEdge*)malloc(sizeof(incidentEdge));
    E->name = e;
    E->next = NULL;
    E->weight = weight;

    incidentEdge* p = v1->eHead;

    if(p == NULL)
        v1->eHead = E;
    else
    {
        while(p->next != NULL)
            p = p->next;

        p->next = E;
    }
}

void insertEdge(Graph* G, char e1, char e2, int weight)
{
    Edge* e = (Edge*)malloc(sizeof(Edge));
    e->v1 = e1;
    e->v2 = e2;
    e->weight = weight;
    e->next = NULL;
    G->eCount++;

    Edge* p = G->eHead;

    if(p == NULL)
        G->eHead = e;
    else
    {
        while(p->next != NULL)
            p = p->next;
    
        p->next = e;
    }


    Vertex* v1 = findVertex(G, e1);
    makeIncidentEdge(G, v1, e2, weight);

    v1 = findVertex(G, e2);
    makeIncidentEdge(G, v1, e1, weight);
}

void incSort(Graph* G, Edge* e[])
{
    Edge* p = G->eHead;

    int i , least;

    for(i = 0; i < G->eCount; i++)
    {
        e[i] = p;
        p = p->next;
    }

    for(i = 0; i < G->eCount - 1; i++)
    {
        least = i;

        for(int j = i + 1; j < G->eCount; j++)
            if(e[j]->weight < e[least]->weight)
                least = j;

        p = e[least];
        e[least] = e[i];
        e[i] = p;
    }
    
    for(i = 0; i < G->eCount - 1; i++)
        printf("[%c%c%d] ", e[i]->v1, e[i]->v2, e[i]->weight);
    

    printf("\n\n");
}

void kruskal(Graph* G, Edge* e[], int v[])
{
    int eCnt = 0, i = 0;
    int vNum1, vNum2;

    Edge* p;

    while(eCnt < G->vCount-1)
    {
        p = e[i];
        vNum1 = vFind(v, p->v1);
    }
    
}


void print(Graph* G)
{
    Vertex* p = G->GHead;
    while(p != NULL)
    {
        printf("[%c] : ", p->name);
        
        incidentEdge* e = p->eHead;

        while(e != NULL)
        {
            printf("[%c, %d] ", e->name, e->weight);
            e = e->next;
        }

        printf("\n");
        p = p->next;
    }
}

int main(void)
{
    Graph G;
    init(&G);


    insertVertex(&G, 'a');
    insertVertex(&G, 'b');
    insertVertex(&G, 'c');
    insertVertex(&G, 'd');
    insertVertex(&G, 'e');
    insertVertex(&G, 'f');
    insertVertex(&G, 'g');


    insertEdge(&G, 'a', 'b', 29); insertEdge(&G, 'a', 'f', 10);
    insertEdge(&G, 'b', 'c', 16); insertEdge(&G, 'b', 'g', 15);
    insertEdge(&G, 'c', 'd', 12); insertEdge(&G, 'd', 'g', 18);
    insertEdge(&G, 'd', 'e', 22); insertEdge(&G, 'e', 'f', 27);
    insertEdge(&G, 'e', 'g', 25);

    print(&G);


    Edge* e[20]; 
    incSort(&G, e);

    char v[G.vCount];
    kruskal(&G, e, v);



    return 0;
}