// Problem Link: same as the other one
// Here, Time Complexity: O(n)
// Auxillary space: O(1)
// decreased the space by using some mathematics.
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
        Input:  [1,2,3,4]
        Output: [24,12,8,6]
        */

        int s = nums.size();

        int summ = 0;

        for(int i=0;i<s;i++){
            summ += log10(nums[i]);
        }

        for(int i=0;i<s;i++){
            nums[i] = pow(10,summ-log10(nums[i]));
        }

        return nums;
    }
};
