// Problem Link: https://leetcode.com/problems/word-break/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // word break - type - I


        unordered_set<string> m(wordDict.begin(),wordDict.end());

        int n = s.size();

        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[n] = 1;

        for(int i=n-1;i>=0;i--){
            string res = "";
            for(int j=i;j<n;j++){
                res += s[j];

                auto p = m.find(res);
                if(p != m.end()){ // found
                    if(dp[j+1]==1){
                        dp[i] = 1;
                    }
                }
            }
        }

        if(dp[0]==1) return true;
        return false;
    }
};
