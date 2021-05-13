#include<bits/stdc++.h>
using namespace std;


int getMedian(int arr1[], int arr2[], int n){

    if(n==0) return -1;

    if(n==1) return (arr1[0]+arr2[0])/2;

    if(n==2){
      int temp = (max(arr1[0],arr2[0])+min(arr1[1],arr2[1]))/2;
      return temp;
    }

    int m1 = medianOf(arr1,n);
    int m2 = medianOf(arr2,n);

    if(m1==m2) return m1; // NOTE: Important Base case

    if(m2>m1){ // exists from 0 to m2 and m1 to n-1
      if(n%2==0){ // if even
        getMedian(arr1+n/2-1,arr2,n-n/2+1);
      }else{ // if odd
        getMedian(arr1+n/2,arr2,n-n/2);
      }
    }else if(m1>m2){
      if(n%2==0){
        getMedian(arr2+n/2-1,arr1,n-n/2+1);
      }else{
        getMedian(arr2+n/2,arr1,n-n/2);
      }
    }
}

int medianOf(int arr[], int n){

  int temp;
  if(n%2==0){
    temp = (arr[n/2]+arr[n/2 - 1])/2; return temp;
  }else{
    temp = arr[n/2]; return temp;
  }
}

int main()
{
	int ar1[] = {1, 2, 3, 6};
	int ar2[] = {4, 6, 8, 10};
	int n1 = sizeof(ar1)/sizeof(ar1[0]);
	int n2 = sizeof(ar2)/sizeof(ar2[0]);
	if (n1 == n2)
		printf("Median is %d", getMedian(ar1, ar2, n1));
	else
		printf("Doesn't work for arrays of unequal size");
	return 0;
}
