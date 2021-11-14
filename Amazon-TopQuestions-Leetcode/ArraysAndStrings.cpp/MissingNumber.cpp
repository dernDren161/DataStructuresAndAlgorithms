// Problem Link: https://leetcode.com/explore/interview/card/amazon/76/array-and-strings/2971/

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int sum = 0;

        for(int x:nums) sum += x;

        int n = nums.size();

        int compare = n*(n+1)/2;

        return compare-sum;
    }
};
