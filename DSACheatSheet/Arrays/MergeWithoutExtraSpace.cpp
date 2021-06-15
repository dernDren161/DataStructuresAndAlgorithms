// Problem Link: https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1#

// Time complexity: O((n+m)*log(m+n))
// Space complexity: O(1)

class Solution{
public:
	void merge(int arr1[], int arr2[], int n, int m) {
	    // code here
	    int i = 0; // for arr1
	    int j = 0; // for arr2
	    int k = n-1; // for arr1

	    while(i<=k && j<m){
	        if(arr1[i]<arr2[j])i++;
	        else{  // NOTE: This condition also works for the arr1[i]==arr2[j]
	            swap(arr2[j],arr1[k]);
	            j++;
	            k--;
	        }
	    }

	    sort(arr1,arr1+n);
	    sort(arr2,arr2+m);

	    // Time complexity of the algo is: O((n+m)log(n+m))
	}
};
