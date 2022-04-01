// Problem Link: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

class Solution {
public:
    void callDFS(vector<bool>&truth, int i, int r,vector<vector<int>>&stones){

        truth[i] = true;

        for(int x=0;x<r;x++){
            if(!truth[x]){
                if(stones[i][0]==stones[x][0] || stones[i][1]==stones[x][1]){
                    callDFS(truth,x,r,stones);
                }
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {

        int r = stones.size();
        vector<bool>truth(r,false);

        int tempAns = 0;

        for(int i=0;i<r;i++){
            if(!truth[i]){
                callDFS(truth,i,r,stones);
                tempAns++;
            }
        }

        return r-tempAns;
    }
};
