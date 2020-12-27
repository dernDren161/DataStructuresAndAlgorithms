// Problem Link: https://leetcode.com/explore/interview/card/facebook/53/recursion-3/292


// if the given string vector was: [1,2,3]
// then the number of permutations are: (vs.size())! or n!
// since from the formula of the number of permutations is: n!/(n-r)!


// important, in this question we get "DISTINCT" elements in the input stream.

class Solution {
public:
    vector<vector<int>> res;

    void call(vector<int> & nums, vector<int>& ans){

        if(ans.size() == nums.size()) {
            res.push_back(ans);
            return;
        }
        int x = nums.size();
        for(int i=0;i<x;i++){

            if(find(ans.begin(),ans.end(),nums[i]) == ans.end()){ // when the element is not found, hence execute this block
                ans.push_back(nums[i]);
                call(nums,ans);

                // Backtracking, with this step.
                ans.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        /*
        Input: nums = [1,2,3]
        Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
        */

        if(nums.size() == 0) return {};

        vector<int> ans;

        call(nums,ans);

        return res;
    }
};
