// Problem Link: https://leetcode.com/problems/maximum-sum-circular-subarray/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int n = nums.size();
        int localMax = nums[0];
        int localMin = nums[0];
        int maxSoFar = nums[0];
        int minSoFar = nums[0];

        int s = 0;
        for(int x:nums)s+=x;

        for(int i=1;i<n;i++){
            localMax = max(localMax+nums[i],nums[i]);
            maxSoFar = max(maxSoFar,localMax);
            localMin = min(localMin+nums[i],nums[i]);
            minSoFar = min(minSoFar,localMin);
        }

        if(minSoFar==s) return maxSoFar;

        return max(maxSoFar,s-minSoFar);
    }
};
