// Problem Link: https://leetcode.com/explore/interview/card/facebook/53/recursion-3/278

// Important hint here is: NOTE: when an element is popped in a vector, the last pointer comes and sits at that position, irrespective of its' current position whatsoever

class Solution {

    vector<int> temp;
    vector<vector<int>> res;



    void call(vector<int>& nums, int l, int r){

        if(l == r){
            res.push_back(temp);
            return;
        }

        temp.push_back(nums[l]);

        call(nums,l+1,r);
        //backtracking
        temp.pop_back();
        call(nums,l+1,r);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        /*
        Input: nums = [1,2,3]
        Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
        */

        if(nums.size() == 0) return {};


        call(nums,0,nums.size());

        return res;
    }
};
