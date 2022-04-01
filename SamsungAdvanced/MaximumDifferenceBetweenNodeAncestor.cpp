// Problem Link: https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

class Solution {
public:

    int call(TreeNode* root, int maxi, int mini){

        if(root==NULL){
            return maxi-mini;
        }

        maxi = max(maxi,root->val);
        mini = min(mini,root->val);

        int le = call(root->left,maxi,mini);
        int ri = call(root->right,maxi,mini);

        return max(le,ri);
    }
    int maxAncestorDiff(TreeNode* root) {

        return call(root,root->val,root->val);
    }
};
