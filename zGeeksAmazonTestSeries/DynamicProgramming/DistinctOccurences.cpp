// Problem Link: https://practice.geeksforgeeks.org/problems/distinct-occurrences/1/?track=amazon-dynamic-programming&batchId=192
// Top Down approach
int subsequenceCount(string S, string T)
{

    int x = S.length();
    int y = T.length();

    int mat[x+1][y+1];

    for(int i=0;i<x+1;i++) mat[i][0] = 1;
    for(int i=1;i<y+1;i++) mat[0][i] = 0; // the base case used in recursion as: if(j == 0) return call(S,T,i-1,j) + 1;

    for(int i=1;i<x+1;i++){
        for(int j=1;j<y+1;j++){

            if(S[i-1] == T[j-1]){
                mat[i][j] = (mat[i-1][j] + mat[i-1][j-1]) % 1000000007;
            }else {
                mat[i][j] = mat[i-1][j];
            }
        }
    }

    return mat[x][y];
}
