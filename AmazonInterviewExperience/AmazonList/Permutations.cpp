// Problem Link: https://leetcode.com/problems/permutations/
// T.C : O(n*n!)
// S.C : O(n*n!)

class Solution {
public:
    vector<vector<int>> result;

    void callToCompute(vector<int> nums, int l, int r){

        if(l==r){
            result.push_back(nums);
        }

        for(int i=l;i<r;i++){
            swap(nums[i],nums[l]);
            callToCompute(nums,l+1,r);
            swap(nums[i],nums[l]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // distinct elements in the vector

        vector<int> temp;
        callToCompute(nums,0,nums.size());

        return result;
    }
};
