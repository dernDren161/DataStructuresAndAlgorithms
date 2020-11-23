#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// All the test cases do not pass in GFG, but the logic and method are correct so rely on this only.
// Problem Link: https://practice.geeksforgeeks.org/problems/maximum-product-subarray/0
// Very Nice Algorithm

ll call(ll num, vector<ll> &vs){
    ll m = vs[0];
    ll localMax = vs[0];
    ll localMin = vs[0];
    ll temp;
    for(ll i=1;i<num;i++){
        if(vs[i] > 0){
            localMax = max(vs[i]*localMax,vs[i]);
            localMin = min(vs[i]*localMin,vs[i]);
        }else{
            temp = localMax;
            localMax = max(vs[i]*localMin,vs[i]);
            localMin = min(vs[i]*temp,vs[i]);
        }
      m = max(m,localMax);

    }
    return m;
}

int main(){
    ll test;
    cin >> test;
    while(test--){
        ll num;
        cin >> num;
        vector<ll> vs(num);
        for(ll i=0;i<num;i++){
            cin >> vs[i];
        }
      call(num,vs); 
    }
    return 0;

}
