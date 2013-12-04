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

