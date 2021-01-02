// Problem Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/submissions/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        if(numbers.size()==0) return {};

        int l = 0;
        int r = numbers.size() - 1;

        vector<int> res;

        while(l<=r){
            if(numbers[l] + numbers[r] == target){
                res.push_back(l+1);
                res.push_back(r+1);
                return res;
            }else if((numbers[l]+numbers[r]) < target){
                l++;
            }else r--;
        }
        return res;
    }
};
