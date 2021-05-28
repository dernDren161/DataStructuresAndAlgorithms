// NOTE: after addition or subtraction the resultant array element may be negative

// Case for negative

// Problem Link: https://practice.geeksforgeeks.org/problems/minimize-the-heights-i/1/#

int getMinDiff(int arr[], int n, int k){

  sort(arr,arr+n);

  int res = arr[n-1]-arr[0];

  int mini, maxi;

  for(int i=1;i<n;i++){

      mini = min(arr[0]+k,arr[i]-k);
      maxi = max(arr[n-1]-k,arr[i-1]+k);

      res = min(res,maxi-mini);
  }
  return res;
}
