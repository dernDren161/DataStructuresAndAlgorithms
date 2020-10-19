public class Solution {
    public int findDuplicate(int[] nums) {
        if (nums == null || nums.length <= 1) {
            return -1;
        }

    int slow = 0;
    int fast = 0;
    int finder = 0;

    while (true)
    {
        slow = nums[slow];
        fast = nums[nums[fast]];

        if (slow == fast)
            break;
    }
    while (true)
    {
        slow = nums[slow];
        finder = nums[finder];
        if (slow == finder)
            return slow;
    }
    }
}
