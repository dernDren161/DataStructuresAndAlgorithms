// Problem Link: https://leetcode.com/explore/interview/card/facebook/5/array-and-strings/3019/

// Important problem, done in 'Facebook-Leet' previously
// Also same variation done under 'Amazon', but that works only with the positive integers.
// This one works with negatives as well.

// This problem counts the number of occurences of the given sum.

// VARIATION - I

// map ----> (sum,occurence count)

// NOTE: THIS is applicable for the contiguous subarray
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        /*
        Input: nums = [1,1,1], k = 2
        Output: 2
        */

        int n = nums.size();
        map<int,int>m;
        int s = 0;
        int res = 0;
        m[0] = 1;

        for(int i=0;i<n;i++){
            s += nums[i];

             auto p = m.find(s-k);

            if(p != m.end()){  // if the key is found.
                res += p->second;
            }

            m[s]++;


        }

        return res;
    }
};
