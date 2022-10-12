// Problem Link: https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1/?company[]=Samsung&company[]=Samsung&problemStatus=unsolved&page=1&query=company[]SamsungproblemStatusunsolvedpage1company[]Samsung#

class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int c = 0;
    // R,D,L,U,RD,LD,LU,RU
    int row[8] = {0,1,0,-1,1,1,-1,-1};
    int col[8] = {1,0,-1,0,1,-1,-1,1};

    bool isSafe(int i, int j, int m, int n, vector<vector<int>>&grid){
        return i>=0 && i<m && j>=0 && j<n;
    }

    void callDFS(int i, int j, int m, int n, vector<vector<int>> & grid){

        grid[i][j] = 0;
        c++;

        for(int x =0;x<8;x++){
            if(isSafe(i+row[x],j+col[x],m,n,grid)&&grid[i+row[x]][j+col[x]]==1){
                callDFS(i+row[x],j+col[x],m,n,grid);
            }
        }
    }

    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int maxi = INT_MIN;

        int m = grid.size();
        int n = grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                callDFS(i,j,m,n,grid);
                maxi = max(maxi,c);
                c = 0;
                }
            }
        }

        return maxi;

    }
};
