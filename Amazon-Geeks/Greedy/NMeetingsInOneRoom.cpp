#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Problem Link: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room/0

bool callingToSort(pair<int,int> m, pair<int,int> n){
    return (m.second < n.second);
}

void call(ll num, ll a[], ll b[]){
    vector<pair<ll,ll>> vs;
    for(ll i=0;i<num;i++){
        vs.push_back(make_pair(a[i],b[i]));
    }
    vector<pair<ll,ll>> old;
    old = vs;
    sort(vs.begin(),vs.end(),callingToSort);

    ll j = 0;
    auto ptr = find(old.begin(),old.end(),vs[j]);
    cout << distance(old.begin(),ptr)+1 << " ";
    for(ll k = 1; k<num;k++){
        if(vs[j].second <= vs[k].first){
            j = k;
            auto btr = find(old.begin(),old.end(),vs[k]);
            cout << distance(old.begin(),btr)+1 << " ";
        }
    }
    cout << endl;
}

int main(){
    ll test;
    cin >> test;
    while(test--){
        ll num;
        cin >> num;
        ll a[num]; ll b[num];
        for(ll i=0;i<num;i++){
            cin >> a[i];
        }
        for(ll i=0;i<num;i++){
            cin >> b[i];
        }
        call(num,a,b);
    }
}
