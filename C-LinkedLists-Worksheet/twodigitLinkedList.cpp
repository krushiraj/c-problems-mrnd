/*
OVERVIEW:  Given a single linked list (two digits as a node).Convert that to number


INPUTS:  SLL head pointer

OUTPUT: Create a number from the linked list given ,In each node there are two numbers ,digit1 and digit1 ,
So if the nodes are 12->34->56->78 , Final number would be 12345678 ( Integer)

ERROR CASES:

NOTES: Only Postive Numbers
*/

#include <stdio.h>
#include <malloc.h>
#include <math.h>

struct twoDigitNode {
	int digit1;
	int digit2;
	struct twoDigitNode *next;
};

int convert_sll_2digit_to_int(struct twoDigitNode *head){
	//struct twoDigitNode *temp = (twoDigitNode *)malloc(sizeof(struct twoDigitNode));
	struct twoDigitNode *temp;
	int arr[10],i=0,j=1,count=0,sum=0;
	//arr = (int *)malloc(10 * sizeof(int));
	temp = head;
	//int arr;
	while (temp != NULL)
	{
		arr[i] = temp->digit1;
		arr[j] = temp->digit2;
		temp = temp->next;
		i = i + 2;
		j = j + 2;
		count = count + 2;
	}
	i = 0;
	j = count;
	while (i < count)
	{
		sum = sum + arr[i] * (pow(10.0, j - 1));
		i++;
		j--;
	}
	return sum;
}
