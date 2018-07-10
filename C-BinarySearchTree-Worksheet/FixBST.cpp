/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};

void replace(struct node *m,struct node *n)
{
	int t;
	t = m->data;
	m->data = n->data;
	n->data = t;
	return;
}

void traverse_rec(struct node *root, struct node **first, struct node **middle, struct node **last, struct node **prev)
{
	if (root != NULL)
	{
		traverse_rec(root->left, first, middle, last, prev);
		if (*prev != NULL && root->data < (*prev)->data)
		{
			if (*first == NULL)
			{
				*first = *prev;
				*middle = root;
			}
			else
			{
				*last = root;
			}
		}
		*prev = root;
		traverse_rec(root->right, first, middle, last, prev);
	}
	return;
}

void fix_bst(struct node *root)
{
	if (root == NULL)
		return;
	struct node *first, *middle, *last, *prev;
	first = middle = last = prev = NULL;
	
	traverse_rec(root, &first, &middle, &last, &prev);
	if (first != NULL && last != NULL)
	{
		replace(first, last);
	}
	else if (first != NULL && middle != NULL)
	{
		replace(first, middle);
	}
	return;
}
