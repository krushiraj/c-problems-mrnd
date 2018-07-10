/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  struct node * left;
  int data;
  struct node *right;
};


void findLeafDown(struct node *root, int lev, int *minDist)
{
	if (root == NULL)
		return;
	if (root->left == NULL && root->right == NULL)
	{
		if (lev < (*minDist))
			*minDist = lev;
		return;
	}
	findLeafDown(root->left, lev + 1, minDist);
	findLeafDown(root->right, lev + 1, minDist);
}

int findThroughParent(struct node * root, struct node *x, int *minDist)
{
	if (root == NULL) return -1;
	if (root == x) return 0;

	int l = findThroughParent(root->left, x, minDist);

	if (l != -1)
	{
		findLeafDown(root->right, l + 2, minDist);
		return l + 1;
	}

	int r = findThroughParent(root->right, x, minDist);

	if (r != -1)
	{
		findLeafDown(root->left, r + 2, minDist);
		return (r + 1);
	}

	return -1;
}

int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (root == NULL || temp == NULL)
		return -1;
	int minDist = INT_MAX;

	findLeafDown(temp, 0, &minDist);

	findThroughParent(root, temp, &minDist);
	return minDist;
	
}