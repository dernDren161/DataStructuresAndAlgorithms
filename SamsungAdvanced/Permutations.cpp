// Problem Link: https://leetcode.com/problems/permutations/

class Solution {
public:
    vector<vector<int>>ans;

    bool callCheck(vector<int>&temp,int x){
        for(int it:temp){
            if(it==x) return true;
        }

        return false;
    }

    void call(vector<int>&nums,int n, int x, vector<int>&temp){

        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<n;i++){
            if(callCheck(temp,nums[i])) continue;
            temp.push_back(nums[i]);
            call(nums,n,x,temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        int n = nums.size();
        vector<int>temp;

        call(nums,n,0,temp);
        return ans;
    }
};
