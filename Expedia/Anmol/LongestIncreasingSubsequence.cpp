// Problem Link: https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int call(vector<int>dp, vector<int> nums, int x){

        int l = 0;
        int r = dp.size()-1;

        while(l<=r){
            int m = l + (r-l)/2;

            // single element
            if(dp.size()==1) return m;

            // just two elements
            if(l==m) return (dp[m]>=x)?m:m+1;

            if(dp[m-1]<x && x<=dp[m]) return m;

            if(dp[m]>x) r = m-1;
            else l = m+1;
        }

        return 0;
    }
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp;

        dp.push_back(nums[0]);

        for(int i=1;i<n;i++){
            if(nums[i]>dp[dp.size()-1])dp.push_back(nums[i]); // NOTE: Don't write nums[i]>=dp[n-1], as breaks for [7,7,7,7,7]
            else{
                int index = call(dp,nums,nums[i]);
                dp[index] = nums[i];
            }
        }

        return dp.size();
    }
};
