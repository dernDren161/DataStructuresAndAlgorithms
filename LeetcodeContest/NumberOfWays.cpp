// Problem Link: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

#define ll long long int
const ll M = 1e9 + 7;
#define MOD_ADD(a,b,m) ((a % m) + (b % m)) % m

class Solution {
public:

    static bool compare(pair<ll,ll> a, pair<ll,ll> b)
    {
        return a.second > b.second; // min heap
    }

    vector<ll> dikstra(ll src, vector<vector<pair<ll,ll>>> &adj, ll n)
    {
        vector<ll> dis(n, 1e18); //1e18 is imp here
        vector<bool> vis(n, 0);

        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, function<bool(pair<ll,ll>, pair<ll,ll>)>> Q(compare);

        Q.push({src, 0});

        while(!Q.empty())
        {
            pair<ll,ll> now = Q.top(); Q.pop();

            ll u = now.first;

            if(vis[u]) continue;
            vis[u] = 1;
            dis[u] = now.second;

            for(auto x : adj[u])
            {
                ll v = x.first;
                ll w = x.second;

                if(dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                    Q.push({v, dis[v]});
                }
            }
        }

        return dis;
    }

    vector<ll> toposort(vector<vector<ll>> &adj, ll n)
    {
        vector<ll> ans;
        ll indegree[n]; memset(&indegree, 0x00, sizeof(indegree));
        for(int u = 0; u < n; u++)
        {
            for(auto v : adj[u])
                indegree[v]++;
        }


        queue<ll> q;
        for(int i = 0; i < n; i++) if(!indegree[i]) q.push(i);

        while(!q.empty())
        {
            ll u = q.front(); q.pop();
            ans.push_back(u);

            for(auto v : adj[u])
            {
                indegree[v]--;
                if(!indegree[v]) q.push(v);
            }
        }

        return ans;
    }

    int countPaths(int n, vector<vector<int>>& roads)
    {
        vector<vector<pair<ll,ll>>> adj(n);
        for(auto e : roads)
        {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<ll> dis = dikstra(0, adj, n);

        vector<vector<ll>> DAG(n);
        for(auto e : roads)
        {
            ll u = e[0];
            ll v = e[1];
            ll w = e[2];

            if(dis[u] + w == dis[v])
            {
                //include this edge u -> v
                DAG[u].push_back(v);
            }
            else if(dis[v] + w == dis[u])
            {
                //include this edge v -> u
                DAG[v].push_back(u);
            }
        }

        vector<ll> topo = toposort(DAG, n);

        ll dp[n]; memset(&dp, 0x00, sizeof(dp));
        dp[n - 1] = 1;

        for(int i = n - 1; i >= 0; i--)
        {
            ll u = topo[i];
            if(u == n - 1) continue;

            for(auto v : DAG[u]) dp[u] = MOD_ADD(dp[u], dp[v], M);
        }

        return dp[0];

    }
};
