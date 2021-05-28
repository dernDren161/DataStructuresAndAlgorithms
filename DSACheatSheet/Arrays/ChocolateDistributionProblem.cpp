// Problem Link: https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1#

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    long long mini = INT_MAX;

    sort(a.begin(),a.end());

    for(long long i=0;i<=n-m;i++){
        mini = min(mini,a[m+i-1]-a[i]);
    }

    return mini;

    }
};
