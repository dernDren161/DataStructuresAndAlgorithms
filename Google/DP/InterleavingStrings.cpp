// Problem Link: https://www.interviewbit.com/problems/interleaving-strings/

int Solution::isInterleave(string A, string B, string C) {
    // interleaving strings
  int m = A.size();
    int n = B.size();
    bool dp[m+1][n+1];

    if(m+n != C.size()) return 0;
    memset(dp,false,sizeof(dp));

    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 && j==0) dp[i][j]=true;

            else if(i==0){ // if A is empty
                if(B[j-1]==C[j-1]){
                    dp[i][j] = dp[i][j-1];
                }
            }
            else if(j==0){// if B is empty
                if(A[i-1]==C[i-1]){
                    dp[i][j] = dp[i-1][j];
                }
            }
            else if(A[i-1]==C[i+j-1] && B[j-1]!=C[i+j-1]){
                // if A and C are equal
                dp[i][j] = dp[i-1][j];
            }else if(B[j-1]==C[i+j-1] && A[i-1]!=C[i+j-1]){
                dp[i][j] = dp[i][j-1];
            }else if(A[i-1]==C[i+j-1] && B[j-1]==C[i+j-1]){
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
        }
    }

    return dp[m][n];
}
