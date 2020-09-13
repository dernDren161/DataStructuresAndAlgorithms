// Problem Link: https://practice.geeksforgeeks.org/problems/subset-sum-problem2643/1/?track=amazon-dynamic-programming&batchId=192

bool call(int a[], int n){

    int s = 0;
    for(int i=0;i<n;i++) s += a[i];

    // if the sum is not even.
    if((s % 2) != 0) return false;

    int temp = s/2;

    // find temp if it can be made a subset in the array.
    /*
                 s
            |f | f|f |f |f |
            |t | | | | |
         n  | t| | | | |
            | t| | | | | // of utmost significance.
    */

    bool mat[n+1][s+1];

    for(int i=0;i<s+1;i++) mat[0][i] = false;
    for(int i=1;i<n+1;i++) mat[i][0] = true;

    for(int i=1;i<n+1;i++){
        for(int j=1;j<s+1;j++){

            // if(W < wt[j-1])
            if(j < a[i-1]){
                mat[i][j] = mat[i-1][j];
            }

            else{
                mat[i][j] = mat[i-1][j] || mat[i-1][j-a[i-1]];
            }

        }
    }

    if(mat[n][temp]) return true;

    return false;

}

bool findPartition(int a[], int n) {

    return call(a,n);
}
