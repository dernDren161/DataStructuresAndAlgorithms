// Problen Link: https://leetcode.com/problems/maximum-number-of-points-with-cost/submissions/

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {

        int r = points.size();
        int c = points[0].size();

        vector<vector<long long>>dp(r,vector<long long>(c));

        for(int i=0;i<c;i++) dp[0][i] = points[0][i];

        for(int i=1;i<r;i++){
            vector<long long>left(c,0);
            vector<long long>right(c,0);
            vector<long long>prev(c);

            prev = dp[i-1];

            left[0] = prev[0];
            for(int k=1;k<c;k++){
                left[k] = max(left[k-1]-1,prev[k]);
            }

            right[c-1] = prev[c-1];
            for(int k=c-2;k>=0;k--){
                right[k] = max(right[k+1]-1,prev[k]);
            }

            for(int x=0;x<c;x++){
                dp[i][x] = max(left[x],right[x]) + points[i][x];
            }


        }

        long long ans = INT_MIN;
        for(int i=0;i<c;i++){
            ans = max(ans,dp[r-1][i]);
        }

        return (long long)ans;
    }
};
