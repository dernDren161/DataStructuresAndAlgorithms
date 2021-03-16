// Problem Link: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

class Solution {
public:
    int n,m;
    int ans=0;
    int xx[4] = {1,-1,0,0};
    int yy[4] = {0,0,1,-1};
    int solve(vector<vector<int>>& matrix,int x,int y,int cnt,vector<vector<int>>&dp)
    {
        if(dp[x][y]!=-1) return dp[x][y];
        int res = INT_MIN;
        for(int i=0;i<4;i++)
        {
            int tx = x + xx[i];
            int ty = y + yy[i];
            if(tx>=0 && ty>=0 && tx<n && ty<m && matrix[tx][ty]>matrix[x][y])
                res = max(res,1+solve(matrix,tx,ty,cnt+1,dp));
        }
        return dp[x][y] = max(res,1);
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        if(n==0) return 0;
        m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                solve(matrix,i,j,1,dp);
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
