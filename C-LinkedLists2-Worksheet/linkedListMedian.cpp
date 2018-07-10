/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	int count = 0,mid,i;
	struct node *temp = (node*)malloc(sizeof(struct node));
	temp = head;
	if (head == NULL)
	{
		return -1;
	}
	else
	{
		while (temp != NULL)
		{
			temp = temp->next;
			count++;
		}
		if (count % 2 == 0)
		{
			mid = count / 2;
			temp = head;
			i = 0;
			while (i < mid-1)
			{
				i++;
				temp = temp->next;
			}
			struct node *temp1 = (node*)malloc(sizeof(struct node));
			temp1 = temp;
			temp1 = temp1->next;
			mid = (temp->num + temp1->num) / 2;
				return mid;
		}
		else
		{
			mid = count / 2;
			mid = mid + 1;
			temp = head;
			i = 0;
			while (i < mid-1)
			{
				i++;
				temp = temp->next;
			}
			mid = temp->num;
			return mid;
		}
	}
}
