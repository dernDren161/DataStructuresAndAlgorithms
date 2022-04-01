// Problem Link: https://leetcode.com/problems/find-leaves-of-binary-tree/

class Solution {
public:
    vector<vector<int>> ans;

    int callDFS(TreeNode* r){

        if(r==NULL) return -1; // NOTE:Most important part :)

        int leftHeight = callDFS(r->left);
        int rightHeight = callDFS(r->right);

        int height = 1 + max(leftHeight,rightHeight);

        if(height==ans.size()){
            ans.push_back({});
        }

        ans[height].push_back(r->val);

        return height;
    }

    vector<vector<int>> findLeaves(TreeNode* root) {
        ans.clear();
        callDFS(root);

        return ans;
    }
};
