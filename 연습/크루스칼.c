#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Edge
{
    char name;
    int weight;
    struct Edge* next;    
}Edge;

typedef struct Vertex
{
    char name;
    Edge* eHead;
    struct Vertex* next;

}Vertex;


typedef struct
{
    Vertex* GHead;
}Graph;

void init(Graph* G)
{
    G->GHead = NULL;
}

void insertVertex(Graph* G, char v)
{
    Vertex * v1 = (Vertex*)malloc(sizeof(Vertex));
    v1->name = v;
    v1->next = NULL;
    v1->eHead = NULL;

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
    Edge* E = (Edge*)malloc(sizeof(Edge));
    E->name = e;
    E->next = NULL;
    E->weight = weight;

    Edge* p = v1->eHead;

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
    Vertex* v1 = findVertex(G, e1);
    makeIncidentEdge(G, v1, e2, weight);

    v1 = findVertex(G, e2);
    makeIncidentEdge(G, v1, e1, weight);
}


void print(Graph* G)
{
    Vertex* p = G->GHead;
    while(p != NULL)
    {
        printf("[%c] : ", p->name);
        
        Edge* e = p->eHead;

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

    



    return 0;
}