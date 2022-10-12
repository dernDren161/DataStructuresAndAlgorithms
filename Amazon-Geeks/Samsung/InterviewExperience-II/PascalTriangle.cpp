// Problem Link: https://practice.geeksforgeeks.org/problems/pascal-triangle0652/1#

#define ll long long

class Solution{
public:

    ll mod=1e9+7;

    vector<ll> nthRowOfPascalTriangle(int n) {

    ll int arr[n][n];


    for (ll int line = 0; line < n; line++)
    {

        for (ll int i = 0; i <= line; i++)
        {

        if (line == i || i == 0)
            arr[line][i] = 1;

        else
            arr[line][i] = (arr[line - 1][i - 1]%mod + arr[line - 1][i]%mod)%mod;
        }
    }
    vector<ll> ans;
    for(int i=0;i<n;i++)
    {
        ll temp=arr[n-1][i]%mod;
        ans.push_back(temp);
    }
    return ans;
    }

};
