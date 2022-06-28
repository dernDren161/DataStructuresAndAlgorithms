// Problem Link: https://practice.geeksforgeeks.org/problems/find-whether-path-exist5238/1#
// T.C : O(n^2)

// Had it been through recursion T.C would be: O(4^(m*n)) but i have been reading O(n^(8))---[NOTE: This one is wrong the T.C is O(4^(m*n))], confusion
// but for this it is O(4^(m*n)) only

// NOTE: Asked in Bytedance

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.

    bool isSafe(int r, int c, int row, int col){
        return r>=0 && c>=0 && r<=row && c<=col;
    }

    bool is_Possible(vector<vector<int>>& grid)
    {
        //code here
        int n = grid.size();
        int i,j;
        bool flag = false;

        for(int x=0;x<n;x++){
            for(int y=0;y<n;y++){
                if(grid[x][y]==1){
                    i = x;j=y; flag = true; break;
                }
                if(flag) break;
            }
        }

        bool vis[n][n];
        memset(vis,false,sizeof(vis));

        vis[i][j] = true;

        queue<pair<int,int>>qs;
        qs.push(make_pair(i,j));

        //R,D,L,U
        int row[4] = {0,1,0,-1};
        int col[4] = {1,0,-1,0};

        while(!qs.empty()){
            pair<int,int> f;
            f = qs.front();
            int r,c;
            r = f.first;
            c = f.second;

            qs.pop();

            if(grid[r][c]==2) return true;

            for(int i=0;i<4;i++){
                  // NOTE: IMP Observe carefully
                    if(isSafe(r+row[i],c+col[i],n-1,n-1) && grid[r+row[i]][c+col[i]]!=0 && !vis[r+row[i]][c+col[i]]){
                        vis[r+row[i]][c+col[i]]=true;
                        qs.push({r+row[i],c+col[i]});
                    }

            }
        }

        return false;
    }
};
