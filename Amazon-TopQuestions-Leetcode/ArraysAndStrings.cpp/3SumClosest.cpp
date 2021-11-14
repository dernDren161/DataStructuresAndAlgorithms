// Problem Link: https://leetcode.com/explore/interview/card/amazon/76/array-and-strings/2967/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int n = nums.size();
        int sum;
        int temp=INT_MAX;
        int result=0;

        sort(nums.begin(),nums.end());

        int j;
        int k;

        // 1, 1, 1, 0
        // 0, 1 ,1 ,1
        for(int i=0;i<n-2;i++){
            if(i==0 || nums[i]!=nums[i-1]){ // NOTE: VVIMP
                j = i+1;
                k = n-1;           // NOTE: VVIMP

                while(j<k){
                    sum = nums[i]+nums[j]+nums[k];

                    if(sum==target) return target;

                    if(abs(target-sum)<temp){
                        temp = abs(target-sum);
                        result = sum;
                    }
                    if(sum<target)j++;
                    else if(sum>target)k--;
                }
            }
        }

        return result;
    }
};
