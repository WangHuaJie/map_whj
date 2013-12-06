#include<stdio.h>
#include<string.h>
#include"file.h"

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
                            G->arcs[i][j]
                          );
            }
    }
}

void 
Search(AdjMatrix *G)
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
                            G->arcs[i][j]);
}

//solve the shortest rode from start to end city by Dijkstra
void
Dijkstra(AdjMatrix *G,int start,int end,int dist[],int path[][MAXVEX])
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
        mindist = INFINITY;
        for(j = 1;j <= G->vexnum;i++)
            if(!path[j][0] && dist[j] < mindist)
            { 
                k = j;
                mindist = dist[j];
            }
        if(mindist == INFINITY)
            return;
        path[k][0] = 1;
        for(j = 1;j <= G->vexnum;j++)            //change the rode
        {
            if(!path[j][0] && G->arcs[k][j]
                    < INFINITY && dist[k] + G->arcs[k][j] < dist[j])
            {
                dist[j] = dist[k] + G->arcs[k][j];
                t = 1;
                while(path[k][t] != 0)
                {
                    path[j][t] = path[k][t];
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
            G->vex[start].name,
            G->vex[end].name,
            G->vex[start].name);
    for(j = 2;path[i][j] != 0;j++)
        printf("->%s",G->vex[path[i][j]].name);
    printf("->%s, distence is %d km\n",G->vex[end].name,dist[i]);
}

//find the shortest rode
void
Shortcut(AdjMatrix *G)
{
    char city[20];
    int start,
        end;
    int dist[MAXVEX],   
        path[MAXVEX][MAXVEX] = {0};
    printf("Please input the start city:");
    scanf("%s",city);
    start = Locate(G,city);
    printf("Please input the end city:");
    scanf("%s",city);
    end = Locate(G,city);
    Dijkstra(G,start,end,dist,path);
}

//solve the shortest rode by Prim Alogrithm
void
Prim(AdjMatrix *G,int start)
{
    struct
    {
        int adjvex;
        int lowcost;
    }closedge[MAXVEX];
    int i,
        e,
        k,
        m,
        min;
    closedge[start].lowcost = 0; //indicate that the vex U has been 
                                 // added into generating tree set
    //init all the vex's corresponding closedge-array except the 
    //start city
    for(i = 1;i <= G->vexnum;i++)
        if(i != start)
        {
            closedge[i].adjvex = start;
            closedge[i].lowcost = G->arcs[start][i];
        }
    for(e = 1;e <= G->vexnum-1;e++) 
    {
        //chose the lightest arc
        min = INFINITY;
        for(k = 1;k <= G->vexnum;k++)
        {
            if(closedge[k].lowcost != 0 && closedge[k].lowcost < min)
            {
                m = k;
                min = closedge[k].lowcost;
            }
        }
        printf("from %s--%s: %d km\n",
                G->vex[closedge[m].adjvex].name,
                G->vex[m].name,
                closedge[m].lowcost
              );
        closedge[m].lowcost = 0;         //indicate that the v0 added
                                         // into the g-t-s
        //when the v0 added ,update array's information
        for(i = 1;i <= G->vexnum; i++)
            if(i != m && G->arcs[m][i] < closedge[i].lowcost)
            {
                closedge[i].lowcost = G->arcs[m][i];
                closedge[i].adjvex = m;
            }
    }
}

//search the connected rode from some-city
void
MiniSpanTree(AdjMatrix *G)
{
    char city[20];
    int start;
    printf("Please input start city:");
    scanf("%s",city);
    start = Locate(G,city);
    Prim(G,start);
}
