// Problem Link: https://leetcode.com/problems/minimum-increment-to-make-array-unique/

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {

        int n = nums.size();

        int steps = 0;

        sort(nums.begin(),nums.end());

        for(int i=0;i<n-1;i++){
            if(nums[i+1] <= nums[i]){
                steps += ((nums[i]+1)-(nums[i+1]));
                nums[i+1] = nums[i] + 1;
            }
        }

        return steps;
    }
};
