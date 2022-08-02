// Problem Link: https://leetcode.com/problems/invert-binary-tree/

// NOTE: Invert a binary tree is same as creating the mirror tree

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        if(root == NULL) return NULL;

        TreeNode* temp = root->left;
        root -> left = root ->right;
        root->right = temp;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
