// Problem Link: https://leetcode.com/explore/interview/card/facebook/52/trees-and-graphs/298

class Solution {

    // This 'static' symbol is absolutely important.
    // as in this code the input is taken throught the 'sort' library and again this 'sort' has to invoke the 'comp' function again
    // since this 'comp' function is again inside the 'Solution' class so with 'static' 'Solution:: comp()' is derived
    // thus this way the sort library understands that it is invoking the 'comp' function inside this 'Solution' class
    // Further descriptive discussion is given in this thread at stack overflow
    // https://stackoverflow.com/questions/26131112/why-stdsort-requires-static-compare-function

    static bool comp(pair<int,int> a,pair<int,int> b)
    {
        return a.first<b.first;
    }
public:
  // same @ D-L,N technique as used for the top down question
  // D -> L,N
    map<int,vector<pair<int,int>>> m;
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root,0,0);
        vector<int> v;
        for(auto i:m)
        {
            // most important step as sorting them in this ascending order way
            sort(i.second.begin(),i.second.end(),comp);
            for(auto k:i.second)
                v.push_back(k.second);
            ans.push_back(v);
            v.clear();
        }
        return ans;
    }
    void dfs(TreeNode* root,int ind,int dp)
    {
        if(root==NULL)
            return;
        m[ind].push_back({dp,root->val});
        dfs(root->left,ind-1,dp+1);
        dfs(root->right,ind+1,dp+1);
    }
};
