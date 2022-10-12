// Problem Link: https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/646/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        /*
        Input: nums = [1,2,3,4,5,6,7], k = 3
        Output: [5,6,7,1,2,3,4]
        */

        k = k % (nums.size());
        int fIndex;
        int fValue;

        int sIndex; 
        int sValue;

        int c = 0;

        for(int i=0;c<nums.size();i++){
            fIndex = i;
            fValue = nums[i];

            do{
                sIndex = (fIndex+k) % nums.size();
                sValue = nums[sIndex];
                nums[sIndex] = fValue;
                fValue = sValue;
                fIndex = sIndex;
                c++;
            }while(i!=fIndex);
        }
    }
};
