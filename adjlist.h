#ifndef _ADJLIST_
#define _ADJLIST_
#include<iostream>
using namespace std;

#define MAXVEX 100 /* ��󶥵���,Ӧ���û����� */
typedef int VertexType; /* ��������Ӧ���û����� */
typedef int EdgeType; /* ���ϵ�Ȩֵ����Ӧ���û����� */
typedef enum{DG,NDG} GraphKind;

typedef struct EdgeNode/* �߱���  */
{
    int adjvex;/* �ڽӵ���,�洢�ö����Ӧ���±� */
    EdgeType weight;/* ���ڴ洢Ȩֵ,���ڷ���ͼ���Բ���Ҫ */
    struct EdgeNode *next; /* ����,ָ����һ���ڽӵ� */
} EdgeNode;

typedef struct VextexNode/* ������� */
{
    VertexType data;/* ������,�洢������Ϣ */
    EdgeNode *firstedge;/* �߱�ͷָ�� */
} VextexNode, AdjList[MAXVEX];

typedef struct
{
    AdjList adjList;
    int numNodes, numEdges; /* ͼ�е�ǰ�������ͱ��� */
} GraphAdjList;


void create_adjlist_graph(GraphAdjList *Gp);
void show_adjlist_graph(GraphAdjList *Gp);
void destroy_adjlist_graph(GraphAdjList *Gp);

#endif