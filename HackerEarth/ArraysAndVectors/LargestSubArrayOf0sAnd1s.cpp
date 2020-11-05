 // A function Code.
// Problem Link: https://practice.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1/?track=md-arrays&batchId=144
int maxLen(int arr[], int n) {
   for(int i=0;i<n;i++){
       arr[i] = (arr[i]==0)?-1:1;
   }
   int sum = 0;
   int l= 0;
   map<int,int> um;
   for(int i=0;i<n;i++){
       sum+=arr[i];
       if(sum==0){
           l = i+1;
       }
       if(um.find(sum)!=um.end()){// means 'found'
           l = max(l,i-um[sum]);
       }
       else{
           um[sum]=i;
       }
   }
   return l;
}
