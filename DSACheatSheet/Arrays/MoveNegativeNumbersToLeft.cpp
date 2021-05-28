// This question preserves the order of the elements
// Hence time taken : O(nlogn)
// Space taken: O(logn)

// Problem Link: https://www.geeksforgeeks.org/rearrange-positive-and-negative-numbers/

#include<bits/stdc++.h>
using namespace std;


void mergeAll(int arr[], int l, int m, int r){

  int i=l;
  int j = m+1;

  // Find the positive elements
  while(i<=m && arr[i]<0)i++;

  while(j<=r && arr[j]<0)j++;

  reverse(arr+i,arr+(m+1));  // from i to m

  reverse(arr+(m+1),arr+j); // from m+1 to j-1

  reverse(arr+i,arr+j); // from i to j-1

}
void RearrangePosNeg(int arr[], int l, int r){
  // atleast i need two elements at last

  if(l<r){
    int m = l+(r-l)/2;

    RearrangePosNeg(arr,l,m);
    RearrangePosNeg(arr,m+1,r);

    mergeAll(arr,l,m,r);
  }
}
int main()
{
    int arr[] = { -12, 11, -13, -5, 6, -7, 5, -3, -6 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    RearrangePosNeg(arr, 0, arr_size - 1);

    printArray(arr, arr_size);

    return 0;
}
