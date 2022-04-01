// Problem Link: https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/

class Solution {
public:
    // R,D,L,U
    int rowM[4]={0,1,0,-1};
    int colM[4]={1,0,-1,0};

    bool isSafe(int i, int j, int r, int c){
        return i>=0 && j>=0 && i<r && j<c;
    }

    int shortestPath(vector<vector<int>>& grid, int k) {

        int r = grid.size(); int c = grid[0].size();
        vector<vector<int>>vis(r,vector<int>(c,-1));

        // r,c,dist,k(remaining quotas)
        queue<vector<int>>qs;
        qs.push({0,0,0,k});


        while(!qs.empty()){
            auto x = qs.front();
            int a = x[0];
            int b = x[1];
            int dist = x[2];
            int quotas = x[3];

            qs.pop();

            if(a==r-1 && b==c-1) return dist;

            for(int i=0;i<4;i++){
               if(isSafe(a+rowM[i],b+colM[i],r,c)){
                   if(grid[a+rowM[i]][b+colM[i]]==1 && quotas>0){
                       quotas--;
                   }else if(grid[a+rowM[i]][b+colM[i]]==1 && quotas<=0)continue;

                   if(vis[a+rowM[i]][b+colM[i]]!=-1 && vis[a+rowM[i]][b+colM[i]]>=quotas){
                       continue;
                   }

                   vis[a+rowM[i]][b+colM[i]] = quotas;

                   qs.push({a+rowM[i],b+colM[i],dist+1,quotas});
               }
            }

        }

        return -1;
    }
};
