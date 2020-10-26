// Problem Link: https://www.youtube.com/watch?v=zr_AoTxzn0Y&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=5
// Code Link: https://www.youtube.com/watch?v=dVXy6hmE_0U

#include<bits/stdc++.h>
using namespace std;

int call(int arr[], int l, int r, int x){

    int result = -1;
    while(l<=r){

      int m = l + (r-l)/2;
      if(arr[m] == x){
        result = m;
        r = m-1;
      }else if(arr[m] > x){
        result = m;
        r = m-1;
      }else{ // i.e arr[m] < x
        l = m+1;
      }
    }

    return result;

}
int main(){
  int arr[] = {1,3,5,6,6,6,6,6,8,9,10}; // a sorted array
  int n = 11;
  int x = 6; // number to be found
  int firstElementIndex = call(arr,0,n-1,x);
  int rightElementIndex = (call(arr,0,n-1,x+1)) - 1;

  cout << "The leftmost index is: " << firstElementIndex << endl;
  cout << "The rightmost index is: " << rightElementIndex << endl;

  return 0;
}
