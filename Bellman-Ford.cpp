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
		//�����ڽӱ��е�ÿ���ߣ������ɳڲ���
		for(int j=0;j<g->numNodes;++j)
		{
			EdgeNode * cur=g->adjList[j].firstedge;
			while(cur!=NULL)
			{
				//�ҵ�һ��k+1��֮�ڿɴ�ıȵ�ǰ·�����̵�·��
				if(cur->weight+dist[j] < dist[cur->adjvex])
				{
					dist[cur->adjvex]= cur->weight+dist[j];
					previous[cur->adjvex]=j; //��¼ǰ��
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