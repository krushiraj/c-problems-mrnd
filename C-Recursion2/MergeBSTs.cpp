/*
Given two Binary Search Trees ,Merge Both of them into a Single Binary Search Tree .
The Resultant Binary Search Tree will be BST1 .ie Merge all elements of BST2 into BST1.
	Example 1:

	Input :
	20        25
	/  \      /  \
	5    30   10   35
	Output :

	Bst 1 :
	20
	/   \
	5     30
	\   /  \
	10 25   35

BST 2 can be merged in BST1 sometimes in many number of ways ,
Any 1 of those correct ways would be fine .

Finally All elements of Both Trees should be in BST 1 .Dont process NULL Inputs
If an element of BST2 is already in BST 1, then BST2 node is ignored.

(Both r1 and r2 shouldnt be NULL at the time of Input)
Note : Dont Create Nodes using malloc,or Swap the data values or else your solution would receive 100%
cut in the marks you got for this question .
You need to solve this question only by changing links.
You will also receive Bonus marks for any better optimizations you make .
Difficulty : Medium -Hard

*/
#include <stdlib.h>
#include <stdio.h>

struct BstNode {
	int data;
	struct BstNode *left;
	struct BstNode *right;
};

void addNode(struct BstNode *root, struct BstNode *a)
{
	if (root->data == a->data)
	{
		return;
	}
	else if (root->data > a->data)
	{
		if (root->left == NULL)
		{
			root->left = a;
		}
		else
			return addNode(root->left,a);
	}
	else
	{
		if (root->right == NULL)
		{
			root->right = a;
		}
		else
			return addNode(root->right,a);
	}
}

void merge(struct BstNode *root1, struct BstNode *root2, struct BstNode *prev)
{
	if (root2 == NULL)
		return;
	merge(root1,root2->left,root2);
	merge(root1,root2->right,root2);
	if (prev == NULL)
	{
		addNode(root1,root2);
	}
	else if (prev->left != NULL)
	{
		if ((prev->left->data == root2->data))
		{
			prev->left = NULL;
			addNode(root1, root2);
		}
	}
	else if (prev->right != NULL)
	{
		if ((prev->right->data == root2->data))
		{
			prev->right = NULL;
			addNode(root1, root2);
		}
	}
}

void merge_two_bst(struct BstNode **root1, struct BstNode *root2) 
{
	if (*root1 == NULL)
	{
		*root1 = root2;
	}
	if (root2 == NULL)
	{
		return;
	}
	else
	{
		merge((*root1), root2, NULL);
	}
}