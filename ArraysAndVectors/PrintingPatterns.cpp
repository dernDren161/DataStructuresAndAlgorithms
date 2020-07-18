#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Problem Link: https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/waves-b18625d7/description/
// Can also be solved using DFS but done here using arrays.

int main(){
    ll r,c,a,b;
    cin >> r >> c >> a >> b;

    for(ll i=0;i<r;i++){
        for(ll j=0;j<c;j++){
            cout << max(abs(i-a),abs(j-b)) << " ";
        }
        cout << endl;
    }
    return 0;
}
