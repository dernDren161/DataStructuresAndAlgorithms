// Problem Link: https://leetcode.com/explore/interview/card/facebook/54/sorting-and-searching-3/279

class Solution {
    /*
    [3,1]
    1
    */

    int call(vector<int>&nums, int target, int l, int r){


        // Always think about making these three points, i.e l, target and r in an ascending order.
        // Very mistakable question.

        while(l<=r){
            int m = l+(r-l)/2;

            if(nums[m] == target) return m;

            if(nums[l]<=nums[m]){
                if(target>=nums[l] && target<=nums[m]) r = m-1;
                else l = m+1;
            }else{
                if(target<=nums[r] && target>=nums[m]) l = m+1;
                else r = m-1;
            }
        }

        return -1;

    }
public:
    int search(vector<int>& nums, int target) {

        /*
        Input: nums = [4,5,6,7,0,1,2], target = 0
        Output: 4
        */
        if(nums.size() == 0) return -1;

        return call(nums,target,0,nums.size()-1);
    }
};
