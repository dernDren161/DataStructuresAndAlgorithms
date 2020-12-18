// Problem Link: https://leetcode.com/explore/interview/card/facebook/5/array-and-strings/3016/
// Time complexity: O(n)
// Auxillary space: O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        /*
        Input:  [1,2,3,4]
        Output: [24,12,8,6]
        */

        int s = nums.size();

        vector<int> vs(s);
        vector<int> left(s);
        vector<int> right(s);

        left[0] = 1;
        right[s-1] = 1;

        for(int i=1;i<s;i++){
            left[i] = left[i-1] * nums[i-1];
        }

        for(int i=s-2;i>=0;i--){
            right[i] = right[i+1] * nums[i+1];
        }

        for(int i=0;i<s;i++){
            vs[i] = left[i] * right[i];
        }

        return vs;
    }
};
