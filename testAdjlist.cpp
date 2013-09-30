#include "Bellman_Ford.h"
#include "graph.h"
using namespace std;

int main()
{
	GraphAdjList g;
	create_adjlist_graph(&g);
	show_adjlist_graph(&g);
	vector<int>previous;
	cout<<"executing Bellman-Ford Algorithm: "<<endl;
	while(true)
	{
		cout<<"input start and end: ";
		int start ; int end;
		cin>>start>>end;
		if(start==-1)break;
		if(BellmanFord(&g,start,previous))
		{
			show_path(previous,start,end);
		}
		else cout<<"Negative circle exists"<<endl;
	}

	
	destroy_adjlist_graph(&g);
	show_adjlist_graph(&g);
	system("pause");
}