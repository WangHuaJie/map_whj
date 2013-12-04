/*************************************************************************
        > File Name: Transportation_System.c
        > Author: HarryKing
        > Mail: wanghuajie1994@gmail.com 
        > Created Time: Wed 04 Dec 2013 08:42:19 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#define MAXVEX 20   
#define INFINITY 32768
typedef struct
{
    int No;                                      //city's number
    char name[20];                               //city's name
}Vextype;

typedef struct
{   
    int arcs[MAXVEX][MAXVEX];                    //arc set
    Vextype vex[MAXVEX];                         //vertexset
    int vexnum;                                  //vertex's number
    int arcnum;                                  //arc's number
}AdjMatrix;

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
    printf("Please input the city's & rode's number\
            in the creating map:\n");
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
        flushall();
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

//show the map information
void
Display(AdjMatrix *G)
{
    int i,
        j;
    printf("\n city triffic's condition:\n");
    for(i = 1 ;i <= G->vexnum; i++)
    {
        for(j = 1;j <= i;j++)
        {
            if(G->arcs[i][j] != INFINITY)
                printf("%s<--->%s:%6dkm\n",
                        G->vex[i].name,
                        G->vex[j].name,
                        G->arcs[i][j],
                      );
        }
    }
}

void 
Serach(AdjMatrix *G)
{
    char city[20];
    int No,
        i,
        j;
    printf("Please input the searching city's name:");
    scanf("%s",city);
    No = Locate(G,city);
    printf("the city's triffic condition:");
    for(i = 1;i <= G->vexnum;i++)
        if(i == No)
            for(j = 1;j <= G->vexnum;j++);
                if(G->arcs[i][j] != INFINITY)   
                    printf("%s---%s:%dkm\n",
                            G->vex[No].name,
                            G->vex[j].name,
                            G->arcs[i][j],
                          );
}

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
    printf("distance:")'
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

//solve the shortest rode from start to end city by Dijkstra
void
Dijkstra(AdjMatrix *G,int start,int end,int dis[],int path[][MAXVEX])
{
    int mindist,
        i,
        j,
        k,
        t = 1;
    for(i = 1;i <= G->vexnum;i++)
    {
        dist[i] = G->arcs[start][i];
        if(G->arcs[start][i] != INFINITY)
            path[i][1] = start;
    }
    path[start][0] = 1;
    for(i = 2;i <= G->vexnum;j++)
    {
        mindist = INSINITY;
        for(j = 1;j <= G->vexnum;i++)
            if(!path[j][0] && dist[j] < mindist)
            { 
                k = j;
                mindist = dist[j];
            }
        if(mindist == INFINITY)
            return;
        paty[k][0] = 1;
        for(j = 1;j <= G->vexnum;j++)            //change the rode
        {
            if(!path[j][0] && G->arcs[k][j]
                    < INFINITY && dist[k] + G->arcs[k][j] < dist[j])
            {
                dist[j] = dist[k] + G->arcs[k][j];
                t = 1;
                while(path[k][t] != 0)
                {
                    path[j][t] = pat[k][t];
                    t++;
                }
                path[j][t] = k;
                path[j][t+1] = 0;
                }
        }
    }
    for(i = 1;i <= G->vexnum;i++)
        if(i == end)
            break;
    printf("%s--->%s the shortest rode is from %s",
    
    
