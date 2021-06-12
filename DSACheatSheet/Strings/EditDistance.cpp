// Problem Link: https://practice.geeksforgeeks.org/problems/edit-distance3702/1#

// NOTE: An advanced form of the 'One Edit Distance' question asked in Facebook.

class Solution {
  public:
    int editDistance(string s, string t) {
        // Code here

        int m = s.size();
        int n = t.size();

        int mat[m+1][n+1];

        for(int i=0;i<m+1;i++) mat[i][0] = i;
        for(int i=0;i<n+1;i++) mat[0][i] = i;

        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){

                if(s[i-1]==t[j-1]){
                    mat[i][j] = mat[i-1][j-1];
                }else if(s[i-1] != t[j-1]){
                    /*
                        1. REPLACE ----          1 + mat[i-1][j-1]
                        2. DELETE/INSERT(i) --   1 + mat[i-1][j]
                        3. DELETE/INSERT(j) --   1 + mat[i][j-1]
                    */

                    mat[i][j] = 1 + min(min(mat[i-1][j-1],mat[i-1][j]),mat[i][j-1]);
                }
            }
        }

        return mat[m][n];
    }
};
