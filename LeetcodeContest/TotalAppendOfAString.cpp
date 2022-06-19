// Problem Link: https://leetcode.com/problems/total-appeal-of-a-string/

class Solution {
public:
    long long appealSum(string s) {

        int n = s.size();

        int prev[26];
        memset(prev,0,sizeof(prev));

        long long ans = 0;

        for(int i=0;i<s.size();i++){
            ans += (i+1-prev[s[i]-'a']) * (n-i);
            prev[s[i]-'a'] = i+1;
        }

        return ans;
    }
};
