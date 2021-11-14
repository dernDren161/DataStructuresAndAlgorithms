// Problem Link: https://leetcode.com/explore/interview/card/top-interview-questions-easy/96/sorting-and-searching/587/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /*
        Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
        Output: [1,2,2,3,5,6]
        */

        int k = m+n-1;  // NOTE: Important point

        int i,j;

        i = m-1; j = n-1;

        while(i>=0 && j>=0){
            if(nums1[i]>=nums2[j]){
                nums1[k] = nums1[i];
                k--;
                i--;
            }else{
                nums1[k] = nums2[j];
                k--;
                j--;
            }
        }

        while(i>=0){
            nums1[k] = nums1[i];
            i--;
            k--;
        }

        while(j>=0){
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }
};
