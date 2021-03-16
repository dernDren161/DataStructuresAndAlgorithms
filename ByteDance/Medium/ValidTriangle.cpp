// Problem Link: https://leetcode.com/problems/valid-triangle-number/submissions/

class Solution {
public:
    int triangleNumber(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        int c = 0;

        for(int i=nums.size()-1;i>=2;i--){
            int j = 0;
            int k = i-1;

            while(j<k){
                if(nums[i]<nums[j]+nums[k]){
                    c += (k-j);
                    k--;
                }else{
                    j++;
                }
            }
        }

        return c;
    }
};
