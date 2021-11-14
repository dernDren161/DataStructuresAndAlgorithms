// Problem Link: https://leetcode.com/problems/binary-tree-level-order-traversal/submissions/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        if(root==NULL) return {};

        queue<TreeNode*> qs;
        qs.push(root);
        vector<vector<int>> result;

        while(!qs.empty()){
            int s = qs.size();
            vector<int> temp;

            while(s--){
                TreeNode* f = qs.front();
                qs.pop();
                temp.push_back(f->val);

                if(f->left)qs.push(f->left);
                if(f->right)qs.push(f->right);
            }

            result.push_back(temp);
        }

        return result;
    }
};
