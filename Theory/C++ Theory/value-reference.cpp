#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void call1(ll arr[]){
  //cout << "Size of arr with arr1(on calling)  " << sizeof(arr) << endl;
  arr[3] = 1000;
  for(ll i=0;i<5;i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main(){
  ll arr[5];
  for(ll i=0;i<5;i++){
    arr[i] = i+2;
  }
  cout << "Before all the changes ";
  for(ll i=0;i<5;i++){
    cout << arr[i] << " ";
  }
  cout << "Size of arr with arr1  " << sizeof(arr) << endl;
  call1(arr);
  for(ll i=0;i<5;i++){
    cout << arr[i] << " ";
  }
  return 0;
}
