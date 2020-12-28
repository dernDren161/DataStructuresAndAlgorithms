//Problem Link: https://leetcode.com/explore/interview/card/facebook/54/sorting-and-searching-3/3032

// NOTE: these edge cases like: (m==0), (m>0)(line 16), etc are very Important, never forget to write them down.
class Solution {

    int call(vector<int>& nums, int l, int r, int n){

        if(nums.size() == 0) return -1;

        while(l<=r){

            int m = l + (r-l)/2;

            if((m==0 || nums[m]>=nums[m-1]) && (m==n-1 || nums[m]>=nums[m+1])){
                return m;
            }else if(m>0 && nums[m]<=nums[m-1]){ // means though nums[m]>=nums[m-1], the other statement is false, i.e     nums[m]>=nums[m+1] is false
                 r = m-1;
            }else l = m+1;

        }

        return -1;
    }
public:
    int findPeakElement(vector<int>& nums) {

        /*
        Input: nums = [1,2,1,3,5,6,4]
        Output: 5
        */

        if(nums.size() == 0) return -1;

        int n = nums.size();
        return call(nums,0,n-1,n);
    }
};
