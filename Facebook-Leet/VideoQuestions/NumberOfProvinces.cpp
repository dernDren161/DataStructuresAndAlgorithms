// Problem Link: https://leetcode.com/problems/number-of-provinces/

class Solution {
public:
    void call(vector<vector<int>>& m, bool truth[], int i){
        truth[i] = true;

        for(int j=0;j<m[i].size();j++){
            if(!truth[j] && m[i][j]==1){
                call(m,truth,j);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        bool truth[n];
        memset(truth,false,sizeof(truth));
        int k = 0;

        for(int i=0;i<n;i++){
            if(!truth[i]){
                call(isConnected,truth,i);
                 k++;
            }

        }

        return k;
    }
};
