#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
set<pair<ll,ll>> ans;
ll n;

void call(ll r,ll c, ll i){
    if(r<1 || c<1 || r>10 || c>10) return;
    if(i==n){ ans.insert({r,c});}
    else{
    call(r-2,c-1,i+1);
    call(r-2,c+1,i+1);
    call(r+2,c+1,i+1);
    call(r+2,c-1,i+1);
    call(r-1,c+2,i+1);
    call(r-1,c-2,i+1);
    call(r+1,c+2,i+1);
    call(r+1,c-2,i+1);
        }

}

int main(){
    ll r,c;
    cin >> r >> c>> n;
    call(r,c,0);
    cout << ans.size() <<endl;
}
