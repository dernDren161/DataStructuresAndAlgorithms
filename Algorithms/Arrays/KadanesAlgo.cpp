#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


// Also listed under "Arrays" as "MaximumSumSubArray"

ll call(ll arr[], ll n){
  ll localMax = 0;
  ll maximum = 0;
  ll start = 0;
  ll end = 0;
  ll s = 0;

  for(ll i=0;i<n;i++){

    if(arr[i] > localMax + arr[i]){
      start = i;
    }
    localMax = max(localMax + arr[i] , arr[i]);

    if(maximum < localMax){
      end = i;
    }
    maximum = max(maximum, localMax);
  }
  cout << "The index of start: " << start << " The index of end: " << end << endl;
  return maximum;
}

int main(){
  ll arr[8]={-2,-4,9,-1,8,5,-10,11};
  cout << "The maximum sum subarray is: " << endl;
  cout << call(arr,8) << endl;
  return 0;
}
