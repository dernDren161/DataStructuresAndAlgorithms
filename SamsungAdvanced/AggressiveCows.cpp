// Aggressive Cows
// 1,2,4,6,8,9  k = 3

bool isSafe(int arr[], int k, int m, int n){
  int p = 1;
  int leftMost = 0;

  for(int i=1;i<n;i++){
    if(arr[i]-arr[leftMost] >= m){
      leftMost = i;
      p++;
      if(p==k) return true;
    }
  }

  return false;
}
int aggressiveCows(int arr[], int k){

  int n = sizeof(arr)/sizeof(arr[0]);
  sort(arr,arr+n);
  int l = 0;
  int r = arr[n-1]-arr[0]+1;

  while(l<=r){
    int m = l + (r-l)/2;
    if(isSafe(arr,k,m,n)){
      l = m;
    }else{
      r = m-1;
    }
  }

  return l;
}
