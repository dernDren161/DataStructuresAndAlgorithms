// Agressive cows
int arr[n];
int k;

bool isSafe(int m, int arr[], int k){

    int leftMost = 0;
    int p = 1;

    for(int i=1;i<n;i++){
      if(arr[i]-arr[leftMost] >= m){
        p++;
        leftMost = i;
        if(p==k) return true;
      }
    }

    return false;
}

int main(){
  sort(arr,arr+n);
  int m = arr[n-1] - arr[0] +1;

  int l = 0; int r = arr[n-1];

  while(l<=r){
    int m = l + (r-l)/2;

    if(isSafe(m,arr)){
      l = m;
    }else{
      r  = m-1;
    }
  }

  return l;
}
