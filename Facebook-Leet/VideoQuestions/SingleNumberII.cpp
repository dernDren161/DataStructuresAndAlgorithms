// Problem Link: https://leetcode.com/problems/single-number-ii/

// This question is similar to the 'Total Hamming Distance' wala problem
// Very intuitive algorithm ;)

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        if(nums.size()==0) return -1;

        int temp;

        int res = 0;

        for(int i=0;i<=31;i++){
            int c = 0;

            for(int j=0;j<nums.size();j++){

                if(nums[j] & (1<<i)) c++; // if it is set
            }

            temp = c % 3; // if the result is non-sero we found our element's set bit at position 'i'.

            if(temp){
              res = res | (1<<i);
            }

        }

        return res;
    }
};
