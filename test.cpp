#include<bits/stdc++.h>
using namespace std;

int call(vector<int> &arr) {
    // add your logic here
	unordered_map<int,int>m;
	m.clear();
	for(int x:arr)m[x]++;

	int ans = 0;
	for(auto a:m){

			int temp = a.second;
			ans = ans + ((temp/2)*(temp-1));

	}

	return ans;
}

int main(){
  vector<int> arr = {5 ,1 ,2 ,3, 2 ,1};
   
  cout << call(arr) << endl;

  return 0;
}
