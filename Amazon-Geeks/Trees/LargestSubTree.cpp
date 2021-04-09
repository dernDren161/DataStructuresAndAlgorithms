// Problem Link: https://www.geeksforgeeks.org/largest-sub-tree-having-equal-no-of-1s-and-0s/

// C++ implementation of the approach
#include <iostream>
using namespace std;

// To store the size of the maximum sub-tree
// with equal number of 0's and 1's
int maxSize = -1;

// Represents a node of the tree
struct node {
	int data;
	struct node *right, *left;
};

// To create a new node
struct node* newnode(int key)
{
	struct node* temp = new node;
	temp->data = key;
	temp->right = NULL;
	temp->left = NULL;
	return temp;
}

// Function to return the maximum size of
// the sub-tree having equal number of 0's and 1's
int maxsize(struct node* root)
{
  if(root == NULL) return 0;

	// NOTE: Look closely this assignment part is the same in both the functions.
  int a = 0;
  int b = 0;

  a = maxsize(root -> left);
  a = a + 1;  // observe closely : this line adds for the root node count
  b = maxsize(root -> right);
  a = a + b;

  if(root -> data == 0){
    if(a >= maxSize){
      maxSize = a;
    }
  }


return a;
}

// adding the root nodes of each subtree
int sum_tree(struct node* root)
{
  if(root != NULLmaxSize){
    if(root -> data == 0){
      root -> data = -1;
    }
  }

  int a = 0;
  int b = 0;

  if(root -> left != NULL) a = sum_tree(root -> left);
  if(root -> right != NULL) b = sum_tree(root -> right);

  root -> data += (a+b);

  return root -> data;

}

// Driver code
int main()
{
	struct node* root = newnode(1);
	root->right = newnode(0);
	root->right->right = newnode(1);
	root->right->right->right = newnode(1);
	root->left = newnode(0);
	root->left->left = newnode(1);
	root->left->left->left = newnode(1);
	root->left->right = newnode(0);
	root->left->right->left = newnode(1);
	root->left->right->left->left = newnode(1);
	root->left->right->right = newnode(0);
	root->left->right->right->left = newnode(0);
	root->left->right->right->left->left = newnode(1);

	sum_tree(root);

	maxsize(root);

	cout << maxSize;

	return 0;
}
