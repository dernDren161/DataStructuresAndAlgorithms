// Problem Link: https://leetcode.com/problems/house-robber-ii/

class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);

        int dp[n+1];

        // Case 1: Ignoring the last element in nums

        dp[0] = 0;
        dp[1] = nums[0];

        for(int i=2;i<n;i++){
            dp[i] = max(nums[i-1]+dp[i-2],dp[i-1]);
        }

        int temp = dp[n-1];

        // Case 2: Ignoring the very first element

        dp[1]=0;
        dp[2]=nums[1];

        for(int i=3;i<=n;i++){
            dp[i] = max(nums[i-1]+dp[i-2],dp[i-1]);
        }

        return max(temp,dp[n]);
    }
};
