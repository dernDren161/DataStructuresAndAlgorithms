// Problem Link: https://leetcode.com/problems/rotate-array/submissions/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        /*
        Input: nums = [1,2,3,4,5,6,7], k = 3
        Output: [5,6,7,1,2,3,4]
        */

        int n = nums.size();
        int x = 0;
        int i = 0;
        int stop = -1;

        while(x<n){
            int next = (i+k)%n;
            int temp = nums[i];

            while(next != stop){
                if(stop == -1){
                    stop = (i+k)%n;
                }

                int storing = nums[next];
                nums[next] = temp;
                temp = storing;
                x++;
                next = (next+k)%n;
            }
            // if x == n-1 by now, then perfectly fine,
            // but if not we have to restart the same process again, with new position
            // the new positions of 'next' and 'start' are now just one step forward of their previous              ones

            i++;
            stop = -1;
        }
    }
};
