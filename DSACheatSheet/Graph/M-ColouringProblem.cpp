// Problem Link: https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

// TC: O(m^V), where m is the number of colours
// SC: O(V), where V is the number of vertices

bool isSafe(int c, bool graph[101][101], int m, int v, int node, int colours[]){

    for(int i=0;i<v;i++){
        if(graph[i][node]==1 && colours[i]==c && i!=node) return false;
    }

    return true;
}

bool call(bool graph[101][101],int m, int v, int node, int colours[]){

    if(node == v) return true;

    for(int i=1;i<=m;i++){
        if(isSafe(i,graph,m,v,node,colours)){
            colours[node] = i;

            if(call(graph,m,v,node+1,colours)) return true;
            colours[node] = 0;
        }
    }

    return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    int colours[V];
    memset(colours,0,sizeof(colours));

    return call(graph,m,V,0,colours);
}
