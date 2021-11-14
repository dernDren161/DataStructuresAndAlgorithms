// Problem Link: https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int i = 0;
        int j = 0;
        int len = INT_MAX;
        int n = nums.size();
        int s = 0;

        while(j<n){
            s += nums[j];

            while(s>=target){
                len = min(len,j-i+1);
                s -= nums[i];
                i++;
            }
            j++;
        }

        if(len==INT_MAX) return 0;

        return len;
    }
};
