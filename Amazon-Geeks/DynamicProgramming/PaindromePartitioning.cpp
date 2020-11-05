// Further optimised code to the Memoization one

int mat[100][100];
memset(mat,-1,sizeof(mat));

int call(string& s, int i, int j){

  if(i>=j) return 0;

  if(isPalindrome(s,i,j)) return 0;

  int m = INT_MAX;

  for(int k=i;k<=j-1;k++){
    int left,right;
    if(mat[i][k] != -1) left = mat[i][k];
    else{
      left = call(s,i,k);
      mat[i][k] = left;
    }

    if(mat[k+1][j] != -1) right = mat[k+1][j];
    else{
      right = call(s,k+1,j);
      mat[k+1][j] = right;
    }

    int temp = 1 + left + right;

    m = min(m,temp);
  }

  mat[i][j] = m;

  return mat[i][j];
}
