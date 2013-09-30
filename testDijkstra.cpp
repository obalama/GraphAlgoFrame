#include "graph.h"

using namespace std;

int main()
{
	vector<vector<int> > g;
	create_an_graph_from_stdin(g,6);
	
	show_graph(g,6);
	vector<int> path;
	int start;int end;
	while(cin>>start>>end)
	{
		path=Dijkstra(g,6,start);
		show_path(path,start,end);
	}
	system("pause");
}