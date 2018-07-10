/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

//Use this function , Dont create any new function with name createNode or createList
struct node * createNodeDummy(int num) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->num = num;
	newNode->next = NULL;
	return newNode;
}

struct node * insertAtEveryKthNode(struct node *head, int K) {
	if (head == NULL || K < 1)
	{
		return NULL;
	}
	else
	{
		struct node *temp,*temp1,*temp2;
		temp1 = (node*)malloc(sizeof(struct node));
		temp2 = (node*)malloc(sizeof(struct node));
		temp1 = head;
		temp = head;
		int count = 0,t,y;
		y = K;
		while (temp != NULL)
		{
			temp = temp->next;
			count++;
		}
		if (K > count)
		{
			return head;
		}
		temp1 = head;
		while (K<=count)
		{
			t = 0;
			temp1 = head;
			if (y == 1)
			{
				while (t < K - 1)
				{
					temp1 = temp1->next;
					t++;
				}
				if (temp1->next != NULL)
				{
					temp2 = temp1->next;
					temp1->next = createNodeDummy(y);
					temp1 = temp1->next;
					temp1->next = temp2;
					count++;
				}
				else
				{
					temp1->next = createNodeDummy(y);
					break;
				}
				K = K + 2;
			}
			else
			{
				while (t < K - 1)
				{
					temp1 = temp1->next;
					t++;
				}
				if (temp1->next != NULL)
				{
					temp2 = temp1->next;
					temp1->next = createNodeDummy(y);
					temp1 = temp1->next;
					temp1->next = temp2;
					count++;
				}
				else
				{
					temp1->next = createNodeDummy(y);
					break;
				}
				K = 2*K + 1;
			}
		}
		return head;
	}
}
