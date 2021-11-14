// Problem Link: https://leetcode.com/explore/interview/card/top-interview-questions-easy/102/math/744/

class Solution {
public:
    int countPrimes(int n) {

        if(n<=0) return 0;
        int m = n-1;

        bool dp[m+1];
        memset(dp,true,sizeof(dp));

        for(int i=2;i*i<=m;i++){
            if(dp[i]){
                for(int j=2*i;j<=m;j+=i){
                    dp[j] = false;
                }
            }
        }

        int c = 0;
        for(int i=2;i<=m;i++){
            if(dp[i])c++;
        }

        return c;
    }
};
