// Time Complexity: O(V+E), where V,E are the number of vertices and edges respectively

int dist[v];
int predes[v];
memset(dist,INT_MAX,v);
memset(predes,-1,v);

bool callBFS(vector<int> adj[], int source, int destination, int v, bool visited[]){

  visited[source] = true;

  queue<int> qs;
  qs.push(source);
  dist[source] = 0;

  while(!qs.empty()){
    int f = qs.front();
    qs.pop();

    for(int i=0;i<adj[f].size();i++){
      if(!visited[adj[f][i]]){
        dist[adj[f][i]] = 1 + dist[f];
        visited[adj[f][i]] = true;
        predes[adj[f][i]] = f;
        qs.push(adj[f][i]);
      }

      if(adj[f][i]==destination) return true;
    }
  }

  return false;

}
vector<int> ShortestDistance(vector<int> adj[], int source, int destination, int v){

  bool visited[v];
  memset(visited,false,v);

  if(!callBFS(adj,source,destination,v,visited)){
    cout << "There is no conncetion between the source and destination" << endl;
    return {};
  }

  // Printing the results

  vector<int> res;
  res.push_back(destination);

  // The shortest distance is: dist[destination]

  while(predes[destination] != -1){
    res.push_back(predes[destination]);
    destination = predes[destination];
  }

  return res;
}
