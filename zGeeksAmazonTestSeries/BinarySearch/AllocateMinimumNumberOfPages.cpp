// Problem Link: https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages/0#
// Video Link: https://www.youtube.com/watch?v=2JSQIhPcHQg&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=21

// NOTE: Related to 'Painter Partition problem'

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isGood(ll arr[], ll m,ll n, ll k){
    ll s = 0;
    ll person = 1;
    for(ll i=0;i<n;i++){
        if(arr[i] > m) return false; // Important base case.
        s += arr[i];
        while(m < s){ // means go to next person
            person++;
            s = arr[i];
            if(person > k) return false;
        }
    }

    if(person > k) return false;
    return true;

}

ll call1(ll arr[], ll n, ll l, ll r, ll k){

    ll res = -1;

    if(n < k) return -1; // Important base case. // NOTE: This is by far the most important base case, without which the code won't run.
    while(l<=r){
        ll m = l + (r-l)/2;  // actually it's an array element
        if(isGood(arr,m,n,k)){
            r = m-1;
            res = m;
        }else{
            l = m+1;
        }
    }

    return res;

}
int main(){
    ll test;
    cin >> test;
    while(test--){
        ll num;
        cin >> num;
        ll k;
        ll arr[num];
        ll s = 0;
        ll m = INT_MIN;
        for(ll i=0;i<num;i++){
            cin >> arr[i];
            s += arr[i];
            if(arr[i] > m) m = arr[i];
        }
        cin >> k;

        cout << call1(arr,num,m,s,k) << endl;
    }
    return 0;
}
