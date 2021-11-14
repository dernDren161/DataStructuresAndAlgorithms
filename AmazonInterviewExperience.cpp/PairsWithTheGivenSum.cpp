
void pairedElements(int arr[], int sum, int n){

  int l = 0;
  int r = n-1;

  while(l<r){

    if(arr[l]+arr[r]==sum){
      cout << "The pair is: " << arr[l] << "and" << arr[r] << endl;
      l++; // NOTE: and nor l++ and r--
    }else if(arr[l]+arr[r]>sum){
      r--;
    }else l++;
  }

  return;
}
