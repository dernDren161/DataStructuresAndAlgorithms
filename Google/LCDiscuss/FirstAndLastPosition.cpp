// Problem Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:

    int callBS(vector<int>&nums, int target, string str){

        int l = 0; int r = nums.size()-1;

        int res = -1;

        while(l<=r){
            int m = l + (r-l)/2;

            if(nums[m]==target){
                if(str=="first"){
                    res = m;
                    r = m-1;
                }else if(str=="second"){
                    res = m;
                    l = m+1;
                }
            }else if(nums[m]>target){
                r = m-1;
            }else{
                l = m+1;
            }
        }

        // If the numbers are not found at all, then we return {-1,-1}
        return res;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        int n = nums.size();

        return {callBS(nums,target,"first"),callBS(nums,target,"second")};
    }
};
