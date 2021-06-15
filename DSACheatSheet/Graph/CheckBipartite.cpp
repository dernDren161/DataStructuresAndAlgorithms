// Problem Link: https://www.geeksforgeeks.org/bipartite-graph/
// TC here is: O(V+E), as it is an adjacency list.
// Had it been an Adjacency matrix then it would have been O(V^2)

#include <bits/stdc++.h>
using namespace std;

bool isBipartite(int V, vector<int> adj[])
{

	vector<int> col(V, -1);

	queue<pair<int, int> > q;


	for (int i = 0; i < V; i++) {


		if (col[i] == -1) {


			q.push({ i, 0 });
			col[i] = 0;

			while (!q.empty()) {
				pair<int, int> p = q.front();
				q.pop();


				int v = p.first;

				int c = p.second;

				for (int j : adj[v]) {


					if (col[j] == c)
						return 0;


					if (col[j] == -1) {
				col[j] = (c) ? 0 : 1;
						q.push({ j, col[j] });
					}
				}
			}
		}
	}

	return 1;
}



int main()
{

	int V, E;
	V = 4 , E = 8;

	vector<int> adj[V];
	adj[0] = {1,3};
	adj[1] = {0,2};
	adj[2] = {1,3};
	adj[3] = {0,2};


	bool ans = isBipartite(V, adj);

	if (ans)
		cout << "Yes\n";

	else
		cout << "No\n";

	return 0;
}
