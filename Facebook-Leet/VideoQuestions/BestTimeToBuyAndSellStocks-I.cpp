// Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/

// NOTE: This question used the logic of (Finding the maximum difference between two elements in an array)

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        int less[n];
        int more[n];

        less[0] = prices[0];
        more[n-1] = prices[n-1];

        for(int i=1;i<n;i++){
            less[i] = min(less[i-1],prices[i]);
        }

        for(int i=n-2;i>=0;i--){
            more[i] = max(more[i+1],prices[i]);
        }

        int m =0;

        // All same, except for the line below.
        /*
        int x,y=0;
        while(x<n && y<n){
        if(more[y]>=less[x]){
          m = max(m,y-x);
          y++;
        }else x++;
      }
        */
        for(int i=0;i<n;i++){
            m = max(m,more[i]-less[i]);
        }

        return m;
    }
};
