// Problem Link:
//https://practice.geeksforgeeks.org/problems/number-of-occurrence2259/1

// NOTE: Just another variation of the "First and Last occurence of a digit" problem.

class Solution{
public:
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */

	int call(int arr[], int l, int r, int x){
	    int res = -1;
	    while(l<=r){
	        int m = l+(r-l)/2;
	        if(arr[m]==x){
	            res = m;
	            r = m-1;
	        }else if(arr[m]>x){
	            res = m;
	            r = m-1;
	        }else if(arr[m]<x){
	            l = m+1;
	        }
	    }
	    return res;
	}
	int count(int arr[], int n, int x) {
	    // code here
	    int i = call(arr,0,n-1,x);
	    int j; // NOTE: But what if the last element is 'x' only, then x+1 becomes out of bound;
	    if(arr[n-1]==x)j=n;
	    else j = call(arr,0,n-1,x+1);

	    return j-i;
	}
};
