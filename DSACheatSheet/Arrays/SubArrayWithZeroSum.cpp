// Problem Link: https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1#

class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        map<int,int>m;
        m[0] = 1;

        int s = 0;

        for(int i=0;i<n;i++){
            s += arr[i];

            auto x = m.find(s);
            if(x != m.end()) return true;
            m[s]++;
        }
        return false;
    }
};
