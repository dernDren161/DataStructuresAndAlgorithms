class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();


        auto inside=[&](int x,int y){
            return x<n && y<m && x>=0 && y>=0;
        };


        vector<pair<int,int>>dirs={{0,1},{1,0},{0,-1},{-1,0}};


        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));


        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;


        q.push({0,{0,0}});
        dp[0][0]=0;


        while(!q.empty()){

            int x=q.top().second.first,y=q.top().second.second,effort=q.top().first;
            q.pop();


            for(auto&dir:dirs){

                int new_x=x+dir.first,new_y=y+dir.second;

                // if thoses new indxes are inside the scope of matrix
                if(inside(new_x,new_y)){

                    // calcutaing current effort
                    int path_length=abs(heights[new_x][new_y]-heights[x][y]);

                    // calcualting max of current effort and the already known effort
                    int new_effort=max(path_length,effort);

                    // if the maximum of effort is smaller that already know of new index, than we update
                    if(new_effort<dp[new_x][new_y]){
                        dp[new_x][new_y]=new_effort;
                        q.push({new_effort,{new_x,new_y}});
                    }
                }
            }
        }

        return dp[n-1][m-1];
    }
};
