// Problem Link: https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slow = nums[0];
        int fast = nums[0];

        if(nums.size()==0) return 0;

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        // slow = fast
        slow = nums[0];

        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
