// Problem Link: https://leetcode.com/problems/subsets/

class Solution {

    vector<vector<int>> ans;

    void call(vector<int>&nums, vector<int> &temp, int l, int r){

        if(l==r){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[l]);
        call(nums,temp,l+1,r);
        temp.pop_back();
        call(nums,temp,l+1,r);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        if(nums.size()==0) return {};

        vector<int> temp;

        call(nums,temp,0,nums.size());
        return ans;
    }
};
