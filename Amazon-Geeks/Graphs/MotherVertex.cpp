// Problem Link: https://practice.geeksforgeeks.org/problems/mother-vertex/1/?track=amazon-graphs&batchId=192

// Based on the principle that: while doing DFS in a directed graph, the very last vertex is one of the Mother Vertices.
// Fun Fact: This way we get the very first encountered mother vertex.

void call(bool* truth, vector<int> g[], int i){
    truth[i] = true;

    for(int x : g[i]){
        if(!truth[x]){
        call(truth,g,x);
        }
    }
}



int findMother(int V, vector<int> g[])
{
   bool* truth = new bool[V];
   memset(truth,false,V);
   int temp = 0;

   for(int i=0;i<V;i++){
       if(!truth[i]){
           call(truth,g,i);
           temp = i;
       }
   }



  memset(truth,false,V);
   call(truth,g,temp);
   for(int i=0;i<V;i++){
       if(!truth[i]) return -1;
   }
   return temp;
 }
