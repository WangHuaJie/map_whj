/*************************************************************************
        > File Name: file.h
        > Author: HarryKing
        > Mail: wanghuajie1994@gmail.com 
        > Created Time: Wed 04 Dec 2013 08:05:34 PM CST
 ************************************************************************/

#define MAXVEX 20
typedef struct ArcNode
{
    int tailvex,
        headvex;
    int weight;
    struct ArcNode *hnextarc,
                   *tnextarc;
}ArcNode;

typedef struct VertexNode
{
    char vexdata;
    ArcNode *head,
            *tail;
}VertexNode;

typedef struct
{
    VertexNode vertex[MAXVEX];
    int vexnum;                   //number of vertex
    int arcnum;                   //number of arc
}AdjList;

//****************************************************************8
typedef struct
{
    int No;            //city's number
    char name[20];     //city's name
}Vextype;              //type of vex

typedef struct
{
    int arcs[MAXVEX][MAXVEX];  //arc set
    Vextype vex[MAXVEX];       //vex set
    int vexnum;                //vex's number
    int arcnum;                //arc's number
}AdjMatrix;                    //adjmatrix

#define MAXVEX 20
#define INFINITY 32768

//confirm the city's serial number according to the city's name
int 
Locate(AdjMatrix *G,char name[]);

//create undirecton map by AdjMatrix
int
Create(AdjMatrix *G);

//show the map's information
void
Display(AdjMatrix *G);

//search for the triffic information
void
Search(AdjMatrix *G);

//add new road
void
Add(AdjMatrix *G);

//revocate new road
void
Del(AdjMatrix *G);

//search the shortest road from start to end city by Dijkstra
void
Dijkstra(AdjMatrix *G,int start,int end,int dist[],int path[][MAXVEX]);

//find the shortest road
void
Shortcut(AdjMatrix *G);

//solve the shortest road by Prim Alogrithm
void
Prim(AdjMatrix *G,int start);

//search the connect road from some-city
void
MiniSpanTree(AdjMatrix *G);



