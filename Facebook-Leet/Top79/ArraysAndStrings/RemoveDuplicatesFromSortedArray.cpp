// Problem Link: https://leetcode.com/explore/interview/card/facebook/5/array-and-strings/3011/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int s = nums.size();
        int x = 0;
        if(s==0) return 0;
        for(int i=0;i<s-1;i++){
            if(nums[i] != nums[i+1]){
                nums[x] = nums[i];
                x++;
            }
        }
        nums[x] = nums[s-1];
        return x+1;
    }
};
