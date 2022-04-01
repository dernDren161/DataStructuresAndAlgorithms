// Problem Link: https://leetcode.com/explore/interview/card/google/59/array-and-strings/3055/

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {

        int n = nums.size();
        vector<string> res;

        for(int i=0;i<n;i++){
            if(nums[i]-lower==0){
                lower++;
                continue;
            }else if(nums[i]-lower == 1){
                res.push_back(to_string(lower));
                lower = nums[i]+1;
            }else{
                res.push_back(to_string(lower)+"->"+to_string(nums[i]-1));
                lower = nums[i] + 1;
            }
        }

        if(upper-lower==0){
            res.push_back(to_string(lower));
        }else if(upper-lower > 0){
            res.push_back(to_string(lower)+"->"+to_string(upper));
        }

        return res;
    }
};
