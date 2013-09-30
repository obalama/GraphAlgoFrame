#include "Floyd_Warshall.h"

using namespace std;

int main()
{
	vector<vector<int> > g;
	create_an_graph_from_stdin(g,6);
	vector<vector<int> >path;
	vector<vector<int> >dp;

	
	Floyd_Warshall(g,path,dp);
	while(true)
	{
		int start;
		int end;
		cout<<"输入要查询的起点和终点："<<endl;
		cin>>start>>end;
		Floyd_Warshall_Path(path,start,end);
	}
	system("pause");
}
