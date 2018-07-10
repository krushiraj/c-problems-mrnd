/*
PreRequiste : Copy compareInt,compareFloat,compareChar functions from previous files to here.
Function names are diff as we cant have 2 same functions with same name in same project.

Question :
Given a array of values, return the start and end indexes of max sub array (continuous)
(where all values in that subarray are equal).

Ie if 2,2,2,3,3,3,3,3,4,5,7,7 is passed return [3,7]; [As 3's sequence is longest]
Ie if 10.0,2.1,2.1,2.1,6.5,7.3,7.3 is passed return [1,3]; [As 2.1's sequence is longest]
Ie if 'x','a','a','a','a','z','m' is passed return [1,4]; [As a's sequence is longest].

Assume there will be only 1 max equal subsequence.

Use compare functions to know whether 2 values are equal or not.

Aim  of this lesson :
-> To understand how void * and function pointers go hand in hand. Understand the importance of
how void * can make power your functions to work with any datatype.
*/
#include <stdio.h>
#include <stdlib.h>

int compareInt2(void * a, void *b) {
	int *c = (int *)malloc(sizeof(int));
	int *d = (int *)malloc(sizeof(int));
	c = (int *)a;
	d = (int *)b;
	if ((*c)>(*d))
	{
		return 1;
	}
	else if ((*c) == (*d))
	{
		return 0;
	}
	else
	{
		return -1;
	}
	//Copy compareInt function from VoidPointers here.
}

int compareFloat2(void * a, void *b) {
	//Copy compareFloat2 function from VoidPointers here.
	float *c = (float *)malloc(sizeof(float));
	float *d = (float *)malloc(sizeof(float));
	c = (float *)a;
	d = (float *)b;
	if ((*c) > (*d))
	{
		return 1;
	}
	else if ((*c) == (*d))
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

int compareChar2(void * a, void *b) {
	//Copy compareChar2 function from VoidPointers here.
	char *c = (char *)malloc(sizeof(char));
	char *d = (char *)malloc(sizeof(char));
	c = (char *)a;
	d = (char *)b;
	if ((*c) > (*d))
	{
		return 1;
	}
	else if ((*c) == (*d))
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
values array where each void * points to an address of an int,float,char etc
length : length of values array
compare : compare method used to compare 2 values in values array
return indices array of start and end index of max equal sub array.
*/
int * max_equal_subarray(void ** values, int length, int(*compare)(void *, void *)) {
	int *out = (int *)malloc(2 * sizeof(int));
	for (int i = 0; i < 2; i++)
	{
		printf("hi\n");
		out[i] = 0;
	}
	int j;
	for (int i = 0; i < length; i++)
	{
		for (j = i + 1; j < length; j++)
		{
			if ((*compare)(values[i], values[j]) != 0)
			{
				break;
			}
		}
		j = j - 1;
		int p = out[0];
		int q = out[1];
		if ((q - p) < (j - i))
		{
			out[0] = i;
			out[1] = j;
		}

	}
	return out;
}

void test_max_subarray() 
{
	int arr[12] = { 2, 2, 2, 3, 3, 3, 3, 3, 4, 5, 7, 7 };
	void** intvalues = (void **)malloc(sizeof(void *) * 12);
	int i = 0;
	for (i = 0; i<12; i++)
	{
		intvalues[i] = (void *)&arr[i];
	}
	int * result = max_equal_subarray(intvalues, 12, &compareInt2);
	printf("Start index: %d,End Index : %d\n", result[0], result[1]);
}

