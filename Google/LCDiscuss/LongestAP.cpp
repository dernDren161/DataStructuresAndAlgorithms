// Problem Link:https://www.geeksforgeeks.org/longest-path-to-the-bottom-of-a-binary-tree-forming-an-arithmetic-progression/

void dfs(Tree* root, int currentDifference,
		int count, int& maxLength)
{
	// If the root's left child exists
	if (root->left) {

		// Calculate the difference
		int difference = root->left->val
						- root->val;

		// If the difference is same
		// as the current difference
		if (difference == currentDifference) {
			dfs(root->left, currentDifference,
				count + 1, maxLength);

			// Update the maxLength
			maxLength = max(maxLength,
							count + 1);
		}

		// Otherwise
		else {
			dfs(root->left, difference,
				2, maxLength);
		}
	}

	// If the root's right child exists
	if (root->right) {

		// Find the difference
		int difference = root->right->val
						- root->val;

		// If the difference is the same
		// as the current difference
		if (difference == currentDifference) {

			dfs(root->right, currentDifference,
				count + 1, maxLength);

			// Update the maxLength
			maxLength = max(maxLength,
							count + 1);
		}

		// Otherwise
		else {
			dfs(root->right, difference,
				2, maxLength);
		}
	}
}

// Function to find the maximum length
// of the path from any node to bottom
// of the tree forming an AP
int maximumLengthAP(Tree* root)
{

	// Base Cases
	if (root == NULL)
		return 0;

	if (root->left == NULL
		and root->right == NULL) {
		return 1;
	}

	// Stores the resultant
	// maximum length of the path
	int maxLength = 2;

	// If the root's left child exists
	if (root->left) {

		int difference = root->left->val
						- root->val;
		dfs(root->left, difference, 2,
			maxLength);
	}

	// If the root's right child exists
	if (root->right) {
		int difference = root->right->val
						- root->val;
		dfs(root->right, difference, 2,
			maxLength);
	}

	// Return the maximum length obtained
	return maxLength;
}
