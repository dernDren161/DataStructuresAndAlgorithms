class Solution {
public:

    int count;

    bool call(vector<int>&nums, int target, int n, int sum, int x,vector<bool>&vis, int k){

        if(k==1) return true;

        if(sum==target){
            return call(nums,target,n,0,0,vis,k-1);
        }
        if(sum>target) return false;
        if(x>=nums.size()) return false;

        for(int i=x;i<n;i++){
            if(!vis[i]){
               // if(sum+nums[i]<=target){
                vis[i] = true;
                if(call(nums,target,n,sum+nums[i],i+1,vis,k)) return true;
                vis[i] = false;//}
            }
        }

        return false;

    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {

        int n = nums.size();
        int sum = 0;
        for(int x:nums)sum+=x;

        if(sum%k!=0) return false;

        vector<bool> vis(n,false);
        count = 0;
        return call(nums,sum/k,n,0,0,vis,k);
    }
};
