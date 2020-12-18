// Problem Link: https://leetcode.com/explore/interview/card/facebook/52/trees-and-graphs/3022/

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

    int call(TreeNode* r, int& res){

        // starting with recursion
        if(r == NULL) return 0;

        int l = call(r->left,res);
        int ri = call(r->right,res);

        int temp = max(max(l,ri)+ r->val, r->val);
        int ans = max(temp,l+ri+r->val);

        res = max(res,ans);

        return temp; // this is as in the hypothesis we had assumed the function would give highest from left and right
    }
public:
    int maxPathSum(TreeNode* root) {

        if(root == NULL) return 0;


        int res = INT_MIN;

        call(root,res);

        return res;
    }
};
