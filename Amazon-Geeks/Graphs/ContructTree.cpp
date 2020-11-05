#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
	int key;
	Node *left, *right;
};

// Function to create a new binary tree node having given key
Node* newNode(int key)
{
	Node* node = new Node;
	node->key = key;
	node->left = node->right = nullptr;

	return node;
}

// Recursive function to perform inorder traversal of a binary tree
void inorderTraversal(Node* root)
{
	if (root == nullptr)
		return;

	inorderTraversal(root->left);
	cout << root->key << ' ';
	inorderTraversal(root->right);
}

// Recursive function to perform postorder traversal of a binary tree
void preorderTraversal(Node* root)
{
	if (root == nullptr)
		return;

	cout << root->key << ' ';
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

// Recursive function to construct a binary tree from given
// inorder and preorder sequence
Node* construct(int start, int end, vector<int> const &preorder,
				int &pIndex, unordered_map<int,int> &map)
{
	// base case
	if (start > end)
		return nullptr;

	// The next element in preorder[] will be the root node of subtree
	// formed by inorder[start, end]
	Node *root = newNode(preorder[pIndex++]);

	// get the index of root node in inorder[] to determine the
	// boundary of left and right subtree
	int index = map[root->key];

	// recursively construct the left subtree
	root->left = construct(start, index - 1, preorder, pIndex, map);

	// recursively construct the right subtree
	root->right = construct(index + 1, end, preorder, pIndex, map);

	// return current node
	return root;
}

// Construct a binary tree from inorder and preorder traversals
// This function assumes that the input is valid
// i.e. given inorder and preorder sequence forms a binary tree
Node* construct(vector<int> const &inorder, vector<int> const &preorder)
{
	// get number of nodes in the tree
	int n = inorder.size();

	// create a map to efficiently find the index of any element in
	// given inorder sequence
	unordered_map<int,int> map;
	for (int i = 0; i < n; i++)
		map[inorder[i]] = i;

	// pIndex stores index of next unprocessed node in preorder sequence
	// start with root node (present at 0'th index)
	int pIndex = 0;

	return construct(0, n - 1, preorder, pIndex, map);
}

int main()
{
	/* Consider below tree
		  1
		/   \
	   /	 \
	  2	   3
	 /	   / \
	/	   /   \
   4	   5	 6
		  / \
		 /   \
		7	 8
	*/

	vector<int> inorder = { 4, 2, 1, 7, 5, 8, 3, 6 };
	vector<int> preorder = { 1, 2, 4, 3, 5, 7, 8, 6 };

	Node* root = construct(inorder, preorder);

	// traverse the constructed tree
	cout << "Inorder  : "; inorderTraversal(root);
	cout << "\nPreorder : "; preorderTraversal(root);

	return 0;
}
