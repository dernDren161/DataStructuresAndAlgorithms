// Problem Link: https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1

class Solution{
public:
    int dp[101][101];

    int callToFind(vector<vector<int>> &Matrix, int i, int j){

        int res = 0;
        if(i>=Matrix.size() || j<0 || j>= Matrix.size()){
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        res = max(res,callToFind(Matrix,i+1,j)+Matrix[i][j]);
        res = max(res,callToFind(Matrix,i+1,j-1)+Matrix[i][j]);
        res = max(res,callToFind(Matrix,i+1,j+1)+Matrix[i][j]);

        dp[i][j] = res;

        return dp[i][j];
    }

    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int ans = 0;
        memset(dp,-1,sizeof(dp));

        for(int i=0;i<Matrix[0].size();i++){
            ans = max(ans,callToFind(Matrix,0,i));
        }

        return ans;
    }
};
