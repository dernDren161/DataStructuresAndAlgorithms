// Problem Link: https://www.geeksforgeeks.org/count-pairs-in-array-whose-sum-is-divisible-by-k/

int countKDivPairs(int arr[], int n, int k){

  int sum = 0;

  int freq[k] = {0};

  for(int i=0;i<n;i++){
    freq[arr[i]%k]++;
  }

  // combination of all the numbers when they are perfectly divisible by k
  sum = freq[0]*(freq[0]-1)/2;

  // is divisible if mod of one no is x and the other one is (k-x)
  for(int i=1;i<k/2 && i!= k-i;i++){
    sum += freq[i] * freq[k-i];
  }

  // if k itself is divided by 2
  if(k%2==0){
    sum += freq[k/2]*(freq[k/2]-1)/2;
  }

  return sum;

}
