/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K) {
	int i, len = 1;
	struct node *temp = (node*)malloc(sizeof(struct node));
	struct node *prev = (node*)malloc(sizeof(struct node));
	if (head == NULL || K <= 1)
	{
		return NULL;
	}
	else
	{
		temp = head;
		prev = temp;
		while (temp != NULL)
		{
			if ((temp->num)%K == 0)
			{
				prev->next = temp->next;
				free (temp);
				
			}
			prev = temp;
			temp = temp->next;
		}
		return head;
	}
	
}