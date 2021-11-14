// Problem Link: https://leetcode.com/problems/symmetric-tree/
// Both T.C and S.C are O(n)

class Solution {
public:

    bool call(TreeNode* l, TreeNode* r){

        if(l==NULL && r==NULL) return true;

        if(l && r && l->val==r->val){
            return call(l->left,r->right)&&call(l->right,r->left);}

            return false;

    }
    bool isSymmetric(TreeNode* root) {

        if(root==NULL) return true;

       return call(root,root);
    }
};
