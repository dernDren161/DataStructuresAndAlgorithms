// Problem Link: https://practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1#

class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        // your code here
        int arr[n+1];
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 2;

        for(int i=3;i<=n;i++){
            arr[i] = (arr[i-1] + arr[i-2])%1000000007;
        }

        return arr[n];
    }
};
