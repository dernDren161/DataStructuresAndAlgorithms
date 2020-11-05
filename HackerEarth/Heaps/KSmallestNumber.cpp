#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//Time Complexity of this algo: O(nlogk) // k is the size of the heap
// Unlike the plain sorting alog: O(nlogn)

ll call(ll num, ll k, vector<ll> &vs){
  // Smallest number - So maxHeap;
  // @ming - so no need of greater;
  priority_queue<ll,vector<ll>> p(vs.begin(),vs.begin()+k);
  for(ll i=k;i<num;i++){
    if(vs[i]<p.top()){
      p.pop();
      p.push(vs[i]);
    }
  }
  return p.top();
}

int main(){
  ll num;
  cout << "Enter the desired size of the array  ";
  cin >> num;
  cout << "Enter the value of k  ";
  ll k;
  cin >> k;
  vector<ll> vs(num);
  for(ll i=0;i<num;i++){
    cin >> vs[i];
  }
  ll temp = call(num,k,vs);
  cout << "The answer is:  " << temp << endl;
  return 0;
}
