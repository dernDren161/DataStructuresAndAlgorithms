#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Question Name: Prefix Reversal to sort the given array. (Nice Problem!!)

// Problem Link: https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/t1-1-6064aa64/description/

ll call(ll arr[], ll test){
	string before = "";
	string after = "";
	for(ll i=0;i<test;i++){
		before += to_string(arr[i]);
	}
	sort(arr,arr+test);
	for(ll i=0;i<test;i++){
		after += to_string(arr[i]);
	}

	queue<string> qs;
	map <string,ll> m;

	if(before == after){
		return 0;
	}

	string r;
	qs.push(before);
	m[before] = 0;
	while(!qs.empty()){
        string temp = qs.front();
		//temp = qs.front().first;
		for(ll x=2;x<=test;x++){
            r = temp;
			reverse(r.begin(),r.begin()+x);
			// This is the optimized step, very crutial for the complte execution of this programme.
			if(m.find(r)==m.end()){
				m[r] = m[temp] + 1;
				qs.push(r);
			}
			if(r == after){
				return m[r];
			}

		}
		qs.pop();
	}
}

int main(){
	ll test;
	cin >> test;
	ll arr[test];
	for(ll p=0;p<test;p++){
		cin >> arr[p];
	}
	//for(auto &w : arr){
	//	cin >> arr[w];
	//}

	cout << call(arr,test) << endl;
	return 0;
}
