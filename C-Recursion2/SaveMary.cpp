/*

	Raju bhai is a new don in town. He enjoys hanging people every weekend.
	This weekend he assembled N people in a circular manner (1,2,..N,1) and choosen a random integer K. 
	He framed certain rules to hang people.
	
	Rule 1: He skips K-1 persons (inclusive) and hang Kth person.
	Rule 2: He always starts counting from 1st person.
	Rule 3: The last person will be allowed to live for rest of his life.
	
	Sample Case:
		Given N=5, K=2
			Initial state: 1,2,3,4,5
		Step 1: skips 1 and hangs 2
			1,3,4,5
		Step 2: Now skips 3 and hangs 4
			1,3,5
		Step 3: Now skips 5 and hangs 1
			3,5
		Step 4: Now skips 3 and hangs 5
			3
		As 3 is only person, he lets him live.

	Save our friend Mary by choosing correct position in the initial circle.
	You have to return the integer x, such that if mary is positioned at x in [1..N] she
	will not be killed, if no such position exists, return -1
	Fill the below function with code and return the postion.
	Return -1 for error cases
*/
#include<stdio.h>
#include<stdlib.h>

struct Node *last = NULL;

struct Node
{
	int data;
	struct Node *next;
};

struct Node *addToEmpty(struct Node *last, int data)
{
	// This function is only for empty list
	if (last != NULL)
		return last;

	// Creating a node dynamically.
	struct Node *temp =
		(struct Node*)malloc(sizeof(struct Node));

	// Assigning the data.
	temp->data = data;
	last = temp;

	// Creating the link.
	last->next = last;

	return last;
}

struct Node *addEnd(struct Node *last, int data)
{
	if (last == NULL)
		return addToEmpty(last, data);

	struct Node *temp =
		(struct Node *)malloc(sizeof(struct Node));

	temp->data = data;
	temp->next = last->next;
	last->next = temp;
	last = temp;

	return last;
}


int savemary(struct Node *head,struct Node *prev,int k)
{
	if (head == prev)
	{
		return head->data;
	}
	else
	{
		int i = 0;
		struct Node *temp = head;
		while (i < k - 1)
		{
			//delete curret node
			temp = temp->next;
			prev = prev->next;
			i++;
		}
		head = temp->next;
		prev->next = temp->next;
		temp->next = NULL;
		free(temp);
		//kth position is saved so kill from next
		return savemary(head,prev,k);
	}
}

struct Node* generate_cll(int n)
{
	last = NULL;
	for (int i = 0; i < n; i++)
	{
		last = addEnd(last,i+1);
	}
	return last;
}

int saveMary(int n, int k)
{
	if (n < 1 && k < 1)
		return -1;
	last = generate_cll(n);
	return savemary(last->next,last,k);
}
