// Problem Link: https://practice.geeksforgeeks.org/problems/distinct-occurrences/1/?track=amazon-dynamic-programming&batchId=192

int subsequenceCount(string S, string T)
{
  int s = S.size(); // column
  int t = T.size(); // row

  int mat[t][s];
  int temp = 0;
  for(int i =0;i<s;i++){
    if(T[0] == S[i]){
        mat[0][i] = ++temp;
    }    else{
        mat[0][i] = temp;
    }
  }

  int tempo = 0;
  for(int i = 1; i<t;i++){
      for(int j = 0;j<s;j++){
          if(j == 0){
              mat[i][j] = 0;
              continue;
          }
          if(T[i] == S[j]){
              mat[i][j] = (mat[i][j-1] + mat[i-1][j-1]) % (1000000007);
              continue;
          }
          mat[i][j] = (mat[i][j-1]) % (1000000007);
      }
  }
  int u = mat[t-1][s-1];
  return ((u) % (1000000007));
}
