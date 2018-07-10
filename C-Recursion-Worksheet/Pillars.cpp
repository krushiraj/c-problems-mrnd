/*
Some where in MissionRnD world ,there is a large plot of empty Rectangular land ,divided into Blocks of
equal size . A Land of N Blocks at length and M Blocks at Breadth will have total of N x M Blocks .

Each Block has a pillar of Height H .[0 <= H <=100000] .A Pillar is said to be a Leader if there are no more
neighbouring pillars (East ,West ,Noth and South) whose height is greater than current one .
And excatly opposite ,A pillar is said to be a Looser if there are no more neighbouring pillars
whose height is less than the current pillar height

If a block has 0 specified ,It has No pillar and No person can be on that block.In the below example
1,2,4... are heights of pillars at that block.Do not consider 0 while calculating Leaders or Loosers .
Example :

1 2 0 1 0
0 0 0 9 0
0 0 0 8 0
0 1 4 6 5
0 0 2 3 4

Here a[0][1] ie 2 ,and a[1][3] ie 9 are leaders ,as all their neighbouring elements are less or equal than it .
Here a[0][0] ie 1 ,and a[0][3] ie 1 and a[3][1] ie 1 and a[4][2] ie 2 are Loose Pillars ,as all their
neighbouring pillars height are greater or equal than it .

Now there is a child who likes to jump from one pillar to another ,He starts at a looser Pillar and jumps to
a nearby pillar (4 Directions) ,if the nearby pillar height is "strictly greater" than curernt pillar height .
So he can jump from 1 to 3 ,or 3 to 7 but not 4 to 1 and 5 to 5 .[all these are heights]
He continues jumping until he reaches a LeaderPillar .

As he likes jumping ,He would like to know the Path which starts at a Looser Pillar and ends at a Leader Pillar
that involves maximum jumps ,Can you help the child solve his Task ?

In the above example :
1-2 Path , requires only 1 jump
1-4-6-8-9 requires 4 jumps
2-3-4-5-6-8-9 requires 6 jumps
1-9 requires only 1 jump.
So in the above example you need to return [2,3,4,5,6,8,9] and copy 6 in jumps_count

Input :
A 2D Array (passed as Single pointer,First element Address) ,N (number of Cols), M(number of rows),
jumps_count (Pointer to an Integer)
Output :
Return the Max Jumps path  ,and copy number of max jumps into jumps_count .

Constraints :
0<=N<=10000
0<=M<=10000
Note : If there is no such path ,Copy 0 in jumps_count and return NULL,(Same for Invalid Inputs too)
Examples :
-----
2 1 7
3 0 4   ->Max Path : [1,2,3,5,6] ,jumps_count =4 [Here both 4's are looser elements]
5 6 4
--------
5 8 9 10
4 3 1 0
3 0 0 3   ->Max Path is [1,2,3,4,5,8,9,10] , jumps_count =8
2 1 1 1
---------
0 0 0
0 4 0  ->Max Path is [4] ,jumps_count=0;
0 0 0
Note : There will be only One Maximum Jumps path .[If there are multiple ,Return any 1 path]
*/
#include <stdlib.h>
#include <stdio.h>
int *res;
void cpy(int *src, int * res, int ic)
{
	for (int i = 0; i <= ic; i++)
	{
		res[i] = src[i];
	}
}
bool islosser(int **arr, int i, int j, int m, int n)
{
	if (arr[i][j] == 0)return false;
	if (i >= 0 && j >= 1 && arr[i][j - 1] != 0 && arr[i][j - 1] < arr[i][j])return false;
	if (i >= 1 && j >= 0 && arr[i - 1][j] != 0 && arr[i - 1][j] < arr[i][j])return false;
	if (j + 1 < n&&i < m&&arr[i][j + 1] != 0 && arr[i][j + 1] < arr[i][j])return false;
	if (j < n&&i + 1 < m&&arr[i + 1][j] != 0 && arr[i + 1][j] < arr[i][j])return false;
	return true;
}
bool isleader(int **arr, int i, int j, int m, int n)
{
	if (i >= 0 && j >= 1 && arr[i][j - 1] > arr[i][j])return false;
	if (i >= 1 && j >= 0 && arr[i - 1][j] > arr[i][j])return false;
	if (j + 1 < n&&i<m&&arr[i][j + 1]>arr[i][j])return false;
	if (j < n&&i + 1 <m&&arr[i + 1][j]>arr[i][j])return false;
	return true;
}
int *findpath(int **arr, int i, int j, int *out, int m, int n, int ic, int *l)
{
	if (isleader(arr, i, j, m, n))
	{
		if (ic > *l)
		{
			*l = ic;
			out[ic] = arr[i][j];
			//free(res);
			cpy(out, res, ic);
		}
		return out;
	}
	else
	{
		//down
		if (j <n&&i + 1 < m&&arr[i + 1][j] > arr[i][j])
		{
			out[ic] = arr[i][j];
			out = findpath(arr, i + 1, j, out, m, n, ic + 1, l);
		}
		//right
		if (j + 1 < n&&i<m&&arr[i][j + 1]>arr[i][j])
		{
			out[ic] = arr[i][j];
			out = findpath(arr, i, j + 1, out, m, n, ic + 1, l);
		}
		//up
		if (i >= 0 && j >= 1 && arr[i][j - 1] > arr[i][j])
		{
			out[ic] = arr[i][j];
			out = findpath(arr, i, j - 1, out, m, n, ic + 1, l);
		}
		//left
		if (i >= 1 && j >= 0 && arr[i - 1][j] > arr[i][j])
		{
			out[ic] = arr[i][j];
			out = findpath(arr, i - 1, j, out, m, n, ic + 1, l);
		}
		return out;
	}
}

int * pillars_max_jumps(int *blocks, int n, int m, int *jumps_count)
{
	if (blocks == NULL)return NULL;
	int c = 0;
	int **arr;
	arr = (int **)malloc(m*sizeof(int*));
	for (int i = 0; i < m; i++){
		arr[i] = (int*)malloc(n*sizeof(int));
	}
	int k = 0;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			arr[i][j] = blocks[k];
			k++;
		}
	}
	int ic;
	int lev = 0;
	int lc = 0;
	int *out = (int *)calloc(m* n,sizeof(int));
	free(res);
	res = (int *)calloc(m*n, sizeof(int));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ic = 0;
			if (islosser(arr, i, j, m, n))
			{
				out = findpath(arr, i, j, out, m, n, ic, &lev);
			}
		}
	}
	//realloc(res,lev);
	*jumps_count = lev;
	if (lev == 0)return NULL;
	return res;
}