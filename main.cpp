#include "functions.h"

int main()
{
	int vert_num = 7;
	int** graph = new int*[vert_num];
	int** graphMin = new int*[vert_num];
	int** graphMinCopy = new int*[vert_num];
	string tmpS;
	string* result = new string[vert_num];
	
	for (int i = 0; i < vert_num; i++)
	{
		graph[i] = new int[vert_num];
		graphMin[i] = new int[vert_num];
		graphMinCopy[i] = new int[vert_num];
	}
	/*"занулим граф"*/
	for (int i = 0; i < vert_num; i++)
	{
		/*изначально компонент 7 и в каждой по 1 вершине*/
		for (int j = 0; j < vert_num; j++)
		{
			graph[i][j] = UNDEF_INT_MAX;
			graphMin[i][j] = UNDEF_INT_MAX;
			graphMinCopy[i][j] = UNDEF_INT_MAX;
		}
	}
	//А
	graph[0][1] = 7;
	graph[0][3] = 4;
	//B
	graph[1][0] = 7;
	graph[1][2] = 11;
	graph[1][3] = 9;
	graph[1][4] = 10;
	//C
	graph[2][1] = 11;
	graph[2][4] = 5;
	//D
	graph[3][0] = 4;
	graph[3][1] = 9;
	graph[3][4] = 15;
	graph[3][5] = 6;
	//E
	graph[4][1] = 10;
	graph[4][2] = 5;
	graph[4][3] = 15;
	graph[4][5] = 12;
	graph[4][6] = 8;
	//F
	graph[5][3] = 6;
	graph[5][4] = 12;
	graph[5][6] = 13;
	//G
	graph[6][4] = 8;
	graph[6][5] = 13;

	printMatrix(graph, vert_num);

	for (int i = 0; i < vert_num; i++)
	{
		minEdge my_minEdge;
		findMin(graph, vert_num, i, my_minEdge);
		graphMin[my_minEdge.min_i][my_minEdge.min_j] = my_minEdge.minW;
		graphMin[my_minEdge.min_j][my_minEdge.min_i] = my_minEdge.minW;
	}

	printMatrix(graphMin, vert_num);
	while (true)
	{

		
		/*graphMinCopy - текущий минимальный остов*/
		for (int i = 0; i < vert_num; i++)
		{
			for (int j = 0; j < vert_num; j++)
			{
				graphMinCopy[i][j] = graphMin[i][j];
			}
		}
		/*выделяем компоненты связонности*/
		for (int i = 0; i < vert_num; i++)
		{
			tmpS = "";
			makeComp(graphMin, vert_num, tmpS, i);
			result[i] += i;
			result[i] += tmpS;
		}
		/*удаляем те ребра, которые уже взяли*/
		for (int i = 0; i < vert_num; i++)
		{
			tmpS = result[i];
			for (int k = 0; k < tmpS.length(); k++)
			{
				for (int t = k; t < tmpS.length(); t++)
				{
					int tmpA = tmpS[k];
					int tmpB = tmpS[t];
					graph[tmpA][tmpB] = UNDEF_INT_MAX;
					graph[tmpB][tmpA] = UNDEF_INT_MAX;
				}

			}
		}

		/*Ищем минимальное ребро из оставшихся*/
		minEdge my_minEdge;
		for (int i = 0; i < vert_num; i++)
		{
			findMin(graph, vert_num, i, my_minEdge);
		}
		/*добавляем найденное ребро к минимальному графу*/
		for (int i = 0; i < vert_num; i++)
		{
			for (int j = 0; j < vert_num; j++)
			{
				graphMin[i][j] = graphMinCopy[i][j];
			}
		}
		graphMin[my_minEdge.min_i][my_minEdge.min_j] = my_minEdge.minW;
		graphMin[my_minEdge.min_j][my_minEdge.min_i] = my_minEdge.minW;

		//printMatrix(graphMin, vert_num);
		//printMatrix(graphMinCopy, vert_num);
		/*если получили компоненту связности, включающую все дерево - выходим*/
		for (int i = 0; i < vert_num; i++)
		{
			string tmp = result[i];
			if (tmp.length() >= vert_num)
			{
				printMatrix(graphMin, vert_num);
				return false;
			}
		}
	}
	return 0;
}