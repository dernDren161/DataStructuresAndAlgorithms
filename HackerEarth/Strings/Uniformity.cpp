#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//The Algorithm used here is quite fascinating
// Problem Link : https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/uniformity-794d7bdc/description/
int main(){
	ll l;
	ll k;
	cin >> l >> k;
	string s;
	cin >> s;
	vector<ll> vs(3);
	ll r=0;
	ll answer = 0;
	ll c1=0;
	ll c2=0;
	ll c3=0;
	for(ll i=0;i<l;i++){
		while(r<l){

			if(s[r]=='a') c1++;
			else if(s[r]=='b') c2++;
			else if(s[r]=='c') c3++;
			vs[0]=c1;
			vs[1]=c2;
			vs[2]=c3;
			r++;
			sort(vs.begin(),vs.end());
			if((vs[0]+vs[1])>k) break;
			answer = max((c1+c2+c3),answer);
		}
		if(s[i]=='a') c1--;
		else if(s[i]=='b') c2--;
		else if(s[i]=='c') c3--;
	}
	cout << answer << endl;
	return 0;
}
