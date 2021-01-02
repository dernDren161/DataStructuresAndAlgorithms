// Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/submissions/

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        if(n==0 || n == 1) return 0;

        int ans = 0;

        for(int i=0;i<n-1;i++){

            if(prices[i+1]>prices[i]) ans = ans + (prices[i+1]-prices[i]);
        }

        if(ans < 0) return 0;

        return ans;
    }
};
