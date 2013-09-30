#include "Bellman_Ford.h"

using namespace std;
bool BellmanFord(GraphAdjList *g,int start,vector<int> & previous)
{
	vector<int>dist(g->numNodes,MYINF);
	vector<int>path(g->numNodes,-1);
	previous=path;

	dist[start]=0;

	for(int i=0;i<g->numNodes;++i)
	{
		//遍历邻接表中的每条边，进行松弛操作
		for(int j=0;j<g->numNodes;++j)
		{
			EdgeNode * cur=g->adjList[j].firstedge;
			while(cur!=NULL)
			{
				//找到一条k+1步之内可达的比当前路径更短的路径
				if(cur->weight+dist[j] < dist[cur->adjvex])
				{
					dist[cur->adjvex]= cur->weight+dist[j];
					previous[cur->adjvex]=j; //记录前驱
				}

				cur=cur->next;
			}
		}
	}

	for(int j=0;j<g->numNodes;++j)
	{
		EdgeNode * cur=g->adjList[j].firstedge;
		while(cur!=NULL)
		{
			if(cur->weight+dist[j] < dist[cur->adjvex])return false;
			cur=cur->next;
		}
	}

	return true;
}