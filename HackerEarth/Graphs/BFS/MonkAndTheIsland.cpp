#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// This question basically clears the concept of using BFS in a program.
// Problem Link : https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/monk-and-the-islands/

void bfss(vector<ll> &visited, vector<ll> vs[],ll x, ll node){
  ll ans = 0;
  queue<pair<ll,ll>> q;
  visited[node] = true;
  q.push(make_pair(0,node));
  while(!q.empty()){
    ll temp = q.front().second;
    if(q.front().second==x-1){
      ans = q.front().first;
      break;
    }
    for(ll i:vs[temp]){

      if(!visited[i]){
        visited[i] = true;
        q.push(make_pair(q.front().first+1,i));
      }
    }
    q.pop();
  }
  cout << ans << endl;

}
int main(){
  ll test;
  cin >> test;
  while(test--){
    ll x,y;
    cin >> x >> y;
    vector<ll> vs[x];
    for(ll i=0;i<y;i++){
      ll a,b;
      cin >> a >> b;
      vs[a-1].push_back(b-1);
      vs[b-1].push_back(a-1);
    }
    vector<ll> visited(x);
   fill_n(visited.begin(),x,false);
    bfss(visited, vs,x,0);
  }
  return 0;
}
