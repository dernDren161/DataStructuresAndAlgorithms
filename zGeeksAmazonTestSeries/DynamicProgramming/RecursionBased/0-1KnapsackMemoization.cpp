int W,n;
int mat[n+1][W+1];
memset(mat,-1,sizeof(mat));

// Here used memoisation technique to avoid some of the "Overlapping Sub Problems" encountered during the recursive approach.

int knap(int wt[], int val[], int W, int n){

  if(mat[n][W] != -1) return mat[n][W];

  if(W==0 || n==0) return 0;

  if(W >= wt[n-1]){
    mat[n][W] = max(val[n-1]+ knap(wt,val,W-wt[n-1],n-1), knap(wt,val,W,n-1));
  }

  if(W < wt[n-1]){
    mat[n][W] = knap(wt,val,W,n-1);
  }
}
