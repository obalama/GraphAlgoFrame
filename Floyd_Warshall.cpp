#include "Floyd_Warshall.h"

using namespace std;

void Floyd_Warshall(Graph_Matrix & g,Graph_Matrix &path,Graph_Matrix &dp)
{
	//可以先用Bellman-Ford算法检查一下是否有负值回路

	int numNodes=g.size();
	
	//图用矩阵表示，因此为了方便起见path和dp表也按照图的方式存放
	path=g;
	dp=g;

	for(int i=0;i<numNodes;++i)
	{
		for(int j=0;j<numNodes;++j)
		{
			if(g[i][j]>=MYINF)path[i][j] = -1 ;//-1 表示不经过任何结点
			else path[i][j] = j;
			dp[i][j]=g[i][j];
		}
	}

	for(int k=0;k<numNodes;++k)
		for(int i=0;i<numNodes;++i)
			for(int j=0;j<numNodes;++j)
			{
				if(dp[i][k]<MYINF && dp[k][j]<MYINF && dp[i][k]+dp[k][j]<dp[i][j])
				{
					dp[i][j] = dp[i][k] + dp[k][j];
					path[i][j] = path[i][k];//path[i][j]存储i到j的路线上i的后继结点
				}
			}

		


}
void Floyd_Warshall_Path(Graph_Matrix &path, int start, int end)
{
	cout<<"从"<<start<<"到"<< end <<"的最短路径 : ";
	while(start!=end)
	{
		cout<<start<<" ";
		start=path[start][end];
		if(start==-1)
		{
			cout<<"no route!!"<<endl;return;
		}
	}
	cout<<end<<endl;
}