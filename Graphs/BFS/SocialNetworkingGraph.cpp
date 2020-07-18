#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e5+17;
vector<ll> vs[maxn];
ll truth[maxn];
ll c[maxn];

//earlier i declared the value of 'maxn' as 1e8+17, which gives a '.bss' error in local gnu compiler.
//set 'maxn' to a much lower value to avoid memory issues.

//Problem Link: https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/social-networking-graph/description/
void call(ll st, ll fi){
  c[st] = 0;
  queue<ll> q;
  q.push(st);
  truth[st] = 1;
  ll cnt = 0;
  while(!q.empty()){
    ll temp = q.front();
    for(ll i:vs[temp]){
      if(!truth[i]){
        truth[i] = 1;
        c[i] = c[temp] + 1;
        if(c[i]==fi) cnt++;
        q.push(i);
      }
    }
    q.pop();
  }
  cout << cnt << endl;
}

int main(){
  ll n,e;
  cin >> n >> e;
  for(ll i=0;i<e;i++){
    ll a,b;
    cin >> a >> b;
    vs[a].push_back(b);
    vs[b].push_back(a);
  }
  ll m;
  cin >> m;
  while(m--){
    ll st,fi;
    cin >> st >> fi;
    memset(c,0,maxn);  //'memset' is a useful method to reinitialize an array.
    memset(truth,0,maxn); // use 'memset' method with arrays only and for vectors use 'fill_in' (didn't work tho!!) better use 'memset' only.
    call(st,fi);
  }
  return 0;
}
