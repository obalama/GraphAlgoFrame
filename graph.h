#ifndef _GRAPH_
#define _GRAPH_
#include "adjlist.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <set>

#define THRE 100
#define   MYINF (INT_MAX-100)

#define Graph_Matrix vector<vector<int> >

using namespace std;
void create_an_graph_from_stdin(vector<vector<int>> &g,int vNum);
void show_graph(vector<vector<int> > &g,int vNum);


//单源最短路径--Dijkstra

void show_path(vector<int> & path, int start, int end);

vector<int> Dijkstra(vector<vector<int> > &g, int vNum,int start);


//Bellman-Ford算法
/*算法核心：
	第i轮循环找到经过至多i条边的最短路径
*/
#endif
