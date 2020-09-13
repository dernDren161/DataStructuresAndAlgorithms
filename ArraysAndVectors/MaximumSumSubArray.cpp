#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll call(ll arr[], ll n){
  ll localMax = arr[0];
  ll maximum = arr[0];

  for(ll i=1;i<n;i++){
    localMax = max(localMax + arr[i] , arr[i]);
    maximum = max(maximum, localMax);
  }
  return maximum;
}

int main(){
  ll arr[8]={-2,-4,9,-1,8,5,-10,11};
  cout << "The maximum sum subarray is: " << endl;
  cout << call(arr,8) << endl;
  return 0;
}
