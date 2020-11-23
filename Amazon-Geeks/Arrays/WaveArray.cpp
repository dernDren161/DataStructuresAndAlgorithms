// Problem Link:
// https://practice.geeksforgeeks.org/problems/wave-array-1587115621/1/?track=amazon-arrays&batchId=192

void convertToWave(int *arr, int n){

   for(int i=0;i<n-1;i+=2){
       swap(arr[i],arr[i+1]);
   }
}
