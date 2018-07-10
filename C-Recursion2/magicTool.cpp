/*

	Given a matrix nxn and a starting point (p,q), 
	Output all the points in the matrix which are identical to the starting point in the fashion similar to magic tool in Adobe photoshop.
	Eg:
	(p,q) : (0,3)
	1 2 3 3
	3 2 3 3
	5 3 3 3
	4 5 1 4
	o/p : [ (0,2) (0,3) (1,2) (1,3) (2,2) (2,3) (2,1) ]

	Use 2 structures provided to solve the problem.
	
	struct point -> contains x, y corresponding to point on matrix.
	struct result -> contains 3 fields
						1. selected -> contains all the final points after the selecting process.
						2. size -> number of the selected points.
						3. visited -> utility variable to note the visited points on matrix during recursion.
	
	In error cases return a emply structures
		size = 0;
		selected = {};
		visited = {};

NOTE : Donot use any Global Variables
*/
#include<stdio.h>
#include <malloc.h>

struct Point 
{
	int x;
	int y;
};


struct result 
{
	Point* selected;
	bool *visited;
	int size;
};


void select(char **pixels, int m, int n, struct Point pivot, result* res, struct Point current) 
{
	// feel free to change this function parameters
	int i = current.x, j = current.y;
	int x = pivot.x, y = pivot.y;
	//check if already visited
	if (res->visited[((i*m) + j)] == true)
	{
		return;
	}

	if (pixels[x][y] == pixels[i][j])
	{
		res->visited[((i*m) + j)] = true;
		res->selected[(res->size)++] = current;
	}
	else
	{
		res->visited[((i*m) + j)] = false;
		return;
	}
	//left
	if (j > 0)
	{
		select(pixels, m, n, pivot, res, { i, j - 1 });
	}
	//top
	if (i > 0)
	{
		select(pixels, m, n, pivot, res, { i - 1, j });
	}
	//right
	if (j < n-1)
	{
		select(pixels, m, n, pivot, res, { i, j + 1 });
	}
	//bottom
	if (i < m-1)
	{
		select(pixels, m, n, pivot, res, { i + 1, j });
	}
}

struct result select_wrapper(char* pixels, int m, int n, struct Point pivot) 
{
	//invalid check
	if (pixels == NULL || pivot.x > m || pivot.y > n || pivot.x < 0 || pivot.y < 0)
		return { {}, {}, 0 };
	m++;
	n++;
	result res;
	Point current = pivot;
	res.size = 0;
	res.selected = (Point *)calloc(m*n,sizeof(Point));
	res.visited = (bool*)calloc(m*n,sizeof(bool));
	//res.visited = {false};
	//creating and copying array to a 2d array
	char **_pixels = (char **)calloc(m, sizeof(char*));
	for (int i = 0; i < m; i++)
	{
		_pixels[i] = (char *)calloc(n,sizeof(char));

	}
	int k = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++,k++)
		{
			_pixels[i][j] = pixels[k];
		}
	}
	//end of copy
	select(_pixels, m, n, pivot, &res, current);
	//res.selected = (Point *)realloc(res.selected, res.size);
	return res;
}
