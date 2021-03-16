// Problem Link: https://leetcode.com/problems/walls-and-gates/

class Solution {
    bool safe(int a, int b, int n){
        return a<n && a>=0 && b<n && b>=0;
    }
public:
    void wallsAndGates(vector<vector<int>>& rooms) {

        if(rooms.size()==NULL) return;

        int n = rooms.size();
        bool truth[n][n];
        memset(truth,false,sizeof(truth));

        queue<pair<pair<int,int>,int>> qs;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(rooms[i][j]==0){
                    qs.push({{i,j},0});
                    truth[i][j]=true;
                }
            }
        }
        //{{i,j},dist}
        // qs has the open gate values;
        // right,down,left,up
        int r[4]={0,1,0,-1};
        int c[4]={1,0,-1,0};

        while(!qs.empty()){
            int x = qs.front().first.first;
            int y = qs.front().first.second;
            int dist = qs.front().second;
            rooms[x][y] = dist;
            qs.pop();

            for(int i=0;i<4;i++){
                if(safe(x+r[i],y+c[i],n) && rooms[x+r[i]][y+c[i]]==2147483647 && truth[x+r[i]][y+c[i]]==false){
                    truth[x+r[i]][y+c[i]] = true;
                    qs.push({{x+r[i],y+c[i]},dist+1});
                }
            }
        }
    }
};
