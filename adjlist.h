#ifndef _ADJLIST_
#define _ADJLIST_
#include<iostream>
using namespace std;

#define MAXVEX 100 /* 最大顶点数,应由用户定义 */
typedef int VertexType; /* 顶点类型应由用户定义 */
typedef int EdgeType; /* 边上的权值类型应由用户定义 */
typedef enum{DG,NDG} GraphKind;

typedef struct EdgeNode/* 边表结点  */
{
    int adjvex;/* 邻接点域,存储该顶点对应的下标 */
    EdgeType weight;/* 用于存储权值,对于非网图可以不需要 */
    struct EdgeNode *next; /* 链域,指向下一个邻接点 */
} EdgeNode;

typedef struct VextexNode/* 顶点表结点 */
{
    VertexType data;/* 顶点域,存储顶点信息 */
    EdgeNode *firstedge;/* 边表头指针 */
} VextexNode, AdjList[MAXVEX];

typedef struct
{
    AdjList adjList;
    int numNodes, numEdges; /* 图中当前顶点数和边数 */
} GraphAdjList;


void create_adjlist_graph(GraphAdjList *Gp);
void show_adjlist_graph(GraphAdjList *Gp);
void destroy_adjlist_graph(GraphAdjList *Gp);

#endif