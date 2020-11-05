
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Fun Facts:
// Time complexity : O(nlogn)  ->> this is in all three cases i.e Worst, Best and Average.
// Auxillary Space : O(n)  ---- which is the temporary size of memory used.
// Algorithm Paradigm : Divide and Conquer

void mergeIt(ll arr[], ll l, ll r, ll m){
  ll left = m-l+1;
  ll right = r-m; // when in confusion: add left and right you should be getting:  (r-l+1), which is the size of the entire array.
  ll L[left];
  ll R[right];
  for(ll i=0;i<left;i++){
    L[i] = arr[i+l];
  }
  for(ll i=0;i<right;i++){
    R[i] = arr[m+1+i];
  }
  ll a = 0;
  ll b = 0;
  ll k = l; // Remember this point.
  while(a<left && b<right){
    if(L[a] <= R[b]){
      arr[k] = L[a];
      a++;
      k++;
    }else{
      arr[k] = R[b];
      b++;
      k++;
    }
  }

  // if incase there are any left elements in the right and left arrays then just store them in arr.
  // directly store them at arr, since the left elements had already been sorted, hence no problem!!!
  while(a < left){
    arr[k] = L[a];
    a++;
    k++;
  }

  while(b < right){
    arr[k] = R[b];
    k++;
    b++;
  }
}

void call(ll arr[],ll l, ll r){
  if(l < r){
    ll m = l + (r-l)/2;
    call(arr,l,m);
    call(arr,m+1,r);
    mergeIt(arr,l,r,m);
  }
}

int main(){
  ll arr[8] = {5,9,2,1,7,6,0,3};
  cout << "Before sorting the elements, the elements are listed as: " << endl;
  for(ll i : arr){
    cout << i << " " ;
  }
  cout << endl ;
  ll n = 8;
  call(arr,0,n-1);
  cout << "After Merge sort, the elemets in the same array are: " << endl;
  for(ll k: arr){
    cout << k << " ";
  }
  cout << endl;
  return 0;

}
