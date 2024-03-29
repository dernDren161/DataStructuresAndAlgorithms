// Problem Link: https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
       int dp[N][N];

       for(int i=0;i<N;i++){
           dp[0][i] = Matrix[0][i];
       }

       for(int i=1;i<N;i++){
           for(int j=0;j<N;j++){
               if(j==0){
                   dp[i][j] = Matrix[i][j] + max(dp[i-1][j],dp[i-1][j+1]);
               }else if(j==N-1){
                   dp[i][j] = Matrix[i][j] + max(dp[i-1][j],dp[i-1][j-1]);
               }else{
                   dp[i][j] = Matrix[i][j] + max(dp[i-1][j],max(dp[i-1][j-1],dp[i-1][j+1]));
               }
           }
       }

       int ans = INT_MIN;

       for(int i=0;i<N;i++){
           ans = max(ans,dp[N-1][i]);
       }

       return ans;
    }
};
