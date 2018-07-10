/*

Bharath is genius reverse engineer, invented a world demanding machine and Kept in a secret building with 
many doors with each door having a passkey.
A Pass key is made up of some digits. Like a passkey can be 1234, 452 etc.
All doors will have passkeys of same digits, (formed from each other). like if number of doors 
are 3, 1223,2132,2321 can be passkeys for those doors. 
(Where as 3321 cannot as 3 is repeated 2 times where as in above sequence its repeated only 1 time)

Sam is very excited to see his wonderful creation. So, she went to the building. She knows the final 
passkey of last door but dont know
what is the exact passkey for each before door. As said before there are many doors with lock in a 
linear fashion such that
she can cross second door only after crossing first door. she can cross third door only after crossing 
2nd door.

Lets say the final pass key she has is 758.
First door pass key is the largest number that can be formed by given final passkey -> 875
Second door pass key is the next largest number that can be formed -> 857
Third door opens for next largest number ->785
Finally fourth door has 758 as passkey and she can enter the room.

Find which Nth door's room contains the machine or How many doors should Sam cross to see the machine?

The final passkey Sam has will be given in the form of Doubly Linked List
eg: 7 <-> 5 <-> 8  o/p: 4

For the above Passkey ,output will be 4, as Sam needs to cross 4 doors which each door having below passkeys.
explanation: (1) 875 (2) 857 (3) 785 (4) 758

Ex 2 : 
If DLL has 9 <-> 1 <-> 4 <-> 6.
For the above Passkey ,output will be 4, as Sam needs to cross 6 doors which each door having below passkeys.
explanation: (1) 9641 (2) 9614 (3) 9461 (4) 9416 (5) 9164 (6) 9146

NOTE:	(1)	DLL can contain maximum of 12 nodes
(2)	All doors will have a Passkey which is formed by the numbers of the original pass key only
(3) From the first door to last, passkey will be in decreasing order.
(4) Duplicates are allowed
(5) "075" is not treated as "75". 0 is also given same importance as others.

You can solve this question in multiple ways. 
Can you solve it without converting to any intermediate forms or using extra space etc? These will be the 
common followup questions
that can be asked in an interview.

Return -1 for invalid cases.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct passKeyNode
{
	int num;
	struct passKeyNode *prev;
	struct passKeyNode *next;
};
int fact(int b)
{
	if (b == 0 || b == 1)
	{
		return 1;
	}
	else
	{
		int f=1,x;
		x = b;
		while (x > 0)
		{
			f = f*x;
			x--;
		}
		return f;
	}
}
int rank(int *a, int t)
{
	int i, j,res;
	int p[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int q[12] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	int y = 0;
		//p = (int *)malloc(t*sizeof(int));
		//q = (int *)malloc(t*sizeof(int));
		/*for (i = 0; i < t; i++)
		{
			p[i] = 0;
			i++;
		}
		i = 0;
		for (i = 0; i < t; i++)
		{
			q[i] = 1;
			i++;
		}*/
		for (i = 0; i < t; i++)
		{
			for (j = i + 1; j < t; j++)
			{
				if (a[i]<a[j])
				{
					p[i]++;
				}
				if (a[i] == a[j])
				{
					q[i]++;
				}
			}
		}
		j = t;
		for (i = 0; i < t; i++)
		{
			//y = y + p[i] * (fact(j - 1));
			if (q[i]==1)
			{ 
			y = y + p[i]*(fact(j - 1));
			}
			else
			{
				y = y + p[i] * (fact(j - 1) / fact(q[i]));
			}
			j--;
		}
		y = y + 1;
	return y;
}
int doorstoCross(struct passKeyNode *passKeyHead)
{
	if (passKeyHead == NULL)
	{
		return -1;
	}
	struct passKeyNode *temp;
	temp = passKeyHead;
	int *r,i=0,tempi,num=0,nums=0;
	r = (int *)malloc(12 * sizeof(int));
	while (temp != NULL)
	{
		r[i] = temp->num;
		i++;
		temp = temp->next;
	}
	r = (int *)realloc(r, sizeof(int)*(i));
	//int rank = rank(r);
	int ranko, ranks;
	ranko = rank(r,i);
	//ranks = rank(nums);
	int j, k;
	k = i;
	j = 0;
	while (j < i)
	{
		num = num + r[j] *pow(10.0,k-1);
		k--;
		j++;
	}
	for (j = 0; j < i; j++)
	{
		for (k = j + 1; k < i; k++)
		{
			if (r[k]>r[j])
			{
				tempi = r[k];
				r[k] = r[j];
				r[j] = tempi;
			}
		}
	}
	//ranks = rank(r,i);
	k = i;
	j = 0;
	while (j < i)
	{
		nums = nums + r[j] * pow(10.0, k - 1);
		k--;
		j++;
	}
	if (num == nums)
	{
		return 1;
	}
	else
	{
		return ranko;
	}
}