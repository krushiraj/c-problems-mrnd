/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
int height(struct node *root)
{
	if (root == NULL)
		return 0;
	int l = 0, r = 0;
	l = height(root->left);
	r = height(root->right);
	if (l > r)
		return l + 1;
	else
		return r + 1;

}
void print(struct node* root, int h, int *a, int *i)
{
	if (h < 0||root==NULL)
		return;
	if (h == 0)
	{
		*(a + *i) = root->data;
		*i = *i + 1;
		return;
	}
	print(root->right, h - 1, a, i);
	print(root->left, h - 1, a, i);
	
		


}

int* decide(struct node* root, int i)
{
	int *arr = (int *)malloc(20 * sizeof(arr));
	int *k;
	int a = 0;
	k = &a;
	int h = height(root);
	for (int j = 0; j < h; j++)
	{
		print(root, j, arr,k);
	}
	return arr;

}

int* BSTRighttoLeftRows(struct node* root)
{ if (root==NULL)
    return NULL;
return decide(root, 0);
}
