// Problem Link: https://leetcode.com/contest/weekly-contest-292/problems/check-if-there-is-a-valid-parentheses-string-path/

class Solution {
public:

    bool callBackTrack(vector<vector<char>>&grid, int r, int c, int k, int x, int y,vector<vector<vector<int>>>&dp){

        if(x>=r || y>=c) return false;

        if(grid[x][y]=='(')k++;
        else if(grid[x][y]==')')k--;

        if(x==r-1 && y==c-1){
            if(k==0) return true;
            return false;
        }

        if(k<0) return false;

        if(dp[x][y][k] != -1) return dp[x][y][k];

        return dp[x][y][k] = callBackTrack(grid,r,c,k,x,y+1,dp) || callBackTrack(grid,r,c,k,x+1,y,dp);
    }

    bool hasValidPath(vector<vector<char>>& grid) {

        if(grid[0][0]==')') return false;

        vector<vector<vector<int>>>dp(grid.size(),vector<vector<int>> (grid[0].size(),vector<int>(201,-1)));
        return callBackTrack(grid,grid.size(),grid[0].size(),0,0,0,dp);
    }
};
