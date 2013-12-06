#include<stdio.h>
#include<string.h>
#include"file.h"

//add new rode
void
Add(AdjMatrix *G)
{
    char city[20];
    int start,
        end,
        weight;
    printf("Please input the new rode's start city's name:");
    scanf("%s",city);
    printf("end city's name:");
    scanf("%s",city);
    end = Locate(G,city);
    printf("distance:");
    scanf("%d",&weight);
    G->arcs[start][end] = weight;
    G->arcs[end][start] = weight;
}

//revocate new rode
void
Del(AdjMatrix *G)
{
    char city[20];
    int start,
        end;
    printf("Please input the Del's rode start city:");
    scanf("%s",city);
    start = Locate(G,city);
    printf("end city");
    scanf("%s",city);
    end = Locate(G,city);
    G->arcs[start][end];
    G->arcs[end][start];
}
