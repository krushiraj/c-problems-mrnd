/*

Problem Code : New York

Count the number of ways of reaching top left cell (0,0) to right bottom cell (n-1,m-1) of a 2d matrix.

You have to change the direction "exactly 'k' times", you can change to any direction top,down,left,right.

You can start with any direction (initially at (0,0) only right and down are possible).

For Example :
N = 3, m = 4 , k = 1
These are the two sequences , change in direction is indicated by *

(1,1) -->  (2,1) -->  (3,1) -->  (3,2)* -->  (3,3) --> (3,4)
(1,1) -->  (1,2) -->  (1,3) -->  (1,4) --> (2,4)* -->  (3,4)

N = 3, m = 4, k = 2

(1,1) --> (2,1) --> (2,2)* --> (2,3) -->  (2,4) -->  (3,4)*
(1,1) --> (1,2) -->  (2,2)* --> (3,2) -->  (3,3)* --> (3,4)
(1,1) --> (1,2) -->  (1,3) -->  (2,3)* -->  (3,3) -->  (3,4)*

Return 0 for invalid cases
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Returns count of paths to reach (i, j) from (0, 0)
// using at-most k turns. d is current direction
// d = 0 indicates along row, d = 1 indicates along
// column.
void newyork_recur(int n, int m, int x, int y, int k, int dir, int *paths)
{
	if ((x == n-1 && y == m-1))
	{
		if (k==0)
			(*paths)++;
		else return;
	}

	if (n < 0 || m < 0 || k<0)
		return;
	/*if (x == n - 1 && y == m - 1)
	{
		return;
	}*/
	if (dir == 0)
	{
		newyork_recur(n, m, x, y + 1, k - 1, 2, paths);
		newyork_recur(n, m, x + 1, y, k - 1, 3, paths);
	}
	if (dir == 1)
	{
		if (x - 1 >= 0)
			newyork_recur(n, m, x - 1, y, k, 1, paths);
		if (y + 1<m)
			newyork_recur(n, m, x, y + 1, k - 1, 2, paths);
		if (y - 1 >= 0)
			newyork_recur(n, m, x, y - 1, k - 1, 4, paths);
	}
	if (dir == 2)
	{
		if (x - 1 >= 0)
			newyork_recur(n, m, x - 1, y, k - 1, 1, paths);
		if (y + 1<m)
			newyork_recur(n, m, x, y + 1, k, 2, paths);
		if (x + 1<n)
			newyork_recur(n, m, x + 1, y, k - 1, 3, paths);
	}
	if (dir == 3)
	{
		if (x + 1<n)
			newyork_recur(n, m, x + 1, y, k, 3, paths);
		if (y + 1<m)
			newyork_recur(n, m, x, y + 1, k - 1, 2, paths);
		if (y - 1 >= 0)
			newyork_recur(n, m, x, y - 1, k - 1, 4, paths);
	}if (dir == 4)
	{
		if (x - 1 >= 0)
			newyork_recur(n, m, x - 1, y, k - 1, 1, paths);
		if (x + 1<n)
			newyork_recur(n, m, x + 1, y, k - 1, 3, paths);
		if (y - 1 >= 0)
			newyork_recur(n, m, x, y - 1, k, 4, paths);
	}
	return;
}

int NewYork(int n, int m, int k)
{
	int paths = 0;
	newyork_recur(n, m, 0, 0, k + 1, 0, &paths);
	return paths;
}
