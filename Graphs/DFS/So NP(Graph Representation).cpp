#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e5+17;
vector<ll> vs[maxn];
bool trut[maxn];
ll cnt = 0;
// Basic of Graph representation.
// this is just to connect the entire graph with "one connectivity"

// Problem Link: https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/so-np-c559f406/
void dfsf(ll o){
    trut[o] = 1;
    for(ll u : vs[o]){
        if(!trut[u]) dfsf(u);
    }
}

int main(){
    ll n,m,k;
    ll a,b;
    cin >> n >> m >> k;
    for(ll i=0;i<m;i++)
        cin >> a >> b,
        a--,
        b--,
        vs[a].push_back(b),
        vs[b].push_back(a);

    for(ll i=0;i<n;i++){
        if(!trut[i]){
            dfsf(i);
            cnt++;
        }
    }

    // we know: number of nodes(n) - graph componenets(k) = minimum edge that should be in the entire graph(e)

    cout << (cnt > k) ? -1 : (m-n+k) << '\n';
    return 0;
}
