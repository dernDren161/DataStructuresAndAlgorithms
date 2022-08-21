// Problem Link: https://practice.geeksforgeeks.org/batch-problems/longest-subarray-with-absolute-difference-between-largest-and-smallest-element-is-not-greater-than-k/0/?track=gts-two-pointers&batchId=397

class Solution
{
   public:
    int LongestSubarray(vector<int>arr, int n, int k)
    {
        map<int,int>myMap;

        int i; int j; i = 0; j = 0;
        int ans = INT_MIN;

        while(j<n){
            myMap[arr[j]]++;

            int diff = (myMap.rbegin()->first)-(myMap.begin()->first);

            if(diff<=k){
                ans = max(ans,j-i+1);
                j++;
            }else if(diff>k){
                while((myMap.rbegin()->first - (myMap.begin()->first))>k){
                    myMap[arr[i]]--;
                    if(myMap[arr[i]]==0){
                        myMap.erase(arr[i]);
                    }
                    i++;
                }
                if(myMap.rbegin()->first-(myMap.begin()->first)<=k){
                    ans = max(ans,j-i+1);
                }
                j++;
            }
        }

        return ans;
    }
};
