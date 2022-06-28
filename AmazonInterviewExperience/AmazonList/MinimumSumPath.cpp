// Problem Link: https://leetcode.com/problems/minimum-path-sum/

/*
  It goes in two directions. Had I done it using backtracking, for each node there were 2 possibilities
  so O(2^(m+n)), where m is row and n is the column number.
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        int mat[row][col]; // initialized to zero already

        mat[0][0] = grid[0][0];

        for(int i=1;i<row;i++) mat[i][0] = grid[i][0] + mat[i-1][0];
        for(int i=1;i<col;i++) mat[0][i] = grid[0][i] + mat[0][i-1];

        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                mat[i][j] = min(mat[i][j-1],mat[i-1][j])+grid[i][j];
            }
        }

        return mat[row-1][col-1];
    }
};
