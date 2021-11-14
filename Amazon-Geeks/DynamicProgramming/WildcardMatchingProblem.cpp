// Problem Link: https://leetcode.com/problems/wildcard-matching/


class Solution {
public:

    int call(string s, string p, int sIndex, int pIndex, int dp[][1001]){

        if(sIndex==-1 && pIndex==-1) return 1;
        if(pIndex == -1){ // pattern completes before the string
            return 0;
        }
        if(sIndex == -1){ // string completes before the pattern
            for(int i=0;i<pIndex;i++){
                if(p[pIndex] != '*') return 0;
            }
            return 1;
        }

        if(dp[sIndex][pIndex] != -1) return dp[sIndex][pIndex];

        if(s[sIndex] == p[pIndex] || p[pIndex]=='?') return dp[sIndex][pIndex] = call(s,p,sIndex-1,pIndex-1,dp);

        if(p[pIndex]=='*'){
            return dp[sIndex][pIndex] = call(s,p,sIndex-1,pIndex,dp) || call(s,p,sIndex,pIndex-1,dp);
        }

        return dp[sIndex][pIndex] = 0;  // NOTE: CONDITION FOR FALSE
    }

    bool isMatch(string s, string p) {

        int dp[1001][1001];
        memset(dp,-1,sizeof(dp));

        int res = call(s,p,s.size()-1,p.size()-1,dp);

        return res;
    }
};
