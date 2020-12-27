// Problem Link: https://leetcode.com/explore/interview/card/facebook/53/recursion-3/293/

class Solution {
public:


    vector<int> ans;
    vector<vector<int>> res;

    void call(vector<int>& nums, int x, int sz){

        if(x == sz){
          res.push_back(ans);
            return;
        }

        // very very important
        // it is because of this declaration of 'map' at this position do we get the first form as is,
        // fo ex: if the input is: "ABC" then,
        // because of the following line the first element in the 2D vector is "ABC" only.

        // and also this avoids the duplication of the same combination as well.
        
        map<int,int> m;
        for(int i=x;i<sz;i++){

            ++m[nums[i]];

            if(m[nums[i]] == 1){
                swap(nums[x],nums[i]);
                ans.push_back(nums[x]);
                call(nums,x+1,sz);
                ans.pop_back();
                swap(nums[x],nums[i]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        /*
        Input: nums = [1,1,2]
        Output:
        [[1,1,2],
        [1,2,1],
        [2,1,1]]
        */

        if(nums.size() == 0) return {};

        int x = 0;
        int s = nums.size();

        call(nums,x,s);

        return res;
    }
};
