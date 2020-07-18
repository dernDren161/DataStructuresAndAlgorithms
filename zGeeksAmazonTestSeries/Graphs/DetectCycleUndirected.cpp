// Problem Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1/?track=amazon-graphs&batchId=192

// @ PUN , P - parent, UN - undirected
bool call(bool* truth, int i, vector<int> g[], int parent){
    truth[i] = true;
    for(int x : g[i]){
        if(!truth[x]){
            if(call(truth,x,g,i)) return true;
        }
        else if(x != parent) return true;
    }
    return false;
}

bool isCyclic(vector<int> g[], int V)
{

   bool* truth = new bool[V];
   memset(truth,false,V);

   for(int i=0;i<V;i++){
    if(!truth[i]){
       if (call(truth,i,g,-1)) return true;
    }
   }
   return false;

}
