// Problem Link: https://leetcode.com/problems/shuffle-an-array/

class Solution {
public:

    // Fisher Yates Algorithm

    vector<int>global;
    int sz;

    Solution(vector<int>& nums) {
          global = nums;
          sz = nums.size();
    }

    vector<int> reset() {
        return global;
    }

    vector<int> shuffle() {

        vector<int>temp;
        temp = global;

        int left = sz;

        for(int i=left-1;i>=0;i--){

            int index = (rand()%left);

            swap(temp[i],temp[index]);
            left--;
        }

        return temp;
    }
};
