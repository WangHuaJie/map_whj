#include<stdio.h>
#include<string.h>
#include"file.h"

//confirm the city's serial number according to the city's name
int 
Locate(AdjMatrix *G, char name[])
{
    int i;
    for(i = 1;i <= G->vexnum;i++)
        if(!strcmp(name,G->vex[i].name))
            return i;
    return -1;
}

//create undirecton map by AdjMatrix
int
Create(AdjMatrix *G)
{
    int i,
        j,
        k,
        weight;
    char city[20];
    printf("Please input the city's & rode's number in the creating map:\n");
    scanf("%d,%d",&G->vexnum,&G->arcnum);
    for(i = 1;i <= G->vexnum;i++)
        for(j = 1;j <= G->vexnum;j++)
            G->arcs[i][j] = INFINITY;
    printf("Please input the %d citys and their name\
            :\n",G->vexnum);
    for(i = 1;i <= G->vexnum;i++)
    {
        printf("No.%d city:",i);
        G->vex[i].No = i;
        fflush(NULL);
        scanf("%s",G->vex[i].name);
    }
    printf("Please input the %d rodes in the map\
            :\n",G->arcnum);
    for(k = 0;k <G->arcnum; k++)
    {
        printf("No.%d rode:",k+1);
        printf("\nbegin city:");
        scanf("%s",city);
        i = Locate(G,city);
        printf("end city:");
        scanf("%s",city);
        j = Locate(G,city);
        printf("distance:");
        scanf("%d",&weight);
        G->arcs[i][j] = weight;
        G->arcs[j][i] = weight;
    }
    return 1;
}

