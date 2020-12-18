// Problem Link: https://leetcode.com/explore/interview/card/facebook/5/array-and-strings/3012/
// Algorithm Link: http://yucoding.blogspot.com/2013/04/leetcode-question-61-next-permutation.html

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();

        int k = -1;

        for(int i = n-2; i>=0;i--){ // find nums[k] < nums[k+1]
            if(nums[i] < nums[i+1]){
                k = i;
                break;
            }
        }

        if(k == -1) {
            sort(nums.begin(),nums.end());
            return;
        }

        for(int i=n-1;i>=0;i--){
            if(nums[i]>nums[k]){
                swap(nums[i],nums[k]);
                break;
            }
        }

        reverse(nums.begin()+(k+1),nums.end());



        return;
    }
};
