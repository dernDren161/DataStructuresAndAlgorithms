// NOTE: after addition or subtraction the resultant array element cannot be negative

// Case for positive

// Problem Link: https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1#

int getMinDiff(int arr[], int n, int k){

  sort(arr,arr+n);

  int res = arr[n-1]-arr[0];

  int mini, maxi;

  for(int i=1;i<n;i++){
     if(arr[i]>=k){ // This makes sure that after computation the element is still positive
      mini = min(arr[0]+k,arr[i]-k);
      maxi = max(arr[n-1]-k,arr[i-1]+k);

      res = min(res,maxi-mini);
    } else continue;
  }

  return res;
}
