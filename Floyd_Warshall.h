#ifndef _FLOYD_WARSHALL_
#define _FLOYD_WARSHALL_
#include "graph.h"

using namespace std;

void Floyd_Warshall(Graph_Matrix & g,Graph_Matrix &path,Graph_Matrix &dp);
void Floyd_Warshall_Path(Graph_Matrix &path, int start, int end);

#endif