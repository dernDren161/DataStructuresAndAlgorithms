// Problem Link: https://leetcode.com/problems/number-of-operations-to-make-network-connected/

class Solution {
public:

    void callDFS(int u, vector<vector<int>> &vs,vector<bool>&truth){

        truth[u] = true;

        for(auto x:vs[u]){
            if(!truth[x]) callDFS(x,vs,truth);
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {

        int s = connections.size();

        if(s<n-1) return -1;

        vector<vector<int>> vs(n);

        vector<bool> truth(n,false);

        for(int i=0;i<s;i++){
            vs[connections[i][0]].push_back(connections[i][1]);
            vs[connections[i][1]].push_back(connections[i][0]);
        }

        int k = 0;

        for(int i=0;i<n;i++){
            if(!truth[i]){
                callDFS(i,vs,truth);
                k++;
            }
        }

      // if there are k components then the total extra edges required are definitely k-1

        return k-1;
    }
};
