// Problem Link: https://leetcode.com/problems/combination-sum/solution/
/*
  T.C: O(N^((T/M)+1 )), where N is the size of the vector , T is the target and M is the minimum element in the given vector
  S.C: O(T/M)
*/

class Solution {
public:
    vector<vector<int>> ans;

    void call(vector<int>&candidates, int target, int x, int sum,vector<int>&temp){

        if(x>=candidates.size()) return;
        if(sum>target) return;
        if(sum==target){
            ans.push_back(temp);
        }

        for(int i=x;i<candidates.size();i++){
            temp.push_back(candidates[i]);
            call(candidates,target,i,sum+candidates[i],temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        int n = candidates.size();
        vector<int>temp;
        ans.clear();
        call(candidates,target,0,0,temp);
        return ans;
    }
};
