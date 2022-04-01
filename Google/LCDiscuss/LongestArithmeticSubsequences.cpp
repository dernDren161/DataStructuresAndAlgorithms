class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {

        int n=nums.size(), ans=0;
        unordered_map<int, unordered_map<int, int>> dp;

        //ending_index, diff, count
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                int diff=nums[i]-nums[j];
                dp[i][diff] = max(2, max(dp[i][diff], dp[j][diff]+1));
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
};
