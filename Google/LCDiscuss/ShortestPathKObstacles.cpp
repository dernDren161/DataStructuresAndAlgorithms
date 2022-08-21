// Problem Link: https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/

class Solution {
public:

    bool isSafe(int newRow, int newCol, int r, int c){
        return newRow>=0 && newCol>=0 && newRow<r && newCol<c;
    }

    int shortestPath(vector<vector<int>>& grid, int k) {

        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>>vis(r,vector<int>(c,-1));

        queue<vector<int>>qs;
        qs.push({0,0,0,k});

        // R,D,L,U
        int rowM[4] = {0,1,0,-1};
        int colM[4] = {1,0,-1,0};

        while(!qs.empty()){
            vector<int> f = qs.front();
            qs.pop();
            int x = f[0];
            int y = f[1];
            int dist = f[2];
            int quota = f[3];

            if(x==r-1 && y==c-1) return dist;

            if(grid[x][y]==1) quota--;

            for(int i=0;i<4;i++){
                int newRow = x + rowM[i];
                int newCol = y + colM[i];

                if(isSafe(newRow,newCol,r,c) && vis[newRow][newCol]<quota){
                    vis[newRow][newCol] = quota;
                    qs.push({newRow,newCol,dist+1,quota});
                }
            }
        }

        return -1;
    }
};
