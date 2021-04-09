// Problem Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1/?track=amazon-graphs&batchId=192

bool call(vector<int> adj[], int n, int i, bool* cross, bool* truth){

  truth[i] = true;
  cross[i] = true;

  for(int x : adj[i]){
      if(cross[x])// this is the basic, if this 'x' is visited already return true
      return true;
      if(!truth[x] && call(adj,n,x,cross,truth))// even though it's not visited but its subordintes are visited then pass true
      return true;
  }

  // Backtracking.

  cross[i] = false;
  return false;
}

bool isCyclic(int V, vector<int> adj[])
{
  bool* truth = new bool[V];
  bool* cross = new bool[V];

  memset(truth,false,V);
  memset(cross,false,V);

  for(int i = 0; i < V; i++) {
    if(truth[i] == false && call(adj,V,i,cross,truth))
    return true;
  }
  return false;
}
