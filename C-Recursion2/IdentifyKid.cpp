/*

Problem Code: IdentifyKid

There are three types of Guys,
'A' - Ambitious Boy 
'B' - Brilliant Boy
'C' - Creative Boy

The first generation guy is 'A'
each guy will have 3 kids 'A','B','C' , but the order will be different

'A' children will be  A ,B, C
'B' children will be  B ,C, A
'C' children will be  C ,A, B    ( rotations of “ABC”)


So basically , if it was represented in the form of a tree


1st  Generation -	                                   A
Index -                                                1
                                 /                     |                   \
2nd Generation -	            A                      B                    C
Index -			                1                      2                    3
                           /    |    \            /    |    \           /   |   \
3rd Generation -          A     B     C          B     C     A         C    A    B
Index-                    1     2     3          4     5     6         7    8     9

Given the N,K which represents the Nth generation and Kth index
You need to identify the type of the kid present there.

Note : If there is No Guy present there, return '\0'

*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

const char A[3] = {'A','B','C'};
const char B[3] = {'B','C','A'};
const char C[3] = {'C','A','B'};

int index;

char getChild(char ch, int i)
{
	switch (ch)
	{
	case 'A':
		return A[i];
	case 'B':
		return B[i];
	case 'C':
		return C[i];
	}
}

void identify(char a, int n, int k, char *c)
{
	if (((*c) != ' ') && (*c == 'A' || *c == 'B' || *c == 'C'))
		return;
	if (n - 1 == 0)
	{
		if (k - index <= 3)
		{
			*c = getChild(a, (k - index - 1));
			return;
		}
		else
		{
			index += 3;
		}
	}
	else
	{
		switch (a)
		{
		case 'A':
			identify('A', n-1, k, c);
			identify('B', n-1, k, c);
			identify('C', n-1, k, c);
			break;
		case 'B':
			identify('B', n - 1, k, c);
			identify('C', n - 1, k, c);
			identify('A', n - 1, k, c);
			break;
		case 'C':
			identify('C', n - 1, k, c);
			identify('A', n - 1, k, c);
			identify('B', n - 1, k, c);
			break;
		default:
			break;
		}
	}
}

char identifyKid(int N, int K)
{
	int k = K;
	int i = 0;
	while (k)
	{
		k /= 3;
		i++;
	}
	if (N < 1 || i > N)
		return '\0';
	index = 0;
	char ch = ' ';
	identify('A', N, K, &ch);
	return ch;
}