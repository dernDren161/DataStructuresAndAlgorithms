
// Problem Link: https://leetcode.com/problems/snakes-and-ladders/

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {

        int n = board.size();

        vector<int> linearStore(n*n+1,-1);
        vector<bool> visited(n+1,false);

        // we use 'n*n+1' as the matrix numbering starts from 1 and vector's start from 0
        // since it starts from 1, we start pop[ulating the linearStore from index 1 instead


        int toggle = 1;
        int temp = 1;

        for(int i=n-1;i>=0;i--){
            if(toggle){
                for(int j=0;j<n;j++){
                    linearStore[temp++] = board[i][j];
                }toggle = 0;
            }else{
                for(int y=n-1;y>=0;y--){
                    linearStore[temp++] = board[i][y];
                }toggle=1;
            }
        }

        queue<pair<int,int>> qs; // number, distance to reach the number
        qs.push(make_pair(1,0));
        visited[1] = true;

        while(!qs.empty()){
            pair<int,int> p;
            p = qs.front();
            qs.pop();

            // NOTE: Accessing the distance
            if(p.first==n*n) return p.second;

                for(int i=p.first+1;i<=p.first+6 && i<=n*n;i++){

                    pair<int,int> newQ;

                    if(!visited[i]){
                        visited[i] = true;
                        newQ.second = 1 + p.second;  // NOTe: Increasing the distance

                        if(linearStore[i]!=-1){
                            newQ.first = linearStore[i];
                        }else{
                            newQ.first = i;
                        }
                    }
                    qs.push(newQ);
                }
        }

        return -1;
    }
};
