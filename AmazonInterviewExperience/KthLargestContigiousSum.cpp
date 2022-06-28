// Problem Link: https://www.geeksforgeeks.org/k-th-largest-sum-contiguous-subarray/

// T.C: O(n^2 * logk), where k is the size of the priority queue
// S.C: O(k)

int kthLargestSum(int arr[], int n, int k){

  // sum[i] gives the total sum till the ith index in the array
  int sum[n];

  /*
  NOTE: Uninitialized arrays in C++ are given zero value
  */
  // At one point the code becomes sum[i-1] i.e sum[-1]
  sum[-1] = 0; // NOTE: Though this is not required as it is by default set to zero

  sum[0] = arr[0];
  sum[1] = sum[0] + arr[1];

  for(int i=2;i<n-1;i++){
    sum[i] = sum[i-1] + arr[i];
  }

  priority_queue<int,vector<int>,greater<int>> pq;

  for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
      // sum from i to j can be given by:
      int x = sum[j] - sum[i-1];

      if(pq.size()<k){
        pq.push(x);
      }else{
        if(x>pq.top()){
          pq.pop();
          pq.push(x);
        }
      }
    }
  }

  return pq.top();

}
