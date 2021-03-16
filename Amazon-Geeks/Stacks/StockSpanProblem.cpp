// Problem Link: https://practice.geeksforgeeks.org/problems/stock-span-problem/0#
// Just a variation of Next Greater to left

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> call(ll arr[], ll n){

    vector<ll> vs;// consists of indices only
    // number - index
    stack<pair<ll,ll>> st;

    for(ll i=0;i<n;i++){
        if(st.empty()) vs.push_back(-1);
        else if(st.size()>0 && st.top().first>arr[i]){
            vs.push_back(st.top().second);
        }else if(st.size()>0 && st.top().first<=arr[i]){//sliding window problem aditya verma
            while(st.size()>0 && st.top().first<=arr[i]) st.pop();
            if(st.empty()) vs.push_back(-2);
            else vs.push_back(st.top().second);
        }
        st.push({arr[i],i});
    }
    for(ll i=0;i<n;i++){
        if(vs[i]==-1) vs[i]=1;
        else if(vs[i] == -2){
            vs[i] = i+1;
        }
        else{
            vs[i] = i - vs[i];
        }
    }

    return vs;
}

int main(){
    ll test;
    cin >> test;
    while(test--){
        ll num;
        cin >> num;
        ll arr[num];
        for(ll i=0;i<num;i++){
            cin >> arr[i];
        }
        vector<ll> vs;
        vs = call(arr,num);
        ll s = vs.size();
        for(ll i=0;i<s;i++){
            if(i==s-1){
                cout << vs[i];
                break;
            }
            cout << vs[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
