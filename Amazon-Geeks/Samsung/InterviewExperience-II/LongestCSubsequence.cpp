// Problem Link: https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1#
// T.C: O(n)

class Solution{
  public:

    int findLongestConseqSubseq(int arr[], int n)
    {
      map<int,int>m;
      for(int i=0;i<n;i++){
          m[arr[i]]++;
      }

      int x = 1;

      for(int i=0;i<n;i++){
          if(m.find(arr[i]-1)==m.end()){
              int temp = arr[i];

              while(m.find(temp+1)!=m.end()){
                  temp++;
              }
              x = max(x,temp-arr[i]+1);
          }
      }

      return x;
    }
};
