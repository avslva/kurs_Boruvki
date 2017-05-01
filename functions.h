#include <iostream>
#include <string>

using namespace std;

#define UNDEF_INT_MAX			(2147483647)

struct minEdge
{
	int minW, min_i, min_j;
	minEdge(): minW(UNDEF_INT_MAX), min_i(0), min_j(0) {}
	minEdge(int minW, int min_i, int min_j): minW(minW), min_i(min_i), min_j(min_j) {}
};

void printMatrix(int** graph, int vert_num);
void makeComp(int** graph, int vert_num, string &str, int point);
void findMin(int** graph, int vert_num, int i, minEdge &my_minEdge);