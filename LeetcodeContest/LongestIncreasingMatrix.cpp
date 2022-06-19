// Problem Link: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

class Solution {
public:
    int dp[200][200];
    // R,D,L,U
    int rowM[4] = {0,1,0,-1};
    int colM[4] = {1,0,-1,0};

    bool isSafe(int i, int j, int r, int c, vector<vector<int>>&mat, int x, int y){
        return i>=0 && j>=0 && i<r && j<c && mat[i][j]>mat[x][y];
    }

    int call(int i, int j, int r,int c, vector<vector<int>>&mat){

        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j] = 1;

        for(int x=0;x<4;x++){
            int a = i+rowM[x]; int b = j+colM[x];

            if(isSafe(a,b,r,c,mat,i,j)){
                dp[i][j] = max(dp[i][j],1+ call(a,b,r,c,mat));
            }
        }

        return dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& mat) {
        // memoization optimization for the same

        int r = mat.size(); int c = mat[0].size();
        memset(dp,-1,sizeof(dp));

        int ans = INT_MIN;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                ans = max(ans,call(i,j,r,c,mat));
            }
        }

        return ans;
    }
};
