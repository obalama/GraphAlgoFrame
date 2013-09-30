#include "Floyd_Warshall.h"

using namespace std;

void Floyd_Warshall(Graph_Matrix & g,Graph_Matrix &path,Graph_Matrix &dp)
{
	//��������Bellman-Ford�㷨���һ���Ƿ��и�ֵ��·

	int numNodes=g.size();
	
	//ͼ�þ����ʾ�����Ϊ�˷������path��dp��Ҳ����ͼ�ķ�ʽ���
	path=g;
	dp=g;

	for(int i=0;i<numNodes;++i)
	{
		for(int j=0;j<numNodes;++j)
		{
			if(g[i][j]>=MYINF)path[i][j] = -1 ;//-1 ��ʾ�������κν��
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
					path[i][j] = path[i][k];//path[i][j]�洢i��j��·����i�ĺ�̽��
				}
			}

		


}
void Floyd_Warshall_Path(Graph_Matrix &path, int start, int end)
{
	cout<<"��"<<start<<"��"<< end <<"�����·�� : ";
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