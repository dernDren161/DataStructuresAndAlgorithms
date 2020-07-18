#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> vs[1017];
ll truth[1017]={0};
map<ll,ll> mm;

// Problem Link: https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/bishu-and-his-girlfriend/description/

void call(ll ct, ll node){
    truth[node] = 1;
    mm[node] = ct;
    for(ll x : vs[node]){
        if(!truth[x]){
            call(ct+1, x); // Initially error because: I did "ct++"" and not "ct+1".
        }
    }
}

int main(){
    ll n;
    cin >> n;
    for(ll i=0;i<n-1;i++){
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        vs[a].push_back(b);
        vs[b].push_back(a);
    }
    for(ll i=0;i<n;i++){
        if(!truth[i]){
            call(0,i);
        }
    }
    ll q;
    cin >> q;
    ll maxi = 100000;
    ll point;
    for(ll k=0;k<q;k++){
        ll temp;
        cin >> temp;
        temp--;
        if(mm[temp]<maxi){
            maxi = mm[temp];
            point = temp+1;
        }

    }
    cout << point << endl;
    return 0;
}
