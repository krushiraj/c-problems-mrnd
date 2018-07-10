/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes
will be followed by ones and then twos.

You should only change the links and shouldnt swap the data. Basically no write operation should be done on data field.

INPUTS:  SLL head pointer
OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2
ERROR CASES:
NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

/*
Optional : For this function swapping data is allowed.Although this wont be tested on our end.
It is only for learning purpose.
*/
void sll_012_sort_swapData(struct node **head){

}

/*
This is the actual function. You are supposed to change only the links.
*/
//struct node * myhead;
void sll_012_sort(struct node **head){
	node* last = *head;
	int numOfNodes = 1;
	while (last->next != NULL)
	{
		last = last->next;
		numOfNodes++;
	}
	node *tail = last;
	node *ptr = *head;
	node *prev = *head;
	for (int i = 0; i<numOfNodes; i++)
	{
		node* temp = ptr;
		ptr = ptr->next;
		if (temp->data == 0)
		{
			if (prev != temp)
			{
				temp->next = *head;
				*head = temp;
				prev->next = ptr;
			}
		}
		else if (temp->data == 2)
		{
			tail->next = temp;
			temp->next = NULL;
			tail = temp;
			if (prev == temp)
				*head = prev = ptr;
			else
				prev->next = ptr;
		}
		else
		{
			if (prev != temp)
				prev = prev->next;
		}
	}
}

	/*node *temp = (node *)malloc(sizeof(struct node));
	node *prev = (node *)malloc(sizeof(struct node));
	temp = *head;
	int i = 0;
	temp = *head;
	while (temp != NULL)
	{
		if (temp->data == 0)
		{
			node *temp1 = (node *)malloc(sizeof(struct node));
			temp1 = *head;
			prev = *head;
			while (1)
			{
				if (*head == temp)
				{
					*head = temp->next;
					break;
				}
				if (prev->next == temp)
				{
					prev->next = temp->next;
					break;
				}
				prev = prev->next;
			}
			*head = temp;
			temp->next = temp1;
		}
		else if (temp->data == 2)
		{
			node *temp2 = (node *)malloc(sizeof(struct node));
			temp2 = *head;
			prev = *head;
			while (temp2->next != NULL)
			{
				temp2 = temp2->next;
			}
			while (1)
			{
				if (*head == temp)
				{
					*head = temp->next;
					break;
				}
				if (prev->next == temp)
				{
					prev->next = temp->next;
					break;
				}
				prev = prev->next;

			}
			temp->next = NULL;
			temp2->next = temp;

		}
		temp = temp->next;
	}
}*/
	/*int min;
	node *temp = (node *)malloc(sizeof(struct node));
	node *temp1 = (node *)malloc(sizeof(struct node));
	temp->next = *head;
	temp1->next = temp->next;
	while (temp->next != NULL)
	{
		while (temp1->next != NULL)
		{
			
		}
	}
	//myhead = *head;
	return;*/


