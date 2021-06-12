// Problem Link: https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1#

class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    bool visited[V];
	    memset(visited,false,V);

	    queue<int>qs;
	    qs.push(0);
	    visited[0] = true;

	    vector<int> ans;

	    while(!qs.empty()){
	        int f = qs.front();
	        qs.pop();
	        ans.push_back(f); // NOTE: notice that from 0 itself it starts being put from here.

	        for(int i=0;i<adj[f].size();i++){
	            if(!visited[adj[f][i]]){
	                  visited[adj[f][i]] = true;
	                  qs.push(adj[f][i]);
	            }
	        }
	    }
	    return ans;
	}
};
