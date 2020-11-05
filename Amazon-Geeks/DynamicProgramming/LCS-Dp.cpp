// Problem Link: https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1/?track=amazon-dynamic-programming&batchId=192#

int call(string&s1, string& s2, int x, int y){

    int mat[x+1][y+1];

    for(int i=0;i<x+1;i++) mat[i][0] = 0;
    for(int i=0;i<y+1;i++) mat[0][i] = 0;

    for(int i=1;i<x+1;i++){
        for(int j=1;j<y+1;j++){

            if(s1[i-1] == s2[j-1]) mat[i][j] = 1 + mat[i-1][j-1];

            else{
               /*
                NOTE:
                For the largest common substring, simply write:

                mat[i][j] = 0;
               */
                mat[i][j] = max(mat[i][j-1],mat[i-1][j]);
            }
        }
    }

    return mat[x][y];
}

int lcs(int x, int y, string s1, string s2){

    return call(s1,s2,x,y);

}
