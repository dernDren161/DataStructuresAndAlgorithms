// Problem Link: https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1#

class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
         priority_queue<long long,vector<long long>,greater<long long>> pq;
         for(long long i=0;i<n;i++){
             pq.push(arr[i]);
         }

         long long s = 0;
         long long a,b;
         long long temp=0;

         while(pq.size()>=2){
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            temp = a + b;
            pq.push(temp);
            s += temp;
            temp = 0;
         }



         return s;
    }
};
