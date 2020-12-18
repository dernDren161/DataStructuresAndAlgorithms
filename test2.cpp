class Solution {
public:
    // Helper function doing actual work
    int maxPathSumHelper(TreeNode* root,int &maxSum)
    {
        if (!root)
            return 0;
        // For both, Left and Right subtree, first get the sum
		//If its less than 0, then assign 0 as value of respective subtree
        int leftVal = max(maxPathSumHelper(root->left, maxSum),0);
        int rightVal = max(maxPathSumHelper(root->right, maxSum),0);

		//Update maxSum if current node node can return maxSum Path
        maxSum = max (maxSum, root->val + leftVal+ rightVal);


		//Return the max value of path of either left or right subtree
        return (root->val + max(leftVal, rightVal));
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxPathSumHelper(root,maxSum);
        return maxSum;
    }
};
