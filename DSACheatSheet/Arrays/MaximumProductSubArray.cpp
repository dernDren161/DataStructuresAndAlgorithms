// Problem Link: https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1#

class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(int *arr, int n) {
	    // code here
	    long long localMax = (long long)arr[0];
	    long long localMin = (long long)arr[0];

	    long long maxi = (long long)arr[0];

	    for(int i=1;i<n;i++){
	        if(arr[i]>0){
	            localMax = max(localMax*(long long)arr[i],(long long)arr[i]);
	            localMin = min(localMin*(long long)arr[i],(long long)arr[i]);
	        }else{ // including if arr[i]==0
	            long long temp = localMin;
	            localMin = min(localMax*(long long)arr[i],(long long)arr[i]);
	            localMax = max(temp*(long long)arr[i],(long long)arr[i]);
	        }

	        maxi = max(maxi,localMax);
	    }

	    return maxi;

	}
};
