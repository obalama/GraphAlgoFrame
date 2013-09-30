#include "adjlist.h"
void create_adjlist_graph(GraphAdjList *Gp)
{
    int i, j, k,w;
    EdgeNode *pe;
    cout << "���붥�����ͱ���(�ո�ָ���:" << endl;
    cin >> Gp->numNodes >> Gp->numEdges;

	cout << "���붥����Ϣ��" << endl;
    for (i = 0 ; i < Gp->numNodes; i++)
    {
        cin >> Gp->adjList[i].data;
        Gp->adjList[i].firstedge = NULL;/* ���߱���Ϊ�ձ� */
    }

    for (k = 0; k <  Gp->numEdges; k++)/* �����߱� */
    {
        cout << "�����(vi,vj,w)�Ķ������i,j,w���ո�ָ���:" << endl;
        cin >> i >> j >> w;
        pe = (EdgeNode *)malloc(sizeof(EdgeNode));
        pe->adjvex = j;/* �ڽ����Ϊj */
		pe->weight = w;
        /* ��pe��ָ��ָ��ǰ������ָ��Ľ�� */
        pe->next = Gp->adjList[i].firstedge;
        Gp->adjList[i].firstedge = pe;/* ����ǰ�����ָ��ָ��pe */

		//���������ͼ���Լ���������δ���
       /* pe = (EdgeNode *)malloc(sizeof(EdgeNode));
        pe->adjvex = i;
        pe->next = Gp->adjList[j].firstedge;
        Gp->adjList[j].firstedge = pe;*/

    }

	cout<<"����ͼ���ڽӱ����ɹ�..."<<endl;
}

void show_adjlist_graph(GraphAdjList *Gp)
{
	cout<<"�ڽӱ����£�"<<endl;
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

	cout<<"�ڽӱ����ٳɹ�..."<<endl;
}