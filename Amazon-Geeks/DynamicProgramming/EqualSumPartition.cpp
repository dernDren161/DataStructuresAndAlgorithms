// Problem Link: https://practice.geeksforgeeks.org/problems/subset-sum-problem2643/1/?track=amazon-dynamic-programming&batchId=192
// The question is same for: Subset sum problem
// Also it is the same for: count the number of subsets sum problem -->> Hint: use '+' instead of '||' for counting the subsets.


bool call(int a[], int n){

    int s = 0;
    for(int i=0;i<n;i++) s += a[i];

    // if the sum is not even.
    if((s % 2) != 0) return false;

    int temp = s/2;

    /* This is important: when the sum is 0 then it is true as an array of let's say 1,2,3,4 can surely have sum 0 if none of them are taken so hence true
    Base case for this recursive code is:
    if(sum == 0) return true;
    if(n == 0) return false;
    */

    // find temp if it can be made a subset in the array.
    /*
                 s
            |f | f|f |f |f |
            |t | | | | |
         n  | t| | | | |
            | t| | | | | // of utmost significance.
    */

    // NOTE: From here on, it is the same code for the SUbset Sum problem as well and is the same as Target Sum problem as well.

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
