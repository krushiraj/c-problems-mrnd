/*
Author : Abhijith Ravuri
*/

#include "stdafx.h"
#include <stdlib.h>

#include "FunctionHeaders.h"

void generate_array(int **input_array, int rows, int columns, int seq)
{
	int k = 0;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			input_array[i][j] = (k++)*seq;
}

int main(){
	
	//Check NSnipers

	//Check CountPairs Sample Code 

	//Check Steps Sample Code

	//Check Spiral Sample Code

	//Check Maze Sample Code

	/*
	int maze[4][3] = {
		{ 0, 0, 1 },
		{ 1, 1, 1 },
		{ 1, 0, 1 },
		{ 1, 0, 1 }
	};

	int m = 4, n = 3;
	int x1 = 3, y1 = 0, x2 = 0, y2 = 2;

	int check=path_exists(&maze[0][0], m, n, x1, y1, x2, y2);
	printf("%d\n", check);
	*/

	int rows = 10, columns = 1;

	int **input_array = (int **)malloc(rows * sizeof(int *));

	for (int i = 0; i < rows; i++)
		input_array[i] = (int *)malloc(columns * sizeof(int));

	generate_array((int**)input_array, rows, columns, -12);

	const int n = 10, m = 9;
	int blocks[m][n] = {
		{ 0, 0, 0, 0, 0, 0, 0, 1, 2, 0 },
		{ 0, 0, 3, 5, 10, 11, 12, 0, 3, 0 },
		{ 0, 0, 0, 0, 0, 14, 13, 0, 4, 0 },
		{ 0, 0, 0, 0, 0, 15, 0, 50, 5, 0 },
		{ 0, 0, 50, 0, 0, 16, 17, 40, 6, 0 },
		{ 0, 0, 40, 0, 0, 0, 18, 30, 7, 0 },
		{ 7, 0, 30, 7, 7, 0, 19, 20, 8, 0 },
		{ 7, 0, 0, 0, 7, 0, 0, 10, 9, 0 },
		{ 7, 7, 7, 7, 7, 0, 0, 0, 0, 0 }, };
	int jumps = 0;
	int *route = pillars_max_jumps(&blocks[0][0], n, m, &jumps);
	printf("-%d-",jumps);
	for (int i = 0; i <= jumps; i++)
	{
		printf("%d ",route[i]);
	}
	return 0;
}