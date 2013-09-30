#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <set>

#define THRE 100
#define   MYINF (INT_MAX-100)

using namespace std;
void create_an_graph_from_stdin(vector<vector<int>> &g,int vNum);
void show_graph(vector<vector<int> > &g,int vNum);


//单源最短路径--Dijkstra

void show_path(vector<int> & path, int start, int end);

vector<int> Dijkstra(vector<vector<int> > &g, int vNum,int start);
