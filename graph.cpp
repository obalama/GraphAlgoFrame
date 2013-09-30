#include "graph.h"
using namespace std;
void create_an_graph_from_stdin(vector<vector<int> > &g,int vNum)
{
	int w=vNum;int h=vNum;
	vector<int>line(w,MYINF);
	for(int ih=0;ih<h;++ih)g.push_back(line);

	for(int ih=0;ih<h;++ih)
	{
		for(int iw=0;iw<w;++iw)
		{
			cin>>g[ih][iw];
			if(g[ih][iw]>THRE)g[ih][iw]=MYINF;
		}
	}
}

void show_graph(vector<vector<int> > &g,int vNum)
{
	int h=vNum;int w=vNum;
	cout<<"The graph is :"<< endl;
	for(int ih=0;ih<h;++ih)
	{
		for(int iw=0;iw<w;++iw)
		{
			
			if(g[ih][iw]==MYINF)cout<<"INF ";
			else cout<<g[ih][iw]<<" ";
		}

		cout<<endl;
	}
	cout<<endl;
}


vector<int> Dijkstra(vector<vector<int> > &g, int vNum,int start)
{
	vector<int>path(vNum,-1);//-1表示路径未找到
	vector<int>dist(vNum,MYINF);
	dist[start]=0;
	set<int>source;//一旦一个点距离源点start最短路径被找到，那么该点就被加入集合source中
	set<int>dest; //source 的补集
	for(int i=0;i<vNum;++i)dest.insert(i);

	
	set<int>::iterator iter_s;
	set<int>::iterator iter_d;

	int cur=start;
	
	while(!dest.empty())
	{
		int curMin=MYINF;
		
		//选出dest中dist最小的那个归入source中
		for(iter_d=dest.begin();iter_d!=dest.end();++iter_d)
		{
			if(curMin>dist[*iter_d])
			{
				curMin=dist[*iter_d];cur=*iter_d;
			}
		}

		source.insert(cur);
		dest.erase(cur);
		
		//加入一个新顶点之后开始更新dest中顶点的dist值，此处可以用最小堆优化
		for(iter_s=source.begin();iter_s!=source.end();++iter_s)
		{
			for(iter_d=dest.begin();iter_d!=dest.end();++iter_d)
			{
				if((g[*iter_s][*iter_d]+dist[*iter_s])<dist[*iter_d])
				{
					dist[*iter_d]=g[*iter_s][*iter_d]+dist[*iter_s];
					path[*iter_d]=*iter_s;
				}
			}	
		}
	}

	return path;
}

void show_path(vector<int> & path, int start, int end)
{
	vector<int>result;
	
	int cur=end;
	result.push_back(end);
	while(cur!=start)
	{
		result.push_back(path[cur]);
		cur=path[cur];
	}
	
	cout<<"The path is: ";
	for(int i=result.size()-1;i>=0;--i)
		cout<<result[i]<<" ";
	cout<<endl;
}	