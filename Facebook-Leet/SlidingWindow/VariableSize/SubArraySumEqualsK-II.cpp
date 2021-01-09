#include<bits/stdc++.h>
// map ----> (sum,ending index)
class Solution{
  public:
    int subarraySum(vector<int,int>& nums, int k){

      int n = nums.size();
      map<int,int> m;
      int s = 0;
      int res = 0;
      m[0] = -1;
      int len = 0;
      int endingIndex = 0;

      for(int i=0;i<n;i++){
        s += nums[i];

        auto p = m.find(s-k);

        if(p == m.end()){ // not found
          m[s] = i;
        }

        if(p != m.end()){
          if((i-m[s-k]+1) > len) len = i-m[s-k]+1;
          endingIndex = i;
        }
      }

      cout << "The longest length is " << len <<  endl;

      cout << "The starting and ending indices are: "<< endl;
      cout << "Starting index: "<< endingIndex-len+1 << endl;
      cout << "Ending index: "<< endingIndex << endl;
    }
}
