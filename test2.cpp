class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> power_set;
        vector<int> set;
        power_set_gen(power_set, set, 0, nums);
        power_set.push_back(set);
        return power_set;
    }
private:
    void power_set_gen(vector<vector<int>>& power_set, vector<int> set, int index, vector<int> nums) {
        if (index == nums.size()) return;

        set.push_back(nums[index]);
        power_set.push_back(set);
        power_set_gen(power_set, set, index + 1, nums);
        set.pop_back();
        power_set_gen(power_set, set, index + 1, nums);
    }
};
