
int call(int arr[], int i, int j){

  if(i>=j) return 0; // not valid even if i and j are equal they necessarily have to be i < j;

  int m = INT_MAX;

  for(int k=i; k<j;k++){

    // ex: 10,20,30 ->>>>> the matrices are m1(of size: 10X20) and m2(20X30)
    // the total number of multiplications done for multiplying m1 and m2 are: 10*20*30 = 6000
    // 10 * 20 * 30 means, 20 is at position (i), 10 is at position (i-1) and 30 is at position(j). So, the total multiplicative variable is:
    // a[i-1] * a[k] * a[j]

    int temp = call(arr,i,k) + call(arr,k+1,j) + a[i-1] * a[k] * a[j];

    if(temp<m) m = temp;

  }

  return m;
}
