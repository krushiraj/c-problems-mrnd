/*
Problem Code : ISDIVSLL

You are Given an SLL where each Node has a character (which is picked from digits or '-'/'+') and a Key integer .
Example SLL : '1' -> '2' -> '3' -> '4'

You need to return 1 if the sum of numbers formed by (the SLL and reverse SLL) is divisible by key ,Return 0 otherwise . Return -1 for invalid cases  .

Sample Input :
SLL: '+'->'1'->'3'->'6'; (which is 136) and Key is 59 .

Sample Output :
1

If Key is 67 in the above example ,You should return 0 .

Explanation :
SLL is 136 , Reverse SLL is 631 . Sum is 631+136 = > 767 . 767 is divisible by 59 , So you should return 1 .

Constraints :

->Characters Range will be in from the following string "+-0123456789" .
->Length of SLL will be less than 10Nodes .
->0<=Key<=10000000
->First char need not defenetly be a sign , if its a digit ,it is considered as a positive number .

Note : Reverse of a negetive SLL is negetive only .And -963 can be divided by 3 .
*/

#include <stddef.h>
#include <malloc.h>
#include <stdio.h>
#include <math.h>

struct charNode{
	char letter;
	struct charNode *next;
};

int isDivisibleSLL(struct charNode * head, int key){
	int arr[10], count = 0,sign=1,i=0,sum=0,sumr=0;
	struct charNode*temp = (charNode*)malloc(sizeof(struct charNode));
	if (key == 0||head==NULL)
	{
		return -1;
	}
	else
	{
		temp = head;
		while (temp != NULL)
		{
			if (temp->letter == '+' || temp->letter == '-' || ((temp->letter >= '0') && (temp->letter <= '9')))
			{
				if (temp->letter == '-')
				{
					sign = -1;
				}
				else if (temp->letter == '+')
				{
					sign = 1;
				}
				else if (((temp->letter >= '0') && (temp->letter <= '9')))
				{
					arr[i] = temp->letter - 48;
					i++;
				}
				temp = temp->next;
			}
			else
			{
				return -1;
			}
		}
		count = i;
		i = 0;
		int j = count;
		while (i < count)
		{
			sum = sum + arr[i] * pow(10.0, j - 1);
			i++;
			j--;
		}
		i = count - 1;
		j = count;
		while (i >= 0)
		{
			sumr = sumr + arr[i] * pow(10.0, j - 1);
			i--;
			j--;
		}
		if (sign == -1)
		{
			sum = -sum;
			sumr = -sumr;
		}
		if ((sum + sumr) % key == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

