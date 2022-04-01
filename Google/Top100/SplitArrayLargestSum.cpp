// Problem Link: https://leetcode.com/problems/split-array-largest-sum/

class Solution {
public:

    bool isValid(int m, vector<int>&nums, int k){
        int p =1;
        int s = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>m) return false;
            s += nums[i];
            while(s>m){
                p++;
                if(p>k) return false;
                s = nums[i];
            }
        }

        if(p>k) return false;
        return true;
    }
    int splitArray(vector<int>& nums, int k) {

        int ans;
        int n = nums.size();

        int s = 0;
        int l = INT_MIN;

        for(int i=0;i<nums.size();i++){
            s+=nums[i];
            l = max(l,nums[i]);
        }

        int r = s;

        while(l<=r){
            int m = l + (r-l)/2;

            if(isValid(m,nums,k)){
                ans = m;
                r = m-1;
            }else{
                l = m +1;
            }
        }

        return ans;
    }
};
