// Problem Link: https://leetcode.com/problems/arithmetic-slices/
// NOTE: Very deep question and very important

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {

        int n = nums.size();
        if(n<3) return 0;

        int dp[n];
        memset(dp,0,sizeof(dp));
        int diff = nums[1] - nums[0];

        int res = 0;

        for(int i=2;i<n;i++){
            if(nums[i]-nums[i-1]==diff){
                dp[i] = dp[i-1] + 1;
            }else{
                diff = nums[i] - nums[i-1];
            }

            res += dp[i];
        }

        return res;
    }
};
