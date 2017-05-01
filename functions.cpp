#include "functions.h"


void printMatrix(int** graph, int vert_num)
{
	for (int i = 0; i < vert_num; i++)
	{
		for (int j = 0; j < vert_num; j++)
		{
			/*если нет ребра*/
			if (UNDEF_INT_MAX == graph[i][j])
			{
				cout << "0" << "	";
			}
			else
			{
				cout << graph[i][j] << "	";
			}
		}
		cout << endl;
	}

	cout << endl;
	cout << endl;
}

void makeComp(int** graph, int vert_num, string &str, int point)
{
	for (int i = 0; i < vert_num; i++)
	{
		if (graph[point][i] < UNDEF_INT_MAX)
		{
			str += i;
			graph[point][i] = UNDEF_INT_MAX;
			graph[i][point] = UNDEF_INT_MAX;
			makeComp(graph, vert_num, str, i);
		}
	}
}
	/*выделяем компоненты связонности*/
	/*	for (int i = 0; i < vert_num; i++)
		{
			for (int j = 0; j < vert_num; j++)
			{
				graphMinCopy[i][j] = graphMin[i][j];
			}
		}
		for (int i = 0; i < vert_num; i++)
		{
			tmpS = "";
			makeComp(graphMin, vert_num, tmpS, i);
			result[i] += i;
			result[i] += tmpS;
		}*/

void findMin(int** graph, int vert_num, int i, minEdge &my_minEdge)
{
	for (int j = 0; j < vert_num; j++)
	{
		if (graph[i][j] < my_minEdge.minW)
		{
			my_minEdge.minW = graph[i][j];
			my_minEdge.min_i = i;
			my_minEdge.min_j = j;
		}
	}
}

