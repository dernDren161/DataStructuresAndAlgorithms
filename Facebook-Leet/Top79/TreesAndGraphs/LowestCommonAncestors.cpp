// Problem Link: https://leetcode.com/explore/interview/card/facebook/52/trees-and-graphs/3024

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root == NULL) return NULL;

        if(root == p || root == q){
            return root;
        }


        // Hypothesis: is that l gives p from the sub-tree

        TreeNode* l = lowestCommonAncestor(root->left,p,q);
        TreeNode* r = lowestCommonAncestor(root->right,p,q);

        if(l && r) return root;

        return (l)?l:r;

    }
};
