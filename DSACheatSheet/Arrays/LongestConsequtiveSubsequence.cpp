// Problem Link: https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1#

class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]

    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here

      unordered_set<int>m;

      for(int i=0;i<N;i++)m.insert(arr[i]);

      int ans = 0;

      for(int i=0;i<N;i++){

          if(m.find(arr[i]-1)==m.end()){ // arr[i] is the first element, then
              int j = arr[i];

              while(m.find(j)!=m.end())j++;

              ans = max(ans,j-arr[i]);
          }
      }

      return ans;
    }
};
