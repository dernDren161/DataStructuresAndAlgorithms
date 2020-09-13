// Problem Link: https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1/?track=amazon-dynamic-programming&batchId=192

// It is an NP complete problem(though an exception) . exception as the dp solution gives a polynomial solution.
// By recursion - 2^n
// By DP - O(nm)
// By DP(space) also - O(nm)
int call(int W, int n, int wt[], int val[]){

    int mat[n+1][W+1];

    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            if(i == 0 || j == 0){
                mat[i][j] = 0;
            }

             else if(j < wt[i-1]){
                mat[i][j] = mat[i-1][j];
            }
            else{
                mat[i][j] = max((val[i-1]+ mat[i-1][j-wt[i-1]]),(mat[i-1][j]));
            }


        }
    }

   return mat[n][W];
}

int knapSack(int W, int wt[], int val[], int n)
{
    return call(W,n,wt,val);
}
