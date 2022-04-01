// Problem Link: https://www.interviewbit.com/problems/distinct-subsequences/

int Solution::numDistinct(string A, string B) {
    // Distinct Occurences
    int r = A.size(); // the longer one
    int c = B.size();
    int dp[r+1][c+1];
    for(int i=0;i<r+1;i++){
        dp[i][0] = 1;
    }
    for(int i=1;i<c+1;i++){
        dp[0][i] = 0;
    }

    for(int i=1;i<r+1;i++){
        for(int j=1;j<c+1;j++){
            if(A[i-1]==B[j-1]){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[r][c];
}
