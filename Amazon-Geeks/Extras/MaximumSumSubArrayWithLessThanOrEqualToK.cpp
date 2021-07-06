// Problem Link: https://www.geeksforgeeks.org/maximum-sum-subarray-having-sum-less-than-or-equal-to-given-sum-using-set/

// Given an array, arr and an integer k, find the highest sum in the array with less than or equal to the value of k
// i.e sumSubArray <= k

int maxSubArraySum(int arr[], int n, int k){

  set<int> s;
  s.insert(0);

  int cSum = 0;
  int maxSum = INT_MIN;

  // NOTE: A variation of the Kadane's Algorithm
  for(int i=0;i<n;i++){
    cSum += arr[i];

    auto p = s.lower_bound(cSum-k);

    if(p != s.end()){ // If found
      maxSum = max(maxSum,cSum- *p);
    }

    s.insert(cSum);
  }

  return maxSum;
}
