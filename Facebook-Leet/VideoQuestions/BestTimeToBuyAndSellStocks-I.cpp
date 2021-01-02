// Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/

// NOTE: This question used the logic of (Finding the maximum difference between two elements in an array)

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        if(n==0 || n==1) return 0;

        int temp = prices[1]-prices[0]; // as the preogression is: from smaller to larger

        int x;

        int m =temp;

        // 'temp' is designed to store the maximum value

        for(int i=1;i<n-1;i++){

            x = prices[i+1]-prices[i];

            if(temp > 0){
                temp = temp + x;
            }else{
                temp = x; // hence 'temp' was designed to store the maximum value.
            }

         m = max(m,temp);
        }

        if(m<0) return 0; // means in descending order

        return m;
    }
};
