int mat[100][100];
memset(mat,-1,sizeof(mat));

int call(strin& s, int i, int j){

  if(i>=j) return 0;

  if(isPalindrome(s,i,j)) return 0;

  if(mat[i][j] != -1) return mat[i][j];

  int m = INT_MAX;

  for(int k=i;k<=j-1;k++){

    int temp = call(s,i,k) + call(s,k+1,j) + 1;
    m = min(m,temp);
  }

  mat[i][j] = m;

  return mat[i][j];
}
