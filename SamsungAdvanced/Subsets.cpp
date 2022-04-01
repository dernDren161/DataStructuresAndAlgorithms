// Finding the different subsets using bitwise manipulation

void subs(vector<int>&nums, int n){
  // find subsets

  for(int i=0;i<(1<<n);i++){
    for(int j=0;j<n;j++){
      if(i&(1<<j)){
        cout << nums[j] << " ";
      }
    }
    cout << endl;
  }
}
