// Problem Link: https://leetcode.com/problems/path-sum-iii/

// NOTE: Here the value of 's' and map, 'm' is not preserved or not sent by reference
// But the value of ans is being sent by 'pass by reference' so be careful

class Solution {
public:
    void call(TreeNode* r, int k, unordered_map<int,int>m, int& ans, int s){

        if(r==NULL) return;

        s = s + r->val;
        auto p = m.find(s-k);
        if(p!=m.end()){
            ans = ans + p->second;
        }
        m[s]++;

        call(r->left,k,m,ans,s);
        call(r->right,k,m,ans,s);
    }
    int pathSum(TreeNode* root, int targetSum) {

        unordered_map<int,int>m;
        m[0] = 1;
        int ans = 0;
        int s=0;
        call(root,targetSum,m,ans,s);

        return ans;
    }
};
