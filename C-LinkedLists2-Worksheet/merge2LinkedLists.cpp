/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>
struct node {
	int num;
	struct node *next;
};
struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	struct node* result = NULL;
	if (head1 == NULL && head2 == NULL)
	{
		return NULL;
	}
	if (head1 == NULL&&head2 != NULL)
	{
		return head2;
	}
	if (head1 != NULL&&head2 == NULL)
	{
		return head1;
	}
	if (head1->num <= head2->num)
	{
		result = head1;
		result->next = merge2LinkedLists(head1->next, head2);
	}
	else
	{
		result = head2;
		result->next = merge2LinkedLists(head1, head2->next);
	}
	return(result);
	/*struct node *temp1 = (node*)malloc(sizeof(struct node));
	struct node *temp2 = (node*)malloc(sizeof(struct node));
	struct node*temp;
		//= (node*)malloc(sizeof(struct node));
	//temp = NULL;
	temp1 = head1;
	temp2 = head2;
	while (temp1 != NULL || temp2 != NULL)
	{
		if (temp1->num < temp2->num)
		{
			temp = temp1;
			temp1 = temp1->next;
			temp = temp->next;
		}
		else if (temp1->num>temp2->num)
		{
			temp = temp2;
			temp2 = temp2->next;
			temp = temp->next;
		}
		else if (temp1->num == temp2->num)
		{
			temp = temp1;
			temp1 = temp1->next;
			temp = temp->next;
			temp = temp2;
			temp2 = temp2->next;
			temp = temp->next;
		}
	}
	while (temp1 != NULL)
	{
		temp->next = temp1;
		temp1 = temp1->next;
		temp = temp->next;
	}
	while (temp2 != NULL)
	{
		temp->next = temp2;
		temp2 = temp2->next;
		temp = temp->next;
	}
	return temp;*/
}
