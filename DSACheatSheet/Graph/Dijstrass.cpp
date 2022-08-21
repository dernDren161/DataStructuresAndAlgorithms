#include<bits/stdc++.h>
using namespace std;

struct comp{
  bool operator()(pair<int,int>&a,pair<int,int>&b){
      return a.first > b.first;
  }
};

void callDijistra(vector<vector<pair<int,int>>>&adj,int source, vector<int>&dist){

    // pair -- {weight,source} with respect to the source we calculate everything
    priority_queue<pair<int,int>,vector<pair<int,int>>,comp>pq;
    pq.push({0,source});
    dist[source] = 0;

    while(!pq.empty()){
      auto f = pq.top();
      pq.pop();
      int x = f.second; int wt = f.first;

      for(auto y:adj[x]){
        int tempWt = y.first;
        int tempDest = y.second;

        if(dist[tempDest] > dist[x]+tempWt){
          dist[tempDest] = dist[x] + tempWt;
          pq.push({tempDest,dist[tempDest]});
        }
      }
    }

    return;
}

int main(){

  vector<vector<pair<int,int>>> adj; // source, {weight,destination}
  adj[0].push_back({2,1});
  adj[1].push_back({2,0});
  adj[0].push_back({15,2});
  adj[2].push_back({15,0});
  adj[1].push_back({1,2});
  adj[2].push_back({1,1});
  adj[1].push_back({5,3});
  adj[3].push_back({5,1});
  adj[2].push_back({3,4});
  adj[4].push_back({3,2});
  adj[3].push_back({8,5});
  adj[5].push_back({8,3});
  adj[4].push_back({1,5});
  adj[5].push_back({1,4});

  int source = 0;
  vector<int>dist(6,INT_MAX);
  callDijistra(adj,source,dist);

  cout << "Shortest distance is " << dist[5] << endl;

  return 0;
}
