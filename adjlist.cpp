#include "adjlist.h"
void create_adjlist_graph(GraphAdjList *Gp)
{
    int i, j, k,w;
    EdgeNode *pe;
    cout << "输入顶点数和边数(空格分隔）:" << endl;
    cin >> Gp->numNodes >> Gp->numEdges;

	cout << "输入顶点信息：" << endl;
    for (i = 0 ; i < Gp->numNodes; i++)
    {
        cin >> Gp->adjList[i].data;
        Gp->adjList[i].firstedge = NULL;/* 将边表置为空表 */
    }

    for (k = 0; k <  Gp->numEdges; k++)/* 建立边表 */
    {
        cout << "输入边(vi,vj,w)的顶点序号i,j,w（空格分隔）:" << endl;
        cin >> i >> j >> w;
        pe = (EdgeNode *)malloc(sizeof(EdgeNode));
        pe->adjvex = j;/* 邻接序号为j */
		pe->weight = w;
        /* 将pe的指针指向当前顶点上指向的结点 */
        pe->next = Gp->adjList[i].firstedge;
        Gp->adjList[i].firstedge = pe;/* 将当前顶点的指针指向pe */

		//如果是无向图可以加上下面这段代码
       /* pe = (EdgeNode *)malloc(sizeof(EdgeNode));
        pe->adjvex = i;
        pe->next = Gp->adjList[j].firstedge;
        Gp->adjList[j].firstedge = pe;*/

    }

	cout<<"有向图的邻接表创建成功..."<<endl;
}

void show_adjlist_graph(GraphAdjList *Gp)
{
	cout<<"邻接表如下："<<endl;
	if(Gp->numNodes == 0 || Gp->numEdges == 0)cout<<"The adjlist is empty!"<<endl;

	for(int v=0;v<Gp->numNodes;++v)
	{
		cout<<"V"<<v<<":";
		if(Gp->adjList[v].firstedge==NULL)cout<<"NULL"<<endl;
		else
		{
			EdgeNode *cur=Gp->adjList[v].firstedge;
			while(cur!=NULL)
			{
				cout<<"V"<<cur->adjvex<<"("<<cur->weight<<")"<<" ";
				cur=cur->next;
			}
			cout<<endl;
		}	
	}
}

void destroy_adjlist_graph(GraphAdjList *Gp)
{
	if(Gp->numNodes == 0 || Gp->numEdges == 0)return ;
	else
	{
		for(int v=0;v<Gp->numNodes;++v)
		{
			while(Gp->adjList[v].firstedge!=NULL)
			{
				EdgeNode *cur=Gp->adjList[v].firstedge;
				Gp->adjList[v].firstedge=cur->next;

				free(cur);
			}
		}
	}

	cout<<"邻接表销毁成功..."<<endl;
}