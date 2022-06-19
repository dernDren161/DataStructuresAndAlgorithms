// Problem Link: https://leetcode.com/contest/biweekly-contest-79/problems/maximum-total-importance-of-roads/

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {

        // calculating the indegrees
        vector<int>inDegrees(n);

        for(auto x:roads){
            inDegrees[x[0]]++;
            inDegrees[x[1]]++;
        }

        sort(inDegrees.begin(),inDegrees.end());

        long long assign = 1;

        long long ans = 0;

        for(int i=0;i<inDegrees.size();i++){
            ans += (inDegrees[i] * assign);
            assign++;
        }

        return ans;
    }
};
