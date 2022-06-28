// Problem Link: https://leetcode.com/problems/validate-binary-search-tree/
// BOTH T.C and S.C are O(n)

class Solution {
public:

    bool callToValidate(TreeNode* r, long long maxi, long long mini){

        if(r==NULL) return true;

        if(r->val >= maxi || r->val <= mini) return false;

        return callToValidate(r->left,r->val,mini) && callToValidate(r->right,maxi,r->val);

    }
    bool isValidBST(TreeNode* root) {

        if(root==NULL) return true;

        return callToValidate(root,LONG_MAX,LONG_MIN);
    }
};
