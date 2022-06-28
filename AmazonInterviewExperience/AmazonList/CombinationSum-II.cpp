// Problem Link: https://leetcode.com/submissions/detail/605020289/

class Solution {
public:

    vector<vector<int>>ans;

    void callBack(vector<int>&candidates,vector<int>&vs,vector<bool>&vis,int target, int sum, int x){

        if(sum>target) return;

        if(sum==target){
            ans.push_back(vs);
            return;
        }

        for(int i=x;i<candidates.size();i++){

                vs.push_back(candidates[i]);
                callBack(candidates,vs,vis,target,sum+candidates[i],i+1);
                vs.pop_back();

        }

        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        int n = candidates.size();

        vector<int>temp;
        vector<bool>vis(n,false);

        sort(candidates.begin(),candidates.end());
        callBack(candidates,temp,vis,target,0,0);

        set<vector<int>>mySet;
        vector<vector<int>>fAns;

        for(auto x:ans){
            mySet.insert(x);
        }

        for(auto x:mySet){
            fAns.push_back(x);
        }

        return fAns;

    }
};
