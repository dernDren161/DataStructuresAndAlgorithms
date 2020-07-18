
// Problem Link: https://practice.geeksforgeeks.org/problems/count-number-of-hops-1587115620/1/?track=amazon-dynamic-programming&batchId=192


long long countWays(int n){

   long long* arr = new long long[n+3];

   //long long arr[n+1];
   arr[0] = 1;
   arr[1] = 1;
   arr[2] = 2;

   for(long long i=3;i<=n;i++){
       arr[i] = (arr[i-1] + arr[i-2] + arr[i-3]) % 1000000007;
   }

   return arr[n];
}
