/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {
	if (head == NULL)
	{
		return NULL;
	}
	else
	{
		struct node *temp;
		struct node*prev;
		struct node* next1;
		//next1 = head;
		temp = head;
		prev = NULL;
		while (temp != NULL)
		{
			
			next1 = temp->next;
			temp->next = prev;
			prev = temp;
			temp = next1;
		}
		head = prev;
		return head;
	}
}

