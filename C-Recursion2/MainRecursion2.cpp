/*
Mock Test 1
Make Sure you submit well before time .
And dont repeteadtly submit ,as it will cause sync issues , Try to submit alteast with
5-10mins gap between each submit .
Make sure your files are uploaded to GoogleDrive before Time Expires.

95% of times ,The last minute Code changes wont fetch you any more marks .It might even
decrease or become 0 , If it leads to a Project Build Failure .
*/
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>
#include "FunctionHeadersRecursion2.h"

struct BstNode
{
	int data;
	struct BstNode *left;
	struct BstNode *right;
};

struct BstNode *newNode_mergeBST(int key){
	struct BstNode *temp = (struct BstNode *)malloc(sizeof(struct BstNode));
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct BstNode * insertNode_mergeBST(struct BstNode *root, int data) {
	if (root == NULL) return newNode_mergeBST(data);
	if (data < root->data)
		root->left = insertNode_mergeBST(root->left, data);
	else if (data > root->data)
		root->right = insertNode_mergeBST(root->right, data);
	return root;
}

struct BstNode * create_BST(int *arr, int len) {
	struct BstNode *root = NULL;
	for (int i = 0; i < len; i++) {
		root = insertNode_mergeBST(root, arr[i]);
	}
	return root;
}

int searchNode(struct BstNode *root, BstNode *node) {
	if (root == NULL) return 0;
	if (root == node && root->data == node->data) return 1;
	return searchNode(root->left, node) || searchNode(root->right, node);
}

void addToArray(BstNode **Nodes, BstNode *Node, int &len) {
	for (int i = 0; i < len; i++) {
		if (Nodes[i]->data == Node->data) return;
	}
	Nodes[len++] = Node;
}

void addNodes(struct BstNode *root, BstNode **Nodes, int &len) {
	if (root == NULL) return;
	addNodes(root->left, Nodes, len);
	addToArray(Nodes, root, len);
	addNodes(root->right, Nodes, len);
}

int totalNodeCount(struct BstNode *root) {
	if (root == NULL) {
		return 0;
	}
	else {
		return 1 + totalNodeCount(root->left) + totalNodeCount(root->right);
	}
}

struct Point
{
	int x;
	int y;
};


struct result
{
	Point* selected;
	bool *visited;
	int size;
};

int main(){
	/*
		Recursion Main
	
//	int a = saveMary(5, 2);
//	char b = identifyKid(15654, 775874);

	char pixels[1][1] = { { 'r' } };
	int m = 0;
	int n = 0;
	Point pivot = { 0, 0 };
	result res = select_wrapper(&pixels[0][0], m, n, pivot);
	*/
	int result = NewYork(3, 3, 2);
	/*
	int b1[] = { 20, 5, 30 }; int len1 = 3;
	int b2[] = { 25, 10, 35 }; int len2 = 3;

	BstNode *Nodes[30]; int len = 0;
	BstNode *bst1 = create_BST(b1, len1);
	BstNode *bst2 = create_BST(b2, len2);

	addNodes(bst1, Nodes, len);
	addNodes(bst2, Nodes, len);

	merge_two_bst(&bst1, bst2);
	*/ 
	return 0;
}

