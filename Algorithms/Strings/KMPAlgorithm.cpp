#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long maxn = 1e5 +17;
ll lps[maxn];

void preprocessing(ll m, string& t, string& p){
  ll l = 0;
  ll i = 1;
  lps[0] = 0;
  while(i<m){
    if(p[i]==p[l]){
      l++;
      lps[i] = l;
      i++;
    } else{
      if(l != 0){
        l = lps[l-1];
      }else{
        lps[i] = 0;
        i++;
      }
    }
  }
}

void logic(ll m, string& t, string& p){
  ll i = 0;
  ll j = 0;
  ll n = t.size();
  while(i<n){
    if(t[i]==p[j]){
      i++;
      j++;
    }
    if(j==m){
      cout << "Testing" << endl;
      cout<<"Pattern found at location: " << i-j << endl;
      j = lps[j-1];
    }
    else if(i<n && (t[i] != p[j])){
      if(j!=0){
        j = lps[j-1];
      }
      else{
        i = i+1;
      }
    }
  }
}

int main(){
  string t = "ABABDABACDABABCABAB";
  string p = "ABABCABAB";
  ll n = t.size();
  ll m = p.size();
  preprocessing(m,t,p);
  logic(m,t,p);
  return 0;
}
