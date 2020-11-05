// Video Link: https://www.youtube.com/watch?v=3RhGdmoF_ac&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=15

#include<bits/stdc++.h>
using namespace std;

int call(int arr[], int key){
    int l = 0;
    int r = 4;

    while(l<=r){
      int m = l+(r-l)/2;

      if(arr[m]==key) return m;
      else if(arr[m] > key) r = m-1;
      else if(arr[m] < key) l = m+1;
    }

    // till here 'l' and 'r' are interchanged.

    return r;
}

int main(){
  int key = 12;
  int arr[5] = {1,3,8,10,15};
  int t = call(arr,k);
  if(abs(arr[t]-key) < abs(arr[t+1]-key)) {
    cout << "The minimum difference is: " << abs(arr[t]-key);
    return 0;
  }
  cout << "The minimum difference is:" << abs(arr[t+1]-key);
  return 0;
}
