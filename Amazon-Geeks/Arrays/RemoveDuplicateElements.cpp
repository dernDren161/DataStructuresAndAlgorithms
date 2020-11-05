// Functioanl Program

// Problem Link: https://practice.geeksforgeeks.org/problems/remove-duplicates-in-small-prime-array/1/?track=amazon-arrays&batchId=192

vector<int> removeDuplicate(vector<int>& arr, int n)
{
   int d[1000] = {0};
   vector<int> vs;
   for(int i=0;i<n;i++){
       if(d[arr[i]] == 0){
           d[arr[i]] = 1;
           vs.push_back(arr[i]);
       }
   }
    
    return vs;
}
