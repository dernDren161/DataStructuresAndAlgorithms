// Problem Link: https://leetcode.com/problems/first-missing-positive/
// T.C: O(n)
// S.C: O(1)

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        int n = nums.size();

        int res = n+1; /*
        NOTE: This is for the case of 1,2,3,4
        where all the numbers will eventually be negative so we have to return n+1 or 5
        only for this case it does not even work for 2,3,4,5
        */

        for(int i=0;i<n;i++){
            if(nums[i]<=0) nums[i] = INT_MAX;
        }

        for(int i=0;i<n;i++){

            if(abs(nums[i])-1<n){ // abs as the number is made negative but we have to take the positive index
                if(nums[abs(nums[i])-1] > 0)  // NOTE: For the case of [1,1] or for the case to avoid the computation of the already 'negative converted' elements
                       nums[abs(nums[i])-1] = -1 * nums[abs(nums[i])-1];
            }
        }

        for(int i=0;i<n;i++){
            if(nums[i]<0) continue;
            else{
                res = i+1;
                break; // NOTE: This break statement is very important.
            }
        }

        return res;
    }
};
