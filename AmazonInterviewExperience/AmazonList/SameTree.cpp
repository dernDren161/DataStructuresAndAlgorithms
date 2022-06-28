// Problem Link: https://leetcode.com/problems/same-tree/
// T.C: O(n)
// S.C: O(n) for the worst case and O(log n) for the best case

class Solution {
public:

    bool call(TreeNode* p, TreeNode* q){

        if(p==NULL && q==NULL) return true;

        if(p && q && p->val==q->val){
            return call(p->left,q->left)&&call(p->right,q->right);
        }

        return false;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {

        if(p==NULL && q==NULL) return true;

        return call(p,q);
    }
};
