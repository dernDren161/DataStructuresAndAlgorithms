// Problem Link: https://leetcode.com/explore/interview/card/facebook/52/trees-and-graphs/291/

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

 // T.C: O(n)
 
class Solution {

    // maximum number of node from the tree
    int call(TreeNode* r, int& res){

        if(r == NULL) return 0;

        int l = call(r->left,res);
        int ri = call(r->right,res);

        int temp = max(l,ri) + 1; //passes through the root node.
        int ans = max(temp,l+ri+1);

        res = max(res,ans);

        // NOTE: Very important point to be noted.
        return temp;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {

        if(root == NULL) return 0;

        int res = INT_MIN;

        call(root,res);

        return res-1;
    }
};
