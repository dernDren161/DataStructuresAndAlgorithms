// Problem Link: https://leetcode.com/problems/matchsticks-to-square/

class Solution {
public:

    bool call(vector<int>&match, int n, int x, int sum, int target, vector<bool>&vis, int k){

        if(k==4) return true;

        if(sum==target){
            return call(match,n,0,0,target,vis,k+1);
        }

        if(sum>target) return false;

        for(int i=x;i<n;i++){
            if(!vis[i]){
                vis[i] = true;
                if(call(match,n,i+1,sum+match[i],target,vis,k)) return true;
                vis[i] = false;
            }
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {

        int n = matchsticks.size();
        int sum = 0;
        for(int x:matchsticks) sum+= x;
        if(sum%4 != 0) return false;
        vector<bool>vis(n,false);

        return call(matchsticks,n,0,0,sum/4,vis,0);
    }
};
