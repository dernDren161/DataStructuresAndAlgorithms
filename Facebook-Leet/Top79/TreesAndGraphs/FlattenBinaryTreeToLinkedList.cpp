// Problem Link: https://leetcode.com/explore/interview/card/facebook/52/trees-and-graphs/322/
// Algorithmic explanation: https://www.geeksforgeeks.org/flatten-a-binary-tree-into-linked-list/#:~:text=Given%20a%20binary%20tree%2C%20flatten,contain%20next%20node%20in%20preorder.&text=Simple%20Approach%3A%20A%20simple%20solution,Level%20Order%20Traversal%20using%20Queue.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {

        // Here we use the inorder traversal

        if(root == NULL) return;

        // NOTE: Important base case, Note it duly !!
        if(root -> left== NULL && root -> right == NULL) return;

        if(root -> left != NULL){
        flatten(root -> left);

        TreeNode* temp;
        temp = root -> right;
        root -> right = root -> left;
        root -> left = NULL;

        TreeNode* temp2;
        temp2 = root -> right;

        while(temp2->right){
            temp2 = temp2 -> right;
        }

        temp2 -> right = temp;
        }

        flatten(root -> right);
    }
};
