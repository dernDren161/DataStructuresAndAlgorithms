// Problem Link: https://leetcode.com/problems/combination-sum/solution/
/*
  T.C: O(N^((T/M)+1 )), where N is the size of the vector , T is the target and M is the minimum element in the given vector
  S.C: O(T/M)
*/

class Solution {
public:
    vector<vector<int>> result;

    void callToCompute(vector<int>& candidates, int l, int r, int target,vector<int> ans, int sum){

        if(sum==target){
            result.push_back(ans);
            return;
        }

        if(l>=r || sum>target) return;

        ans.push_back(candidates[l]);
        callToCompute(candidates,l,r,target,ans,sum+candidates[l]);
        ans.pop_back();
        callToCompute(candidates,l+1,r,target,ans,sum); // NOTE: Do not add to sum here, sum is added only once.
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        int n = candidates.size();
        vector<int> ans;
        callToCompute(candidates,0,n,target,ans,0);

        return result;
    }
};
