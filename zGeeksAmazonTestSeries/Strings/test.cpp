#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string call(string s, int k){
		int stringSize = s.size();

		string dummy = "";
		int temp = 0;
		int kam = k;
		for(int i = 0; i<(stringSize/k); i++){
			dummy += string(s.rbegin()+temp,s.rbegin()+kam);
			//dummy += reverse(s.begin()+temp,s.begin()+kam);
			temp += kam;
			kam += k;
		}
		return dummy;
}

int main(){
	string s = "amazoninterview";
	cout << call(s,5) << endl;
	return 0;
}
