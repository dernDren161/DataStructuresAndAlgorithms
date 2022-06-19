// Problem Link: https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/

class Solution {
public:
    int minNumberOperations(vector<int>& target) {

        int n = target.size();
        int prev = 0;
        int res = 0;

        for(int i=0;i<n;i++){
            res += (target[i]-min(target[i],prev));
            prev = target[i];
        }

        return res;
    }
};
