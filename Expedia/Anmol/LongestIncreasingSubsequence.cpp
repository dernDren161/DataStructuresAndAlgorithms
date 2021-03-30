// This question follows the 'Patience Sorting Algorithm'
// The code does not give the correct result, but understand the concept.
// Algorithm Link: https://leetcode.com/problems/longest-increasing-subsequence/discuss/74824/JavaPython-Binary-search-O(nlogn)-time-with-explanation

#include<bits/stdc++.h>
using namespace std;


int callBinarySearch(int arr[], int l, int r, int x, int dp[]){
  while(l<=r){
    int m = l + (r-l)/2;

    if(dp[m]==x) return m;
    else if(dp[m]<x) l = m+1;
    else if(dp[m]>x) r=m-1;
  }
  return l; // returning l will align with the 'Patience Sorting Algorithm'.
}
int call(int arr[], int n, int dp[]){

  for(int i=0;i<n;i++){
    int p = callBinarySearch(arr,0,i,arr[i],dp);
    dp[p] = arr[i];
  }

}
int main(){
  int dp[6];
  memset(dp,1000,6);
  int arr[6]={50,3,10,7,40,80};
  call(arr,6,dp);
  int c = 0;
  for(int i=0;i<6;i++){
    if(dp[i]!= 1000){
      c++;
    }
  }
  cout << "The number of increasing subsequences are: " << c << endl;
  cout << "The subsequent numbers are: " <<  endl;
  for(int i=0;i<6;i++){
    cout << dp[i] << endl;
  }
  return 0;
}
