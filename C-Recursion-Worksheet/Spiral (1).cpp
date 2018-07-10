/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>
/*int *a = (int *)calloc(30, sizeof(int));
int i = 0;
int* show(int rows, int columns,int r1,int c1, int **input_array,int x,int d)
{ 
	
	if (rows == r1&&columns == c1)
	{
		return a;
	}

	if (d == 2)
	{
		for (int k = c1; k < columns; k++)
		{
			a[i] = input_array[x][k]; i++;
		}
		return show(rows, columns, r1 + 1, c1, input_array, columns - 1, 3);
	}
	if (d == 3)
	{
		for (int k = r1; k < rows; k++)
		{
			a[i] = input_array[k][x]; i++;
		}
		return show(rows, columns - 1, r1, c1, input_array, rows - 1, 4);
	}
	if (d == 4)
	{
		for (int k = columns - 1; k >= c1; k--)
		{
			a[i] = input_array[x][k]; i++;
		}
		return show(rows - 1, columns, r1, c1, input_array, c1, 1);
	}
	if (d == 1)
	{
		for (int k = rows - 1; k >= r1; k--)
		{
			a[i] = input_array[k][x];
			i++;
		}
		return show(rows, columns, r1, c1 + 1, input_array, r1, 2);
	}



}
*/
int *spiral(int rows, int columns, int **input_array)
{
	//return show(rows,columns,rows,columns,input_array,0,2);
	return 0;
}
