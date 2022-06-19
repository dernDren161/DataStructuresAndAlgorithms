// Problem Link: https://leetcode.com/problems/russian-doll-envelopes/

// NOTE: SCROLL down there is one more solution

class Solution {
public:

    static bool comp(vector<int>&a, vector<int>&b){

        if(a[0]==b[0]){
            return a[1]>b[1];
        }

        return a[0]<b[0]; // sorting in ascending order for width
    }

    int maxEnvelopes(vector<vector<int>>& env) {

        int n = env.size();

        vector<int>dp; // stores just the height parameter

        sort(env.begin(),env.end(),comp); // sort w.r.t the width and reverse sort for height

        for(int i=0;i<env.size();i++){

            auto it = lower_bound(dp.begin(),dp.end(),env[i][1])-dp.begin();

            if(it>=dp.size()){
                dp.push_back(env[i][1]);
            }else{
                dp[it] = env[i][1];
            }
        }

        return dp.size();
    }
};

-------------------------------------------------------------------------------------------------------------------------------

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        if(nums.size()==1) return 1;
        int n = nums.size();
        vector<int>dp;


        for(int i=0;i<n;i++){

            auto it = lower_bound(dp.begin(),dp.end(),nums[i])-dp.begin();

            if(it >= dp.size()){
                dp.push_back(nums[i]);
            }else{
                dp[it] = nums[i];
            }
        }

        return dp.size();
    }
};
