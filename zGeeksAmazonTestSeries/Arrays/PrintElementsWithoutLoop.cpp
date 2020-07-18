#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void call(int num){

   if(num == 0) return;
   call(num-1);
   cout << num;
}


int main() {

	int test;
	cin >> test;
	while(test--){
	    int num;
	    cin >> num;
	    call(num);
	    cout << endl;
	}
	return 0;
}
