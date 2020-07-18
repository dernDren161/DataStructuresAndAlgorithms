#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Problem Link: https://practice.geeksforgeeks.org/problems/leaders-in-an-array/0/?track=md-arrays&amp;batchId=144
void call(ll n, ll arr[]){
    vector<ll> vs;
    vs.push_back(arr[n-1]);
    ll m=arr[n-1];

    for(ll i=n-2;i>=0;i--){
        if(arr[i]>=m){
            m = arr[i];
            vs.push_back(m);
        }
    }
    reverse(vs.begin(),vs.end());
    for(ll x : vs)
        cout << x << " ";

    cout << endl;

}
int main(){
    ll test;
    cin >> test;
    while(test--){
        ll n;
        cin >> n;
        ll arr[n];
        for(ll i=0;i<n;i++)
            cin >> arr[i];
        call(n,arr);
    }
    return 0;
}
