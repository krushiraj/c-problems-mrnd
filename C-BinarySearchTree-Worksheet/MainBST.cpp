/*
This Project will seem to be little tougher than before ones .But It can be done very easily
once you completed C-Recursion Project completely .

Note : You can use the functions specified as wrapper functions ,and write new functions 
which might take more parameters .

*/


#include <stdio.h>
#include <stdlib.h>
#include "FunctionHeadersBST.h"

struct node{
	struct node * left;
	int data;
	struct node *right;
};

struct node *newnode(int key)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct node * addnode(struct node *root, int data){
	if (root == NULL) return newnode(data);

	if (data < root->data)
		root->left = addnode(root->left, data);
	else if (data > root->data)
		root->right = addnode(root->right, data);
	return root;
}

void swap_nodes(struct node *a, struct node *b){
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}

int main()
{
	struct node *root = NULL;
	int nums[10] = { 2, 1,4,3 };
	int arr[10];
	for (int i = 0; i < 4; i++){
		root = addnode(root, nums[i]);
	}
	/*
	struct node *swaplist[2];
	int originaldata[2];
	swaplist[0] = root->left;
	swaplist[1] = root->right;
	originaldata[0] = swaplist[0]->data;
	originaldata[1] = swaplist[1]->data;

	swap_nodes(swaplist[0], swaplist[1]);
	
	inorder(root, arr);
	for (int i = 0; i < 3; i++)
		printf("%d", arr[i]);
	fix_bst(root);
	*/
	inorder(root, arr);
	for (int i = 0; i < 4; i++)
		printf("%d", arr[i]);
	int a = get_closest_leaf_distance(root, root->right);
	//Use it for testing ,Creating BST etc
}
