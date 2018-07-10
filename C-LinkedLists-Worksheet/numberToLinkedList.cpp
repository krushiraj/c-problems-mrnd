/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES:

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};
 struct node* first;
 void insert(int x)
 {
	 node *temp1 = ( node *)malloc(sizeof(struct node));
	 temp1->num = x;
	 temp1->next = first;
	 first = temp1;

 }
struct node * numberToLinkedList(int N) {
	first = NULL;
	int num1,y;
	  node *temp=( node *)malloc(sizeof(struct node));
	num1 = N;
	if (N < 0)
	{
		num1 = -N;
	}
	if (N != 0)
	{
		while (num1 != 0)
		{
			y = num1 % 10;
			num1 = num1 / 10;
			insert(y);
		}
	}
	else
	{
		temp->num = 0;
		temp->next = NULL;
		first = temp;
	}
	return first;
}