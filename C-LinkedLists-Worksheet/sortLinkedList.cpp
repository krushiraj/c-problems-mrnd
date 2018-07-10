/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.

*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
};

struct node * sortLinkedList(struct node *head) {
	if (head == NULL)
	{
		return NULL;
	}
	int temp;
	struct node* temp1 = (node *)malloc(sizeof(struct node));
	struct node* temp2 = (node *)malloc(sizeof(struct node));
	temp1 = head;
	if (temp1->next == NULL)
	{
		return head;
	}
	else
	{
		while (temp1 != NULL)
		{
			temp2 = temp1->next;
			while (temp2 != NULL)
			{
				if (temp2->num < temp1->num)
				{
					temp = temp1->num;
					temp1->num = temp2->num;
					temp2->num = temp;
				}
				temp2 = temp2->next;
			}
			temp1 = temp1->next;
		}
		return head;
	}
}