/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};



void inorder1(struct node *root, int *arr, int   *i)
{
	if (root == NULL || arr == NULL)
		return;
	inorder1(root->left, arr, i);
	*(arr + *i) = root->data;
	*i = *i + 1;
	inorder1(root->right, arr, i);

}
void inorder(struct node *root, int *arr)
{
	if (root == NULL || arr == NULL)
		return;
	int x = 0;
	int*p = &x;
	inorder1(root, arr, p);
}
void preorder1(struct node *root, int *arr, int *p)
{
	if (root == NULL || arr == NULL)
		return;
	*(arr + *p) = root->data;
	*p = *p + 1;

	preorder1(root->left, arr, p);
	preorder1(root->right, arr, p);
}
void preorder(struct node *root, int *arr)
{
	if (root == NULL || arr == NULL)
		return;

	int x = 0;
	int*p = &x;

	preorder1(root, arr, p);
}
void postorder1(struct node *root, int *arr, int *i)
{
	if (root == NULL || arr == NULL)
		return;
	postorder1(root->left, arr, i);
	postorder1(root->right, arr, i);
	*(arr + *i) = root->data;
	*i = *i + 1;
}
void postorder(struct node *root, int *arr)
{
	if (root == NULL || arr == NULL)
		return;
	int x = 0;
	int*p = &x;
	postorder1(root, arr, p);

}
