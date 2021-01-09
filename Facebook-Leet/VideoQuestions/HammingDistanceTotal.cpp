// Problem Link: https://leetcode.com/problems/total-hamming-distance/

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {

        //010
        //100

        if(nums.size()==0) return 0;

        int res = 0;


        // The time complexity here is: O(31*n) or just O(n)

        for(int i=0;i<=31;i++){
            int c = 0;
            for(int j=0;j<nums.size();j++){

                if((1<<i)&nums[j]) c++; // means it is set.
            }
            res += (c)*(nums.size()-c); // set values * non set values.
        }

        return res;
    }
};
