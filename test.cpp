{
  int dp[T.length() + 1][S.length() + 1];
  for (int i = 1; i <= T.length(); i++)
        dp[i][0] = 0;

    // Initializing first row with all 1s. An empty
    // string is subsequence of all.
  for (int j = 0; j <= S.length(); j++)
        dp[0][j] = 1;
  for(int i = 1;i<=T.length();i++){

      for(int j = 1;j<=S.length();j++){
          //if(j==0) dp[i][j] = 0;
          //else if(i == 0) dp[i][j] = 1;
          if(T[i-1] == S[j-1]){
            dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
          }
          else if(T[i-1] != S[j-1]){
            dp[i][j] = dp[i][j-1];
          }
      }
  }
  return dp[T.length()][S.length()];
  //Your code here
}
