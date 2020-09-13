#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll call(ll num, vector<ll> &arr, ll k){
  // Since Largest - So MinHeap to be used;
  // @ Ming - where 'g' - greater;
  priority_queue<ll,vector<ll>,greater<>> p(arr.begin(),arr.begin()+k);
  for(ll i=k;i<num;i++){
    if(arr[i]>p.top()){
      p.pop();
      p.push(arr[i]); // careful as it is queue/stact so "push" used instead of "push_back";
    }
  }
  return p.top();
}
  
int main(){
  cout << "Enter the desired size of the array " << endl;
  ll num;
  cin >> num;
  cout << "Enter the value of k" << endl;
  ll k;
  cin >> k;
  vector<ll> arr(num);
  for(ll i=0;i<num;i++){
    cin >> arr[i];
  }

  ll temp = call(num,arr,k);
  cout << "The required answer is : " << temp << endl;
  return 0;
}
