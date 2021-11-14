
// Problem Link: https://leetcode.com/problems/decode-ways/submissions/

class Solution {
public:
    int numDecodings(string s) {

        // 2 1 4 6 3
        // if dp[i] where dp[i] represents the ways to decode till ith index
        // dp[i] = dp[i-1] + dp[i-2]

        int n = s.size();

        if(s[0]=='0') return 0;
        if(n==0) return 0;

        int dp[n];
        memset(dp,0,sizeof(dp));

        // the bottom up approach here would be

        dp[0] = 1;

        int temp;

        for(int i=1;i<n;i++){
            temp = stoi(s.substr(i-1,2)); // 21
            if(temp >= 1 && temp<=26 && s[i-1]!='0'){// it can also be 08, for that s[i-1]!=0
                if(i-2>=0){ // when it is not the first two characters of the string where we can take 'i-2'
                    dp[i] = dp[i-2];
                }else{
                    dp[i] = 1; // It's actually 2 but we add later on after this to make it two
                }
            }
            if(s[i] != '0') dp[i] = dp[i] + dp[i-1]; // as dp[i] was already changed to dp[i-2] earlier
        }

        return dp[n-1];

    }
};
